from Bio.Seq import translate

index = [1,2,3,4,5,6,9,10,11,12,13,14,15]

s = input()
out = input()

for i in index:
    if(translate(s, table=i).replace("*", "") == out):
        print(i)
        break