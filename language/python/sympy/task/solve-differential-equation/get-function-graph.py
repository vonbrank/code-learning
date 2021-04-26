import sympy as sy
import matplotlib.pyplot as plt
import numpy as np

x = sy.symbols('x')
particular_solution = (x - sy.sin(x))*sy.exp(-x)

x_range = np.arange(-5, 5, 0.1)
y_range = [particular_solution.subs(x, x_val) for x_val in x_range]
plt.plot(x_range, y_range)
plt.axis([-6, 6, -10, 10])
plt.grid()
plt.show()
