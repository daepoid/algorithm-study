temp_str = input()
upper = False
total = 10
if temp_str[0] == '(':
    upper = True
else:
    upper = False

for i in range(1, len(temp_str)):
    if not upper:
        if temp_str[i] == '(':
            total += 10
            upper = True
        else:
            total += 5
    else:
        if temp_str[i] == ')':
            total += 10
            upper = False
        else:
            total += 5
print(total)