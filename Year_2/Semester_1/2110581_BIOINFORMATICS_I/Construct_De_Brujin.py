n = int(input())
s = input()

ans = {}
for i in range(len(s) - n + 1):
    ans[s[i : i + n - 1]] = ans.get(s[i : i + n - 1], "") + "," + s[i + 1 : i + n]

for x, y in ans.items():
    print(x, "->", y[1:])
