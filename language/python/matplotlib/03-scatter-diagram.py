import numpy as np
import matplotlib.pyplot as plt
maxn = 100
x = np.random.randn(maxn)
y = x + np.random.randn(maxn) * 0.5
plt.scatter(x, y, c='r')
plt.show()

x = np.array([20, 30, 40, 50])
y = np.array([0, 4, 2, 8])
print(x-3*y)
plt.scatter(x, x-10*y)
plt.show()
