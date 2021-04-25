import sympy as sp

x = sp.Symbol('x')
fx = 5*x + 4
y1 = fx.evalf(subs={x: 6})
print(y1)
