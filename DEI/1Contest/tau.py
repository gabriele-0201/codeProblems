vars = {}

class op:
    def calcValue(self):
        if(self.type == "value"):
            return vars[self.value1]
        elif(self.type == "not"):
            return not self.value1.calcValue()
        elif self.type == "and":
            return self.value1.calcValue() and self.value2.calcValue()
        elif self.type == "or":
            return self.value1.calcValue() or self.value2.calcValue()
        elif self.type == "implies":
            return not self.value1.calcValue() or self.value2.calcValue()
        elif self.type == "equal":
            return self.value1.calcValue() == self.value2.calcValue()

def getType(c):
    if c == "K":
        return "and"
    elif c == "A":
        return "or"
    elif c == "C":
        return "implies"
    elif c == "E":
        return "equal"
    elif c == "N":
        return "not"

def findParam(s):

    operand1 = op()
    remainingString = ""

    if s[0] == "p" or s[0] == "q" or s[0] == "r" or s[0] == "s" or s[0] == "t" :
        operand1.type = "value"
        operand1.value1 = s[0]
        s = s[1::]
        remainingString = s
    else:
        operand1.type = getType(s[0])
        s = s[1::]
        operand1.value1, remainingString = findParam(s)
        if(operand1.type != "not"):
            operand1.value2, remainingString= findParam(remainingString)

    return operand1, remainingString

vals = []

s = ""
while(True):
    s = input()
    if(s == "0"):
        break
    vals.append(s)

for val in vals:

    taut = op()
    
    taut, remainingString = findParam(val)

    vars = {}

    for c in val:
        if c == "p" or c == "q" or c == "r" or c == "s" or c == "t":
            vars[c] = False

    tautology = True
    for i in range(pow(2,len(vars))):
        st = format(i, "b")
        for j in range(len(vars) - len(st)): 
            st = '0' + st
        #input = [int(x) for x in st] # pass to int really usefull

        for j, k in enumerate(vars.keys()):
            vars[k] = True if st[j] == "1" else False
        #print(vars) 
        out = taut.calcValue()
        #print(out)
        if out != True:
            tautology = False
            break

    if tautology: 
        print("tautology")
    else:
        print("not")