import numpy as np
a = np.int32((np.random.random((3, 4)) * 10))
print(a)
print(a.ravel())
print(a.reshape(2, -1))
print(a.reshape(2, -1).T)
