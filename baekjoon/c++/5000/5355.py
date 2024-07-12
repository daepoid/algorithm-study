t = int(input())
for i in range(t):
    str = input().split()
    num = float(str[0])
    for j in range(1, len(str)):
        if str[j] == '@':
            num *= 3
        elif str[j] == '%':
            num += 5
        elif str[j] == '#':
            num -= 7
    print(f'{num:0.2f}')
