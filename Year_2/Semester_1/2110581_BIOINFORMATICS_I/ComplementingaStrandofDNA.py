
def reverse_complement(s):
    a = list(s[::-1])
    for i in range(len(a)):
        if a[i] == 'T':
            a[i] = 'A'
        elif a[i] == 'A':
            a[i] = 'T'
        elif a[i] == 'C':
            a[i] = 'G'
        else:
            a[i] = 'C'
    
    return "".join(a)


c = 0
with open('input.txt') as f:
    a = f.readlines()[1::2]
    for s in a:
        s = s.replace("\n", "")
        c += reverse_complement(s) == s

print(c)