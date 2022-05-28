from random import randint
n = int(input())
print(n)
print(' '.join([str(randint(1, 1000000)) for i in range(n)]))
