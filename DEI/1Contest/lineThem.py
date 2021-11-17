n = int(input())
names = []

for i in range(n):
   names.append(input()) 

prev = names[0]
names.remove(prev)
inc = False
dec = False

for n in names:
    if(prev > n):
        if(inc):
            inc = False
            dec = False
            break
        dec = True
    elif(prev < n):
        if(dec):
            inc = False
            dec = False
            break
        inc = True
    
    prev = n

if inc:
    print("INCREASING")
elif dec:
    print("DECREASING")
else:
    print("NEITHER")