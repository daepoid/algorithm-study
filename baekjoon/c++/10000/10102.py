v = int(input())
temp_str = input()
a, b = 0, 0
for i in range(len(temp_str)):
    if temp_str[i] == 'A':
        a += 1
    else:
        b += 1
if a > b:
    print('A')
elif a < b:
    print('B')
else:
    print('Tie')
