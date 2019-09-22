import sys

T, N, M = [int(_) for _ in input().split()]

for t in range(1, T + 1):
    p = [3, 5, 7, 11, 13, 16, 17]
    res = []

    for pp in p:
        print(' '.join([str(pp)] * 18))
        sys.stdout.flush()
        res.append(sum(int(_) for _ in input().split()) % pp)

    k = res[-1]
    skip_p = 17

    while k <= M:
        works = True

        for i in range(len(p)):
            if k % p[i] != res[i]:
                works = False

        if works:
            break

        k += skip_p

    print(k)
    sys.stdout.flush()
    if "-1" == input():
        break

sys.exit()
