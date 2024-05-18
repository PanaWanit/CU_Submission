with open("answerseq.txt", "r") as f:
    m = [x.strip() for x in f.readlines()]

with open("answerseq.txt", "w") as f:
    for i, x in enumerate(m, start=1):
        f.write(f">test{i}\n")
        f.write(x + "\n")
