import random

def answer(g):
    R = len(g)
    mask_len = 1 << (R + 1)
    ternary_mask_len = 3 ** (R + 1)
    C = len(g[0])

    last = [1] * mask_len
    cur = [0] * mask_len

    for col in range(C):
        # Compress last information
        transformed_masks = [0] * ternary_mask_len

        for mask in range(mask_len):
            if last[mask] == 0:
                continue

            valid = True

            # Transformed masks for state by encoding in ternary
            t = [0]

            for row in range(R):
                c = mask >> row & 1
                c += mask >> (row + 1) & 1

                modifiers = []

                if g[row][col]:
                    if c == 2:
                        valid = False
                        break
                    else:
                        # c = 0, 1 requires 1, 0
                        modifiers.append(c ^ 1)
                else:
                    # As long as c does not equal 1
                    if c == 0:
                        modifiers += [0, 2]
                    elif c == 1:
                        modifiers += [1, 2]
                    else:
                        modifiers += [0, 1, 2]

                tt = []
                for t_mask in t:
                    for modifier in modifiers:
                        tt.append(t_mask * 3 + modifier)
                t = tt

            if not valid:
                continue

            for t_mask in t:
                transformed_masks[t_mask] += last[mask]

        # Compute current state
        for mask in range(mask_len):
            t_mask = 0
            for row in range(R):
                c = mask >> row & 1
                c += mask >> (row + 1) & 1
                t_mask = t_mask * 3 + c

            cur[mask] += transformed_masks[t_mask]

        last = cur
        cur = [0] * mask_len

    return sum(last)

# g = [[True, True, False, True, False, True, False, True, True, False], [True, True, False, False, False, False, True, True, True, False], [True, True, False, False, False, False, False, False, False, True], [False, True, False, False, False, False, True, True, False, False]]
g = []
for i in range(10):
    g.append([])
    for j in range(50):
        g[i].append(random.choice([True, False]))
print(answer(g))
