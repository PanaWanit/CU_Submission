s = input()
y = [""] * len(s)

for i in range(len(s)):
    y = sorted([s[i] + y[i] for i in range(len(s))])

print(y[0][1:])
