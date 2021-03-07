import numpy as np
a = np.arange(10)**3
print(a)
print(a[2])
print(a[::-1])
for i in a:
    print(i**(1/3.))


def f(x, y):
    return 10 * x + y


b = np.fromfunction(f, (5, 4), dtype=int)
print(b)
print(b.dtype)
print(b[:, 1])
print(b[1:2, :])
