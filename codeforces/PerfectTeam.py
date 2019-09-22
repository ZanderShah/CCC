q = int(input())

for _ in range(q):
    c, m, x = map(int, input().split())
    print(min(min(c, m), (c + m + x) // 3))
