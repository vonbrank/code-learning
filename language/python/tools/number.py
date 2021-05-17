sha256 = input()
print(sha256)

res_base_10 = 0

for i in sha256[::-1]:
    print(i, end=' ')
    now = 0
    if(i.isdigit()):
        now = ord(i) - ord('0')
        print(now, end=' ')
        print('digit', end=' ')
    if(i.isalpha()):
        now = ord(i) - ord('a') + 10
        print(now, end=' ')
        print('alpha', end=' ')

    res_base_10 *= 16
    res_base_10 += now
    print(res_base_10)

print(res_base_10)

while res_base_10 > 0:
    print("[%d] " % (res_base_10 % 31), end=' ')
    res_base_10 //= 10
