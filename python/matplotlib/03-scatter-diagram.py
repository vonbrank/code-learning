import numpy as np
import matplotlib.pyplot as plt
maxn = 100
x = np.random.randn(maxn)
y = x + np.random.randn(maxn) * 0.5
plt.scatter(x, y, c='r')
plt.show()
