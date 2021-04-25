M, N, T = map(int, input().split())

a = []

for i in range(0, M * T + 2):
    a.append(True)
i = 1


def check(x):
    while x > 0:
        if x % N == 0:
            return True
        x //= 10
    return False


while i <= M * T:
    if check(i):
        if i % M == 0:
            a[M] = False
        else:
            a[i % M] = False
    i += 1

flag = True

for i in range(1, M + 1):
    if a[i]:
        flag = False
        print("%d " % i, end='')

if flag:
    print("NO")
