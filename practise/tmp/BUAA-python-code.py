import math  # 使用math.floor()前要导入math模块
n, m = map(int, input().split())  # 输入n, m
cnt = 0  # 统计障碍数
gain = 0    # 获得的高跟鞋数
loss = 0    # 损失的高跟鞋数
for i in range(n):
    a, b = map(int, input().split())    # 输入a, b
    if b == 1:  # 如果b=1, 则损失+a, 障碍数+1
        loss += a
        cnt += 1
    else:   # 否则获得a个高跟鞋
        gain += a
    if(loss >= m + gain):   # 如果过程中剩余高跟鞋数小于0，就跳出循环
        break

# m + gain - loss 表示剩余高跟鞋数
if(loss >= m + gain):   # 剩余数小于等于0就lose
    print("Sorry, you lose!")
else:   # (m + gain - loss)/(loss/cnt) 算出能爬上几阶台阶，math.floor可以实现向下取整，"%d %d"%(...)可以实现格式化输出
    print("%d %d" % (m + gain - loss, math.floor((m + gain - loss)/(loss/cnt))))
