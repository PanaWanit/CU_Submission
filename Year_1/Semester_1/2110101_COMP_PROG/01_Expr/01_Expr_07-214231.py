def mosteller(w, h):
    return (w*h)**0.5/60

def du_bois(w, h):
    return 7.184e-3 * w**0.425 * h**0.725

def fujimoto(w, h):
    return 8.883e-3 * w**0.444 * h**0.663
def main():
    w = float(input())
    h = float(input())
    print("Mosteller =", round(mosteller(w, h), 5))
    print("Du Bois =", round(du_bois(w, h), 5))
    print("Fujimoto =", round(fujimoto(w, h), 5))

exec(input())

