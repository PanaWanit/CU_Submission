import random


def random_motif_search(sequences, k, num_iterations=1000):
    best_motif = None
    best_motif_count = 0

    for _ in range(num_iterations):
        seq_index = random.randint(0, len(sequences) - 1)
        seq = sequences[seq_index]
        start = random.randint(0, len(seq) - k)
        motif = seq[start : start + k]
        motif_count = 0

        for s in sequences:
            for i in range(len(s) - k + 1):
                if s[i : i + k] == motif:
                    motif_count += 1

        if motif_count > best_motif_count:
            best_motif = motif
            best_motif_count = motif_count

    return best_motif


# Example sequences for testing
sequences = []

with open("test.txt", "r") as f:
    sequences = [x.strip() for x in f.readlines()]

k = 10  # Length of the motif
num_iterations = 100_000

result = random_motif_search(sequences, k, num_iterations)
print(f"The most common motif of length {k} is: {result}")
