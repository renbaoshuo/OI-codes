from math import *

n, m = map(int, input().split())

print(comb(n + m, m) - comb(n + m, m - 1))
