import numpy as np


class KMeanClustering:
    def __init__(self, n_cluster=3, random_seed=0, centroid=None):
        self.centroid = centroid
        self.n_cluster = n_cluster
        self.random_seed = random_seed

    def fit(self, X):
        while True:
            start_centroid = np.array(self.centroid, dtype=np.float64)
            diffs = self.centroid[:, np.newaxis] - X
            distances = np.sum(diffs**2, axis=2)
            min_idx = np.argmin(distances, axis=0)  # Get min_index to all centroid points

            for i in range(self.n_cluster):
                points = X[min_idx == i, :]
                self.centroid[i, 0] = points[:, 0].mean()
                self.centroid[i, 1] = points[:, 1].mean()

            if np.array_equal(self.centroid, start_centroid):
                break

    def predict(self, X):
        diffs = self.centroid[:, np.newaxis] - X
        distances = np.sum(diffs**2, axis=2)
        min_idx = np.argmin(distances, axis=0)  # Get min_index to all centroid points
        return min_idx
