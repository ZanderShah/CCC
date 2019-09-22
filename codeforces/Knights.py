n = int(input())

for i in range(n):
    print(''.join('B' if (i + j) & 1 else 'W' for j in range(n)))
