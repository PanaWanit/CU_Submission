import random


def random_motif_search(dna, k, t, N):
    best_motifs = [random.choice([seq[i : i + k] for i in range(len(seq) - k + 1)]) for seq in dna]
    best_score = calculate_score(best_motifs)
    cnt = 0
    for _ in range(N * N * N):
        random_index = random.randint(0, t - 1)
        motifs_except_i = best_motifs[:random_index] + best_motifs[random_index + 1 :]
        profile = create_profile(motifs_except_i, k)

        removed_sequence = dna[random_index]
        probabilities = []
        for i in range(len(removed_sequence) - k + 1):
            kmer = removed_sequence[i : i + k]
            probability = calculate_probability(kmer, profile)
            probabilities.append(probability)

        total_probability = sum(probabilities)
        normalized_probabilities = [p / total_probability for p in probabilities]
        chosen_index = random.choices(range(len(probabilities)), normalized_probabilities)[0]

        best_motifs[random_index] = removed_sequence[chosen_index : chosen_index + k]

        score = calculate_score(best_motifs)
        if score < best_score:
            best_score = score
        else:
            cnt += 1
        if cnt == 10000:
            break
    return best_motifs, best_score


def create_profile(motifs, k):
    profile = {base: [1] * k for base in "acgt"}
    t = len(motifs)

    for i in range(k):
        for motif in motifs:
            base = motif[i]
            profile[base][i] += 1

    for base in profile:
        for i in range(k):
            profile[base][i] /= t + 4  # Add pseudocounts

    return profile


def calculate_probability(kmer, profile):
    probability = 1.0
    for i, base in enumerate(kmer):
        probability *= profile[base][i]
    return probability


def calculate_score(motifs):
    k = len(motifs[0])
    t = len(motifs)
    consensus = ""

    for i in range(k):
        counts = {"a": 0, "c": 0, "g": 0, "t": 0}
        for motif in motifs:
            counts[motif[i]] += 1
        consensus += max(counts, key=counts.get)

    score = 0
    for motif in motifs:
        score += sum(1 for a, b in zip(motif, consensus) if a != b)

    return score


# Example usage:
f = open("test.txt")
dna = [i.strip() for i in f.readlines()]
k = 10
t = 97
N = 1000

best_motifs, best_score = random_motif_search(dna, k, t, N)
print("Best Motifs:", best_motifs)
print("Best Score:", best_score)

# After running the Gibbs sampling algorithm, you can modify the best_motifs list to capitalize the motifs in each sequence.
capitalized_sequences = [seq[:i] + motif.upper() + seq[i + k :] for i, (seq, motif) in enumerate(zip(dna, best_motifs))]

# Now, you can print the sequences with capitalized motifs:
for i, sequence in enumerate(capitalized_sequences):
    print(f"Sequence {i + 1}: {sequence}")
