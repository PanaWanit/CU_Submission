import numpy as np
import numpy.typing as npt
import matplotlib.pyplot as plt


class Kmeans:
    def __init__(self, num_clusters: int = 3, to_tex: bool = False):
        self.num_clusters = num_clusters
        self.to_tex = to_tex

    def fit(self, X: npt.ArrayLike, initial=None):
        X = np.array(X)
        if initial == None:
            centroids = np.random.rand(self.num_clusters, X.shape[1])
        else:
            centroids = np.array(initial, dtype=np.float64)
        i = 1
        while True:
            if self.to_tex:
                print(r"\item")
                print(f"Attempt {i}: \\\\")
                i += 1

            dif_to_all_centroids = X[:, np.newaxis] - centroids
            euclidean_dist_to_all_centroids = np.power(dif_to_all_centroids, 2).sum(axis=2)
            cluster = np.argmin(euclidean_dist_to_all_centroids, axis=1)
            next_centroids = np.copy(centroids)

            for i in range(self.num_clusters):
                closest_points = X[cluster == i, :]
                updated_centroid = closest_points.mean(axis=0)
                next_centroids[i] = updated_centroid

                if self.to_tex:
                    print(f"Centroid {i+1} at ({centroids[i, 0]:.2f}, {centroids[i, 1]:.2f})")
                    print(r"\begin{flalign*}")
                    closest_points_str = ", ".join([f"({x[0]:.2f}, {x[1]:.2f})" for x in closest_points])
                    numerator_str_x = "+".join([f"{x[0]:.2f}" for x in closest_points])
                    numerator_str_y = "+".join([f"{x[1]:.2f}" for x in closest_points])
                    print(f"\\textbf{{Assign}}: \\quad & {closest_points_str}  & \\\\")
                    print(
                        f"\\textbf{{Update}}: \\quad & (\\dfrac{{ {numerator_str_x} }}{{{closest_points.shape[0]}}}, \\dfrac{{ {numerator_str_y} }}{closest_points.shape[0]} ) = \\left({updated_centroid[0]:.2f}, {updated_centroid[1]:.2f}\\right) &"
                    )
                    print(r"\end{flalign*}")
                    print()

            if np.array_equal(centroids, next_centroids):
                break
            centroids = next_centroids

        self.centroids = centroids
        self.clusters_ = cluster

        self.all_data_centroid = X.mean(axis=0)

        self.between_cluster_var = sum(
            [
                X[cluster == i, :].shape[0] * np.power(centroids[i] - self.all_data_centroid, 2).sum()
                for i in range(self.num_clusters)
            ]
        )

        self.all_data_var = sum([np.power(x - self.all_data_centroid, 2).sum() for x in X])

        self.inertia_ = self.between_cluster_var / self.all_data_var


if __name__ == "__main__":
    # For T5, T6
    data = [[1, 2], [3, 3], [2, 2], [8, 8], [6, 6], [7, 7], [-3, -3], [-2, -4], [-7, -7]]
    # init = [[3, 3], [2, 2], [-3, -3]]  # T5
    # init = [[-3, -3], [2, 2], [-7, -7]]  # T6

    init = [[3, 3], [2, 2], [-3, -3], [-7, -7]]  # OT2
    k = len(init)

    cluster = Kmeans(num_clusters=k, to_tex=False)
    cluster.fit(data, init)

    data = np.array(data)
    color = ["red", "green", "blue", "yellow"]
    cen_color = ["lightcoral", "springgreen", "royalblue", "gold"]

    plt.figure(figsize=(10, 6))
    for i in range(k):
        plt.scatter(
            data[cluster.clusters_ == i, 0], data[cluster.clusters_ == i, 1], c=color[i], label=f"cluster {i+1}"
        )
        plt.scatter(xp := cluster.centroids[i, 0], yp := cluster.centroids[i, 1], c=cen_color[i], alpha=0.2)
        plt.annotate(
            f"centroid {i+1} \n ({xp:.2f}, {yp:.2f})",
            xy=(xp - 0.5, yp + 0.5),
        )

    plt.grid()
    plt.legend()
    plt.show()

    print("between", cluster.between_cluster_var)
    print("all_data", cluster.all_data_var)
    print("explained variance", cluster.inertia_)
