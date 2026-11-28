from openai import OpenAI

import os
import dspy


""""
ReAct
"""

import wikipedia

def wikipedia_search(query: str) -> list[str]:
    """Search Wikipedia for the given query and return a list of page titles."""
    return wikipedia.search(query)


def get_wikipedia_page(title: str) -> str:
    """Get the content of a Wikipedia page given its title."""
    return wikipedia.page(title).content

def hello5():
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

    haiku_bot = dspy.ReAct(HaikuBot, tools=[wikipedia_search, get_wikipedia_page])
    result = haiku_bot(location="Camp Meeker", mood="pensive", season="summer")
    print(result.haiku)

    print(dspy.inspect_history(n=1))

"""
Module
"""

class HaikuEnsemble(dspy.Module):
    def __init__(self, n: int = 3):
        super().__init__()

        self.n = n

        # Module 1 generates several haikus
        self.writer = dspy.ReAct(
            "location, season, mood, num_haikus: int -> haikus: list[str]",
            tools=[wikipedia_search, get_wikipedia_page],
            max_iters=5
        )

        # Module 2 picks the most evocative
        self.judge = dspy.ChainOfThought(
            "location, season, mood, candidates: list[str] -> most_evocative_index: int"
        )

    def forward(self, location: str, season: str, mood: str) -> dspy.Prediction:
        candidates = self.writer(
            location=location, season=season, mood=mood, num_haikus=self.n,
        ).haikus

        verdict = self.judge(
            location=location, season=season, mood=mood, candidates=candidates,
        )

        return dspy.Prediction(
            haiku=candidates[verdict.most_evocative_index],
            candidates=candidates,
            reasoning=verdict.reasoning,
        )


def hello6():
    # Configure DSPy to use local Ollama
    lm = dspy.LM(
        model="ollama/qwen3.5:4b",
        api_base="http://localhost:11434/v1",
        api_key=os.environ["OLLAMA_API_KEY"],
        reasoning_effort="none",
    )

    dspy.configure(lm=lm)

    ensemble = HaikuEnsemble(n=5)
    result = ensemble(location="Bodega Bay", season="autumn", mood="inspired")
    print(result.haiku)
    print('----')
    print(result.candidates)
    print('----')
    print(result.reasoning)
    print('----')

    print(dspy.inspect_history())



def main():
    hello6()


if __name__ == "__main__":
    main()
