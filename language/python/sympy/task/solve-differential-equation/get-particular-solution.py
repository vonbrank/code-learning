import sympy as sy

x = sy.symbols('x')

C1 = sy.symbols('C1')
C2 = sy.symbols('C2')

general_solution = (C1*sy.sin(x) + C2*sy.cos(x) + x)*sy.exp(-x)

f1 = general_solution.subs(x, 0)
f2 = general_solution.diff(x, 1).subs(x, 0)

# print(f1)
# print(f2)

parameters = sy.solve([f1, f2], [C1, C2])

# print(parameters)
# print(parameters[C1])
# print(type(parameters[C1]))

particular_solution = general_solution
particular_solution = particular_solution.subs(C1, parameters[C1])
particular_solution = particular_solution.subs(C2, parameters[C2])
print(particular_solution)
