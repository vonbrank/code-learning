import sympy as sp
import matplotlib.pyplot as plt
import numpy as np

f = sp.symbols('f', cls=sp.Function)
x = sp.symbols('x')

eq = sp.Eq(f(x) + f(x).diff(x, 1), 5 * x)
print(sp.dsolve(eq, f(x)))

# exit()

C1 = sp.symbols('C1')
eqr = (C1 + 5*(x - 1)*sp.exp(x))*sp.exp(-x)
eqr1 = eqr.subs(x, 0)
print(sp.solveset(eqr1 - 1, C1))

# exit()
eqr2 = eqr.subs(C1, 6)

x_1 = np.arange(-5, 5, 0.1)
y_1 = [(6 + 5*(x - 1)*sp.exp(x))*sp.exp(-x) for x in x_1]
plt.plot(x_1, y_1)
plt.axis([-6, 6, -10, 10])
plt.grid()
plt.show()
