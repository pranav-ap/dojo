import os
import json
import dspy
from typing import Literal


def load_examples(path: str, limit: int | None = None) -> list[dspy.Example]:
    examples = []
    with open(path) as f:
        for line in f:
            row = json.loads(line)
            examples.append(
                dspy.Example(
                    location=row["location"],
                    season=row["season"],
                    mood=row["mood"],
                ).with_inputs("location", "season", "mood")
            )
    if limit is not None:
        examples = examples[:limit]
    return examples


def haiku_metric(example, prediction, trace=None, pred_name=None, pred_trace=None):
    """GEPA-compatible metric: returns score + feedback."""
    text = prediction.haiku.lower()
    if example.season.strip().lower() in text:
        return dspy.Prediction(
            score=0.0,
            feedback="Don't reference the input season verbatim. Use imagery to evoke the season instead."
        )
    return dspy.Prediction(score=1.0, feedback=None)


Season = Literal["spring", "summer", "autumn", "winter"]


class HaikuBot(dspy.Signature):
    """Write a classical haiku given the provided inputs."""
    location: str = dspy.InputField()
    mood: str = dspy.InputField()
    season: Season = dspy.InputField()
    haiku: str = dspy.OutputField()


def setup_lm():
    lm = dspy.LM(
        model="openai/qwen3.5:4b",
        api_base="http://localhost:11434/v1",
        api_key=os.environ["OLLAMA_API_KEY"],
        reasoning_effort="none",
    )
    dspy.configure(lm=lm)


def hello_optimize():
    """Baseline evaluation: run on test set, get pre-optimization score."""
    setup_lm()

    examples = load_examples("/home/pranav/dojo/nlp/src/nlp/haiku_examples.jsonl", limit=30)

    n = len(examples)
    train_end = int(n * 0.5)
    val_end = int(n * 0.75)  # fixed: must be greater than train_end
    train, val, test = examples[:train_end], examples[train_end:val_end], examples[val_end:]

    haiku_bot = dspy.Predict(HaikuBot)

    evaluator = dspy.Evaluate(
        devset=test,
        metric=haiku_metric,
        num_threads=4,
        display_progress=True,
        provide_traceback=True,
    )
    result = evaluator(haiku_bot)
    print(f"Baseline test score: {result.score}")
    return haiku_bot, train, val, test


def hello_optimize2():
    """GEPA optimization: compile on train+val, then evaluate on test."""
    setup_lm()

    reflection_lm = dspy.LM(
        model="openai/qwen3.5:4b",
        api_base="http://localhost:11434/v1",
        api_key=os.environ["OLLAMA_API_KEY"],
        reasoning_effort="none",
    )

    examples = load_examples("/home/pranav/dojo/nlp/src/nlp/haiku_examples.jsonl", limit=30)
    n = len(examples)
    train_end = int(n * 0.5)
    val_end = int(n * 0.75)  # fixed
    train, val, test = examples[:train_end], examples[train_end:val_end], examples[val_end:]

    haiku_bot = dspy.Predict(HaikuBot)

    optimizer = dspy.GEPA(
        metric=haiku_metric,
        reflection_lm=reflection_lm,
        auto="light",
    )

    optimized_haiku_bot = optimizer.compile(haiku_bot, trainset=train, valset=val)
    optimized_haiku_bot.save("/home/pranav/dojo/nlp/src/nlp/haiku_optimized.json")

    # Post-optimization evaluation: use the untouched test set
    evaluator = dspy.Evaluate(
        devset=test,
        metric=haiku_metric,
        num_threads=4,
        display_progress=True,
        provide_traceback=True,
    )
    result = evaluator(optimized_haiku_bot)
    print(f"Optimized test score: {result.score}")


def load_and_test():
    setup_lm()

    loaded_bot = dspy.Predict(HaikuBot)
    loaded_bot.load("/home/pranav/dojo/nlp/src/nlp/haiku_optimized.json")

    result = loaded_bot(location="a quiet library", mood="mysterious", season="winter")
    print(result.haiku)


def main():
    hello_optimize()       # baseline
    hello_optimize2()      # optimize + final eval


if __name__ == "__main__":
    main()
