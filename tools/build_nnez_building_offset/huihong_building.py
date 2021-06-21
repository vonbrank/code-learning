import numpy as np

f = open(r'D:\Users\VonBrank\Documents\GitHub\code-learning\tools\build_nnez_building_offset\huihong_building_scene_02.in', 'r')


A_offset = np.array([[49, 68, -108]])
B_offset = np.array([[1172, 80, 1210]])
A = np.array([[1, 0, 0],
              [0, 1, 0],
              [0, 0, 1]])
A = np.matrix(A)
B = np.array([[-1, 0, 0],
              [0, 1, 0],
              [0, 0, -1]])
B = np.matrix(B)
X1_absolute = np.zeros((1, 3))
X1_relative = np.zeros((1, 3))
X2_absolute = np.zeros((1, 3))
X2_relative = np.zeros((1, 3))
Xr_offest = 180


def cal_cor(op, x, y, z, xr):
    # global A_offset

    def cal_X1(x, y, z):
        # print("1: 计算X1")
        X2_absolute[0][0], X2_absolute[0][1], X2_absolute[0][2] = x, y, z
        global X1_relative, A_offset, B_offset
        # A_offset = np.zeros((1, 3))
        # B_offset = np.zeros((1, 3))

        X2_relative = X2_absolute - B_offset
        print((A.I @ B @ X2_relative.T + A_offset.T).T, end='')
        pass

    def cal_X2(x, y, z):
        # print("2: 计算X2")
        # X1_absolute[0] = 2
        # X1_absolute[1] = 1
        X1_absolute[0][0], X1_absolute[0][1], X1_absolute[0][2] = x, y, z
        global X1_relative, A_offset, B_offset
        # A_offset = np.zeros((1, 3))
        # B_offset = np.zeros((1, 3))
        X1_relative = X1_absolute - A_offset
        # print(B.I @ A)
        # print(B.I @ A @ X1_relative.T)
        print((B.I @ A @ X1_relative.T + B_offset.T).T, end='')
        pass

    # print(A)
    # print(B)
    # print(B.I @ A @ X)

    # print("1: 计算X1")
    # print("2: 计算X2")

    # op = int(input())

    # print(B_offset)
    # print(B_offset.T)
    if op == 1:
        cal_X1(x, y, z)
        print(' ', xr + Xr_offest)
    else:
        cal_X2(x, y, z)
        print(' ', xr - Xr_offest)


n, op = map(int, f.readline().split())
# print(n)
# print(op)
for i in range(0, n):
    x, y, z, xr = map(int, f.readline().split())
    cal_cor(op, x, y, z, xr)
    # print(f.readline())
