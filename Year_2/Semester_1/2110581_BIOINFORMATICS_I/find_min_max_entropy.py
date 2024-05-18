import numpy as np

p = np.array([[0.1, 0.4, 0.1], [0.2, 0.2, 0.1], [0.3, 0.1, 0.7], [0.4, 0.3, 0.1]])
p = -p * np.log2(p)

col = np.sum(p, axis=0)
print(np.max(col), np.min(col))
