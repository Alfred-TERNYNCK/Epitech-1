import math
import sys

def print_help():
        print("""USAGE
    ./107transfer [num den]+

DESCRIPTION
    num    polynomial numerator defined by its coefficients
    den    polynomial denominator defined by its coefficients""")
        return

def check_args():
    if len(sys.argv) == 1 or len(sys.argv) == 2:
        print("Error: invalid number of arguments")
        exit(84)
    for i in range(1, len(sys.argv)):
        for char in sys.argv[i]:
            if char not in "0123456789*":
                print("Error: invalid argument")
                exit(84)

def polynomial_value(x, coeffs):
    """
    Computes the value of a polynomial with given coefficients at a given point x.
    """
    result = 0
    for i, coeff in enumerate(coeffs):
        result += coeff * (x ** i)
    return result

def main():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        print_help()
        exit(0)
    check_args()
    num = [float(coeff) for coeff in sys.argv[1].split("*")]
    den = [float(coeff) for coeff in sys.argv[2].split("*")]

    for i in range(1001):
        x = i / 1000
        value = polynomial_value(x, num) / polynomial_value(x, den)
        print(f"{x:.3f} -> {value:.5f}")

if __name__ == "__main__":
    main()
