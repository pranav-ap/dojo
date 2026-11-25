from openai import OpenAI

import os
import dspy


def hello():
    client = OpenAI(
        base_url="http://localhost:11434/v1",
        api_key=os.environ["OLLAMA_API_KEY"],
    )

    completion = client.chat.completions.create(
        model="qwen3.5:4b",
        messages=[{"role": "user", "content": "Hello!"}],
        reasoning_effort="none",
    )

    print(completion.choices[0].message.content)



def hello2():
    # Configure DSPy to use local Ollama
    lm = dspy.LM(
        model="ollama/qwen3.5:4b",
        api_base="http://localhost:11434/v1",
        api_key=os.environ["OLLAMA_API_KEY"],
    )

    dspy.configure(lm=lm)

    """
    “Given the fields subject, produce the fields haiku.”
    """
    predict = dspy.Predict("subject -> haiku")

    # Caching is enabled by default
    result = predict(subject="France")
    print(result.haiku)

    # returns the chat messages
    print(dspy.inspect_history(n=1))


def hello3():
    # Configure DSPy to use local Ollama
    lm = dspy.LM(
        model="ollama/qwen3.5:4b",
        api_base="http://localhost:11434/v1",
        api_key=os.environ["OLLAMA_API_KEY"],
        reasoning_effort="none",
    )

    dspy.configure(lm=lm)

    from typing import Literal

    Season = Literal[
        "spring", "summer", "autumn", "winter",
    ]

    class HaikuBot(dspy.Signature):
        """
        Write a classical haiku given the provided inputs.
        """
        location: str = dspy.InputField()
        mood: str = dspy.InputField()
        season: Season = dspy.InputField()
        haiku: str = dspy.OutputField()

    haiku_bot = dspy.Predict(HaikuBot)
    result = haiku_bot(location="Bodega Bay", mood="mysterious", season="autumn")
    print(result.haiku)

    print(dspy.inspect_history(n=1))

def hello4():
    # Configure DSPy to use local Ollama
    lm = dspy.LM(
        model="ollama/qwen3.5:4b",
        api_base="http://localhost:11434/v1",
        api_key=os.environ["OLLAMA_API_KEY"],
        reasoning_effort="none",
        # max_tokens=512,
    )

    dspy.configure(lm=lm)

    from typing import Literal

    Season = Literal[
        "spring", "summer", "autumn", "winter",
    ]

    class HaikuBot(dspy.Signature):
        """
        Write a classical haiku given the provided inputs.
        """
        location: str = dspy.InputField()
        mood: str = dspy.InputField()
        season: Season = dspy.InputField()
        haiku: str = dspy.OutputField()

    haiku_bot = dspy.ChainOfThought(HaikuBot)
    result = haiku_bot(location="Bodega Bay", mood="mysterious", season="autumn")
    print(result.haiku)

    print(dspy.inspect_history(n=1))


def main():
    hello4()


if __name__ == "__main__":
    main()
