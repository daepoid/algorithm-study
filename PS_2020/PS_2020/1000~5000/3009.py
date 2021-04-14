a = [0, 0, 0]
b = [0, 0, 0]
x, y = 0, 0
for i in range(3):
    a[i], b[i] = map(int, input().split())

a.sort()
b.sort()
if a[0] == a[1]:
    x = a[2]
else:
    x = a[0]
if b[0] == b[1]:
    y = b[2]
else:
    y = b[0]
print(x, y)
