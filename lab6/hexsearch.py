
import re
result = []
m = 0
mass = []
#regex = re.compile("0x........")
with open("memlog_free2.txt") as f:

    for line in f:
        if re.findall("0x............", line):
            result.append(re.findall("0x............", line))
size = len(result)
unique = []

for number in result:
    if number in unique:
        continue
    else:
        unique.append(number)

print("Число найденых адресов", size)
print("Число уникальных адресов", len(unique))
print("Нечетные")
for i in unique:
    m = result.count(i)
    if m % 2 != 0:
        print(i, m)

    #for j in range(m):
    #    result.remove(i)
