q = int(input())

for _ in range(q):
    n = int(input())

    s = [0] * 15
    for ss in map(int, input().split()):
        if ss > 2048:
            continue
        s[ss.bit_length()] += 1

    for i in range(0, 11 + 1):
        s[i + 1] += s[i] // 2

    print('YES' if s[12] != 0 else 'NO')
