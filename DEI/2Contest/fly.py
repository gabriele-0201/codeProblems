from operator import itemgetter

x, y = input().split()
x = int(x)
y = int(y)

# Se x e' minore di zero allora posso prendere il valore assoluto solo che devo invertire tutti i coefficenti dei scudi
convert = False
if (x < 0):
    x = abs(x)
    convert = True

n = int(input())

sh = []

for i in range(n):
    sh.append([float(x) for x in input().split()])

h = 0
totSpaces = 0
hSky = []
sums = 0

sh = sorted(sh, key=itemgetter(0))

for s in sh:
    if s[0] > h:
        hSky.append(s[0] - h)
    
    h = s[1]

if h < y:
    hSky.append(y - h)

for s in sh:
    sums += (s[1] - s[0]) * s[2]

for h in hSky:
    sums += h

#print(x)
#print(len(hSky) + len(sh))
#print(sums)

if(convert):
    print(-(x / sums))
else:
    print(x / sums)
