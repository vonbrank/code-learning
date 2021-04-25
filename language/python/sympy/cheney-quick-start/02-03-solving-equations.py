import sympy as sp

x = sp.Symbol('x')
y = sp.Symbol('y')

f1 = x + y - 3
f2 = x - y + 5

print(sp.solve([f1, f2], [x, y]))
