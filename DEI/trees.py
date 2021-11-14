n = int(input())

trees = []

#for i in range(n):
#    trees.append(int(input()))
trees = [int(x) for x in input().split()]

trees.sort(reverse=True)

#dc = []
c = 1
for i in range(len(trees)):
     #dc.append(t + 1)
     trees[i] += (c + 1)
     c += 1

print(max(trees))