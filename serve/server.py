from vllm import LLM, SamplingParams

def offlline_generate():
    prompts = [
        "Hello, my name is",
        "The president of the United States is",
        "The capital of France is",
        "The future of AI is",
    ]

    sampling_params = SamplingParams(temperature=0.8, top_p=0.95)

    llm = LLM(
        # model="Qwen/Qwen3.5-0.8B",
        model="HuggingFaceTB/SmolLM2-135M-Instruct",
        max_model_len=3000,          # reduce context window
        gpu_memory_utilization=0.9,
    )

    outputs = llm.generate(prompts, sampling_params)

    for output in outputs:
        prompt = output.prompt
        generated_text = output.outputs[0].text
        print(f"Prompt: {prompt!r}, Generated text: {generated_text!r}")


def offline_chat():
    from vllm import LLM, SamplingParams

    llm = LLM(
        # model="Qwen/Qwen3.5-0.8B",
        model="HuggingFaceTB/SmolLM2-135M-Instruct",
        max_model_len=3000,
        gpu_memory_utilization=0.9,
    )

    sampling_params = SamplingParams(temperature=0.8, top_p=0.95, max_tokens=100)

    conversation = [[
        {"role": "system", "content": "You are a concise assistant."},
        {"role": "user", "content": "What is the capital of France?"},
    ]]

    outputs = llm.chat(conversation, sampling_params=sampling_params)

    for output in outputs:
        print(f"Prompt: {output.prompt!r}")
        print(f"Response: {output.outputs[0].text!r}")


def main():
    offline_chat()

        
if __name__ == "__main__":
    main()

"""
# OpenAI Completions API  


curl http://localhost:8000/v1/completions \
    -H "Content-Type: application/json" \
    -d '{
        "model": "HuggingFaceTB/SmolLM2-135M-Instruct",
        "prompt": "San Francisco is a",
        "max_tokens": 7,
        "temperature": 0
    }'


# OpenAI Chat Completions API 

curl http://localhost:8000/v1/chat/completions \
    -H "Content-Type: application/json" \
    -d '{
        "model": "HuggingFaceTB/SmolLM2-135M-Instruct",
        "messages": [
            {"role": "system", "content": "You are a helpful assistant."},
            {"role": "user", "content": "Who won the world series in 2020?"}
        ],
        "max_tokens": 20,
        "temperature": 0
    }'
"""

