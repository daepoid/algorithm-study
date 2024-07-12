n = int(input())
pos_list = [0, 0, 0, 0, 0]
for i in range(n):
    x, y = map(int, input().split())
    if x > 0 and y > 0:
        pos_list[0] += 1
    elif x < 0 and y > 0:
        pos_list[1] += 1
    elif x < 0 and y < 0:
        pos_list[2] += 1
    elif x > 0 and y < 0:
        pos_list[3] += 1
    else:
        pos_list[4] += 1
print(f'Q1: {pos_list[0]}\nQ2: {pos_list[1]}\nQ3: {pos_list[2]}\nQ4: {pos_list[3]}\nAXIS: {pos_list[4]}')
