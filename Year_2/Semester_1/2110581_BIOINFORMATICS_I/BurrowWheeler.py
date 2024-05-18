s = input()
ans = "".join([x[-1] for x in sorted([s[i:] + s[:i] for i in range(len(s))])])

print(ans)
