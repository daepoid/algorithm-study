t = int(input())

for i in range(t):
    n = int(input())
    max_name = ''
    max_count = 0
    for j in range(n):
        temp_name, temp_count = input().split()
        if int(temp_count) > max_count:
            max_count = int(temp_count)
            max_name = temp_name
    print(max_name)
