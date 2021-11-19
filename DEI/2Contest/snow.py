n = int(input())

ns = []
snows = []

for i in range(n):
    v = int(input())
    ns.append(v)

    snow = []

    for j in range(v):
        x = int(input())
        snow.append(x)

    snows.append(snow)

for i in range(n):

    ctn = 0
    ctns = []
    s = set()
    j = 0
    while j < ns[i]:
        
        if snows[i][j] in s:
            
            c = snows[i][j]
            j -= 1
            while(snows[i][j] != c):
                j -= 1
            j += 1

            ctns.append(ctn)
            ctn = 0
            s.clear()
            
        s.add(snows[i][j])
        ctn += 1
        j += 1
    ctns.append(ctn)

    print(max(ctns))

