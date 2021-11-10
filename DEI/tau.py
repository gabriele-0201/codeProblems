
class op:

    def clacOperand1():
        pass

def getType(c):
    if c == "K":
        return "and"
    elif c == "A":
        return "not"
    elif c == "C":
        return "implies"
    elif c == "E":
        return "equal"


vals = []

s = ""
while(True):
    s = input()
    if(s == "0"):
        break
    vals.append()


for val in vals:

    taut = op()

    c = val[0]
    val.remove(c)

    if c == "p" or c == "q" or c == "r" or c == "s" or c == "t" or c == "N":
        print("not")
        break

    taut.value = getType(c)

    for c in val:
        if()