import math

init = input().split()

n = int(init[0])
m = int(init[1])
k = int(init[2])

ns = [int(x) for x in input().split()]
ms = [int(x) for x in input().split()]
ks = [int(x) for x in input().split()]

for side in ks:
    ms.append(side * (math.sqrt(2)/2))

ns.sort(reverse=True)
ms.sort(reverse=True)

#print(ns)
#print(ms)

ctn = 0

for rad in ns:
    
    indexToRemove = -1

    for index, hRad in enumerate(ms):

        if hRad < rad:
            ctn += 1
            indexToRemove = index
            break

    if indexToRemove != -1:
        ms.pop(indexToRemove)

print(ctn)