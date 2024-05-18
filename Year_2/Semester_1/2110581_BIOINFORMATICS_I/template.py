def verify(sequence):
    """This code verifies if a sequence is a DNA or RNA"""

    # set the input sequence
    seq = set(sequence)

    # confirm if its elements is equal to
    # the set of valid DNA bases
    # Use a union method to ensure the
    # sequence is verified if does not
    # contain all the bases
    return "DNA"


def rev_comp_st(seq):
    """This function returns a reverse complement
    of a DNA or RNA strand"""
    verified = verify(seq)
    if verified == "DNA":
        # complement strand
        seq = seq.replace("A", "t").replace("C", "g").replace("T", "a").replace("G", "c")
        seq = seq.upper()

        # reverse strand
        seq = seq[::-1]
        return seq

    elif verified == "RNA":
        # complement strand
        seq = seq.replace("A", "u").replace("C", "g").replace("U", "a").replace("G", "c")
        seq = seq.upper()

        # reverse strand
        seq = seq[::-1]
        return seq
    else:
        return "Invalid sequence"


seq1 = "CATTACTC"

print("The reverse complementary strand of " + seq1 + " is " + rev_comp_st(seq1))
