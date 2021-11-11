from typing import Counter


n = int(input())

ps = [int(x) for x in input().split()]

c = 0 
prev = ps[n - 1]

for i in range(n - 2, 0 - 1, -1):
    if(ps[i] >= prev):
        #if prev == 0:
        #    c = c + ps[i]
        #    ps[i] = 0
        #else:
        cc = (ps[i] - prev) + 1
        if cc > ps[i]:
            c = 1
            break
        c = c + cc
        ps[i] = ps[i] - cc

    prev = ps[i]
print(c)