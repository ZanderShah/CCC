import sys

T = int(input())

for t in range(1, T + 1):
    N, B, F = [int(_) for _ in input().split()]

    K = 4
    while 2 ** K >= N:
        K -= 1

    p = [(('0' * (2 ** k) + '1' * (2 ** k)) * 1024)[:N] for k in reversed(range(K + 1))]
    res = []

    for pp in p:
        print(pp)
        sys.stdout.flush()
        res.append(input())

    broken = [2 ** K] * (N // (2 ** K))
    if N % (2 ** K) != 0:
        broken.append(N % (2 ** K))

    l = -1
    i = -1
    for r in res[0]:
        if l != r:
            i += 1
            if l == -1 and r == '1':
                i += 1
            l = r
        broken[i] -= 1

    for k in range(1, K + 1):
        new_broken = []

        i = 0
        j = 0
        for b in broken:
            nb = [0, 0]

            for _ in range(2 ** (K - k + 1)):
                if i >= N:
                    break
                if p[k][i] == '0':
                    nb[0] += 1
                else:
                    nb[1] += 1
                i += 1

            for _ in range(2 ** (K - k + 1) - b):
                if j >= N - B:
                    break
                if res[k][j] == '0':
                    nb[0] -= 1
                else:
                    nb[1] -= 1
                j += 1

            new_broken += nb

        broken = new_broken

    print(' '.join(str(b) for b in range(len(broken)) if broken[b] != 0))
    sys.stdout.flush()
    if "-1" == input():
        break

sys.exit()
