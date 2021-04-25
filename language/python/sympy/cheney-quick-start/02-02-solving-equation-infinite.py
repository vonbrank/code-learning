import sympy as sp

x = sp.Symbol('x')
y = sp.Symbol('y')

fx = x * 3 + y ** 2

print(sp.solve(fx, x, y))
