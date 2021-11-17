stop = False

vals = []
v = []
while(True):
   
    n = int(input())

    if(n == 0):
        break
    
    s = input()

    if(s == 'too high'):
        t = [n, 'h']
        v.append(t)
    elif(s == 'too low'):
        t = [n, 'l']
        v.append(t)
    elif(s == 'right on'):

        t = [n, v[:]]# INSERT A COPY OF THE LIST
        vals.append(t) 
        v.clear()

for v in vals:    

    dis = False

    for b in v[1]:

        if b[1] == 'h':
            if b[0] <= v[0]:
                dis = True
                break

        elif b[1] == 'l':
            if b[0] >= v[0]:
                dis = True
                break
    
    if dis:
        print("Stan is dishonest")
    else:
        print("Stan may be honest")