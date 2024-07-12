a = input()
b = input()
c = input()

if len(a) == len(c):
    if b == '+':
        print(int(a) + int(c))
    else:
        print(int(a) * int(c))
else:
    if len(a) > len(c):
        big = len(a)
        small = len(c)
    elif len(a) < len(c):
        big = len(c)
        small = len(a)
    num_str = '1'
    if b == '*':
        for i in range(big+small - 2):
            num_str += '0'
    elif b == '+':
        for i in range(big-small - 1):
            num_str += '0'
        num_str += '1'
        for i in range(small - 1):
            num_str += '0'
    print(num_str)
