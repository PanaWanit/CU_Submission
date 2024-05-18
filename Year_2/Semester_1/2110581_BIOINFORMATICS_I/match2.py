from Bio import pairwise2
from Bio.pairwise2 import format_alignment
from Bio import SeqIO
import numpy as np
from sklearn.cluster import KMeans
import itertools

# Load your sequences from a FASTA file (replace 'sequences.fasta' with your file)
sequences = [
    "AAAACAACTAACCCTTGCCAA",
    "AAACAACTAACCCTTGCCAAC",
    "AACAACTAACCCTTGCCAACG",
    "ACAACTAACCCTTGCCAACGG",
    "GAAAGCCAATAAAAGGACAAG",
    "AAAGCCAATAAAAGGACAAGG",
    "AAGCCAATAAAAGGACAAGGT",
    "AGCCAATAAAAGGACAAGGTT",
    "GCCAATAAAAGGACAAGGTTT",
    "AAAGGACAAGGTTTTTATCCT",
    "AAGGACAAGGTTTTTATCCTA",
    "AGGACAAGGTTTTTATCCTAC",
    "GGACAAGGTTTTTATCCTACA",
    "GACAAGGTTTTTATCCTACAT",
    "TTCATCCACTTGGACTAGTTT",
    "TCATCCACTTGGACTAGTTTT",
    "CATCCACTTGGACTAGTTTTT",
    "ATCCACTTGGACTAGTTTTTT",
    "TTGGACTAGTTTTTTAACCAA",
    "GGACTAGTTTTTTAACCAATC",
    "GACTAGTTTTTTAACCAATCC",
    "GCCTGGGACGAGATCCCGATC",
    "CCTGGGACGAGATCCCGATCA",
    "CTGGGACGAGATCCCGATCAC",
    "GGGACGAGATCCCGATCACCT",
    "GGACGAGATCCCGATCACCTA",
    "GACGAGATCCCGATCACCTAT",
    "AGATCCCGATCACCTATCCGA",
    "GATCCCGATCACCTATCCGAT",
    "TCCCGATCACCTATCCGATGG",
    "CCGATCACCTATCCGATGGAC",
    "CGATCACCTATCCGATGGACA",
    "GATCACCTATCCGATGGACAC",
    "ATCACCTATCCGATGGACACC",
    "TCACCTATCCGATGGACACCG",
    "GCCCTTGAAAAAACAACTAAC",
    "CCCTTGAAAAAACAACTAACC",
    "CCTTGAAAAAACAACTAACCC",
    "CTTGAAAAAACAACTAACCCT",
    "TTGAAAAAACAACTAACCCTT",
    "AACAAAAAAGGATTAAGTAGT",
    "ACAAAAAAGGATTAAGTAGTG",
    "CAAAAAAGGATTAAGTAGTGA",
    "AAAAAAGGATTAAGTAGTGAA",
    "AAAAAGGATTAAGTAGTGAAA",
    "CTAACCCTTGCCAACGGCGTG",
    "TAACCCTTGCCAACGGCGTGG",
    "AACCCTTGCCAACGGCGTGGG",
    "ACCCTTGCCAACGGCGTGGGA",
    "ACTCAACAAAAAAGGATTAAG",
    "CTCAACAAAAAAGGATTAAGT",
    "TCAACAAAAAAGGATTAAGTA",
    "TGAAAAAACAACTAACCCTTG",
    "GAAAAAACAACTAACCCTTGC",
    "AAAAAACAACTAACCCTTGCC",
    "AAAAACAACTAACCCTTGCCA",
    "TCCACTTGGACTAGTTTTTTA",
    "CACTTGGACTAGTTTTTTAAC",
    "ACTTGGACTAGTTTTTTAACC",
    "AAAAGGATTAAGTAGTGAAAG",
    "AAAGGATTAAGTAGTGAAAGC",
    "AAGGATTAAGTAGTGAAAGCC",
    "AGGATTAAGTAGTGAAAGCCA",
    "GGATTAAGTAGTGAAAGCCAT",
    "CAACTAACCCTTGCCAACGGC",
    "AACTAACCCTTGCCAACGGCG",
    "ACTAACCCTTGCCAACGGCGT",
    "CAACAAAAAAGGATTAAGTAG",
    "GATTAAGTAGTGAAAGCCATT",
    "ATTAAGTAGTGAAAGCCATTT",
    "TTAAGTAGTGAAAGCCATTTT",
    "TAAGTAGTGAAAGCCATTTTG",
    "AAGTAGTGAAAGCCATTTTGA",
    "AGTAGTGAAAGCCATTTTGAG",
    "GTGAAAGCCAATAAAAGGACA",
    "TGAAAGCCAATAAAAGGACAA",
    "CCAATAAAAGGACAAGGTTTT",
    "CAATAAAAGGACAAGGTTTTT",
    "AATAAAAGGACAAGGTTTTTA",
    "ATAAAAGGACAAGGTTTTTAT",
    "TAAAAGGACAAGGTTTTTATC",
    "AAAAGGACAAGGTTTTTATCC",
    "ACAAGGTTTTTATCCTACATG",
    "CAAGGTTTTTATCCTACATGA",
    "AGAAGTTTCATCCACTTGGAC",
    "GAAGTTTCATCCACTTGGACT",
    "AAGTTTCATCCACTTGGACTA",
    "AGTTTCATCCACTTGGACTAG",
    "GTTTCATCCACTTGGACTAGT",
]


# Function to calculate sequence similarity using pairwise alignment
def calculate_similarity(seq1, seq2):
    alignments = pairwise2.align.globalxx(seq1, seq2, one_alignment_only=True)
    best_alignment = alignments[0]
    alignment_score = best_alignment[2]
    return alignment_score


# Create a similarity matrix
num_sequences = len(sequences)
similarity_matrix = np.zeros((num_sequences, num_sequences))

for i, j in itertools.combinations(range(num_sequences), 2):
    similarity = calculate_similarity(sequences[i], sequences[j])
    similarity_matrix[i, j] = similarity
    similarity_matrix[j, i] = similarity

# Define the number of clusters you want
num_clusters = 5  # Change this as needed

# Perform hierarchical clustering
# clustering = KMeans(n_clusters=num_clusters, affinity="precomputed", linkage="average")
# cluster_labels = clustering.fit_predict(1 - similarity_matrix)

# Print the clusters
# for cluster_num in range(num_clusters):
# cluster_indices = np.where(cluster_labels == cluster_num)[0]
# print(f"Cluster {cluster_num + 1}:")
# for idx in cluster_indices:
# print(f"   {sequences[idx]}")

import matplotlib.pyplot as plt

max_k = 20
range_k = range(1, max_k + 1)
y = []

for num_cluster in range_k:
    clustering = KMeans(n_init=1, n_clusters=num_cluster, random_state=42)
    cluster_labels = clustering.fit_predict(1 - similarity_matrix)
    y.append(clustering.inertia_)

plt.plot(range_k, y)
plt.scatter(range_k, y)
plt.show()
