ref = input().replace("\n", "")
r = []
r.append([input().replace("\n", "") for _ in range(43)])
r.append([input().replace("\n", "") for _ in range(43)])

for i in range(2):
    r[i] = sorted(zip([ref.find(s) for s in r[i]], r[i]))

arr = [(" " * len(ref)) for i in range(43)]

print(ref)
for i in range(2):
    c = 0
    for indent, s in r[i]:
        if indent == -1:
            continue
        arr[c] = arr[c][:indent] + s + f">{i+1}" + arr[c][indent + 14 :]
        c += 1

print(*arr, sep="\n")
