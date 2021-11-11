
class op:

    def clacOperand(n):
        pass

    def calcValue(self):
        if(self.type == "value"):
            print(self.value1)
        elif(self.type == "not"):
            print("not " + self.value1)

        print(self.type)

        print(self.value1.calcValue())
        print(self.value2.calcValue())
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

# Pay attenction to this recurtion, I really need TWO findParam? study the remaining string

def findParam(s):

    operand1 = op()
    remainingString = ""

    if s[0] == "p" or s[0] == "q" or s[0] == "r" or s[0] == "s" or s[0] == "t" :
        operand1.type = "value"
        operand1.value1 = s[0]
        s = s[1::]
        remainingString = s
    elif s[0] == "N":
        operand1.type = "not"
        operand1.value1 = s[1]
        s = s[2::]
        remainingString = s
    else:
        operand1.type = getType(s[0])
        s = s[1::]
        operand1.value1, remainingString = findParam(s)
        operand1.value2= findParam(remainingString)[0]
        remainingString = ""

    return operand1, remainingString

vals = []

s = ""
while(True):
    s = input()
    if(s == "0"):
        break
    vals.append(s)

# ALLORA, faccio un ciclo che parte e mi controlla la prima lettera maiuscola
# Poi trovata la prima lettere maiuscola la rimuove dalla stringa e va alla ricerca dei parametre
# Adesso per il primo parametro o trova una lettera minuscola (finito)
# Oppure una maiuscola, (se N allora prendo quella dopo ed ho fatto)
# Se Invece e' una maiuscola ricomincio in loop dalla ricerca del primo parametro
# appena ho finito con il primo parametro inizio con il secondo che ripete le stesse cose

for val in vals:

    taut = op()

    c = val[0]
    val = val[1::]
    if c == "p" or c == "q" or c == "r" or c == "s" or c == "t" or c == "N":
        print("not")
        break

    taut.type = getType(c)

    taut.value1, remainingString = findParam(c)
    taut.value1 = findParam(remainingString)[0]

    print(taut.calcValue())