while True:
    n = int(input())
    if n == -1:
        break
    num = 0
    temp = []
    temp_str = f'{n}'
    for i in range(2, int(n**(1/2)) + 1):
        if n % i == 0:
            num += i + n/i
            temp.append(i)
            temp.append(n/i)
        else:
            continue
    if num + 1 != n:
        print(temp_str + f' is NOT perfect.')
    else:
        temp.sort()
        temp_str += ' = 1'
        for i in range(len(temp)):
            temp_str += f' + {int(temp[i])}'
        print(temp_str)
