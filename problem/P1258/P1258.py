a = input().split()
print('%.6lf' % (((int(a[2]) + int(a[1])) * int(a[0]) / (int(a[2]) + 3 * int(a[1]))) / int(a[2]) +
                 (int(a[0]) - ((int(a[2]) + int(a[1])) * int(a[0]) / (int(a[2]) + 3 * int(a[1])))) / int(a[1])))
