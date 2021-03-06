import numpy as np
import math
a = np.array([2, 3, 4])
print("a:", a)
print(a.dtype)
b = np.array([1.2, 2.4, 3.6])
print("b:", b)
print(b.dtype)
c = np.array([(1, 2, 3), (4.5, 5, 6)], dtype=np.int32)
print(c)
d = np.zeros((3, 4))
print(d)
e = np.ones((3, 5))
print(e)
f = np.empty((2, 3))
print(f)
g = np.arange(10, 30, 5)
print(g)
h = np.linspace(0, 2, 9)
print(h)
i = np.linspace(0, 2*math.pi, 100)
print(i)
print(np.sin(math.pi/2))
