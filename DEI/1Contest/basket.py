values = [int(x) for x in input().split()]

n = values[0]

p = values[1]

l = values[2]

scores = {}

winners = []

for i in range(n):
    scores[input()] = 0

for i in range(l):
    name, s = input().split() 

    scores[name] = scores[name] + int(s)

    if scores[name] >= p and not name in winners:
        winners.append(name)

for name in winners:
    print(name + " wins!")

if len(winners) == 0:
    print("No winner!")

