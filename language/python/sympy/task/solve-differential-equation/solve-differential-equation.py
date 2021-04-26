import sympy as sy
import matplotlib.pyplot as plt
import numpy as np

f = sy.symbols('f', cls=sy.Function)
x = sy.symbols('x', real=True)

differential_equation = sy.Eq(
    f(x).diff(x, 2) - 4 * f(x).diff(x, 1) + 3 * f(x), 0)

general_solution = sy.dsolve(differential_equation, f(x)).rhs

print(general_solution)

exit(0)

f1 = general_solution.evalf(subs={x: 0}) - 6
f2 = general_solution.diff(x, 1).evalf(subs={x: 0}) - 10

print(f1)
print(f2)

# particular_solution = sy.solve([f1, f2], [C1, C2])
# print(particular_solution)
# print(type(sy.dsolve(eq, f(x))))
# print(str(sy.dsolve(eq, f(x))))
# print(type(str(sy.dsolve(eq, f(x)))))
# print(type(sy.dsolve(eq, f(x)).rhs))
