import sympy as sp

x = sp.Symbol('x')
y = sp.Symbol('y')
fx = x * x + x * y
y1 = fx.evalf(subs={x: 6, y: 4})
print(y1)
