import sympy as sy
import matplotlib.pyplot as plt
import numpy as np

f = sy.symbols('f', cls=sy.Function)
x = sy.symbols('x')

eq = sy.Eq(f(x).diff(x, 2) + f(x).diff(x, 1), 1)

print(sy.dsolve(eq, f(x)))
print(type(sy.dsolve(eq, f(x))))
print(str(sy.dsolve(eq, f(x))))
print(type(str(sy.dsolve(eq, f(x)))))
print(type(sy.dsolve(eq, f(x)).rhs))
