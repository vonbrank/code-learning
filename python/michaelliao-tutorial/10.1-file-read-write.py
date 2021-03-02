try:
    f = open('python\michaelliao-tutorial\input.txt', 'r')
    a = f.read()
    print(type(a))
    print(a)
finally:
    if f:
        f.close()
