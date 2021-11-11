vars = {}

class op:

    def clacOperand(n):
        pass

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
        elif self.type == "equals":
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

# TRUE
# TRUE OR p
# p OR NOT p
# NOT (p AND NOT p)
# p == p
# (p OR q) == p OR (NOT p AND q)
# A E Apq p K Npq
# (p == q) -> (p -> q)

# Pay attenction to this recurtion, I really need TWO findParam? study the remaining string
def findParam(s):

    operand1 = op()
    remainingString = ""

    if s[0] == "p" or s[0] == "q" or s[0] == "r" or s[0] == "s" or s[0] == "t" :
        operand1.type = "value"
        operand1.value1 = s[0]
        s = s[1::]
        remainingString = s
        #print("variable created "+ str(operand1.value1))
    #elif s[0] == "N":
    #    operand1.type = "not"
    #    operand1.value1 = s[1]
    #    s = s[2::]
    #    remainingString = s
    #    #print("NOT " + str(operand1.value1))
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

    c = val[0]
    if c == "p" or c == "q" or c == "r" or c == "s" or c == "t":
        taut.type = "value"
        taut.value1 = c
    else:
        val = val[1::]
        taut.type = getType(c)
        taut.value1, remainingString = findParam(val)
        
        #if(taut.value1.type == "value"):
        #   taut.value1 = taut.value1.value1

        if(taut.type != "not"):
            taut.value2 = findParam(remainingString)[0]

    for c in val:
        if c == "p" or c == "q" or c == "r" or c == "s" or c == "t":
            vars[c] = False

    prev = False
    tautology = True
    for i in range(pow(2,len(vars))):
        st = format(i, "b")
        for j in range(len(vars) - len(st)): # pass to int really usefull
            st = '0' + st
        input = [int(x) for x in st]

        for j, k in enumerate(vars.keys()):
            vars[k] = True if input[j] == 1 else False
        #print(vars) 
        out = taut.calcValue()
        #print(out)
        if(i == 0):
            prev = out
        else:
            if prev != out:
                tautology = False
                break

    if tautology: 
        print("tautology")
    else:
        print("not")