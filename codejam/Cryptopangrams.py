from math import gcd

T = int(input())
for t in range(1, T + 1):
    N, L = [int(_) for _ in input().split()]
    ciphertext = [int(_) for _ in input().split()]

    plaintext = [0] * (L + 1)

    i = 0
    while ciphertext[i] == ciphertext[i + 1]:
        i += 1

    plaintext[i + 1] = gcd(ciphertext[i], ciphertext[i + 1])

    for i in range(i + 1, len(ciphertext)):
        plaintext[i + 1] = ciphertext[i] // plaintext[i]
    for i in reversed(range(i)):
        plaintext[i] = ciphertext[i] // plaintext[i + 1]

    decrypt = {}
    c = 'A'
    for p in sorted(set(plaintext)):
        decrypt[p] = c;
        c = chr(ord(c) + 1)

    print('Case #{}: {}'.format(t, ''.join(decrypt[p] for p in plaintext)))
