import sympy as sy

f = sy.symbols('f', cls=sy.Function)
x = sy.symbols('x')

differential_equation = sy.Eq(
    f(x).diff(x, 2) + 2 * f(x).diff(x, 1) + 2 * f(x), x * sy.exp(-x))
# 在这里输入你要求解的微分方程，逗号前输入左式，逗号后输入右式
# 若包含exp(), sin()等函数，请写成sy.exp(), sy.sin()等
general_solution = sy.dsolve(differential_equation, f(x)).rhs

print(general_solution)
