import math

n = int(input())

m = math.ceil(math.sqrt(n))
k = math.sqrt(m**2 - n)
found = False
while (n < m**2 - k**2):
    k = math.sqrt(m**2 - n)
    if k % 1 == 0:
        found = True
        break
    m = m + 1

if found:
    print(str(m) + " " + str(k))
else:
    print("impossible")