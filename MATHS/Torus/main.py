import math
import sys

list_a = []

class return_zero(Exception):
    pass

def function_dev(x):
    _, a1, a2, a3, a4 = list_a
    return a1 + 2 * a2 * x + 3 * a3 * x ** 2 + 4 * a4 * x ** 3

def function(x):
    a0, a1, a2, a3, a4 = list_a
    return a0 + a1 * x + a2 * x ** 2 + a3 * x ** 3 + a4 * x ** 4

def bisection_method(n):
    a = 0
    b = 1
    c = 1
    while int(function(c) * 10 ** n) != 0:
        c = (a + b) / 2
        if function(a) * function(c) < 0:
            b = c
        else:
            a = c
        if int(function(c) * 10 ** n) == 0:
            print("x = {:.{}f}".format(c,n))
        else:
            print("x = {:g}".format(c))

def newton_method(n):
    a = 0.5
    len_a = 0
    f = function
    f_dev = function_dev
    print("x = 0.5")
    while int(f(a) * 10 ** n) != 0:
        a = a - f(a) / f_dev(a)
        len_a = min(max(len(f"{a:.{n}g}") - len(str(int(a))), len_a), n)
        print(f"x = {float(f'{a:.{n}g}'):.{len_a}f}")

def secant_method(n):
    a = 0
    b = 1
    x = 0
    f = function
    while abs(f(b)) > 10 ** -n:
        a, b = b, b - f(b) * (b - a) / (f(b) - f(a))
        s = "{:.{}f}".format(b, n)
        if x == 0:
            s = s.rstrip("0")
        x = 1
        print(f"x = {s}")

def recip_arg():
    global list_a
    list_a = [int(x) for x in sys.argv[2:7]]
    return sys.argv[1], int(sys.argv[7])

def main():
    try:
        opt, n = recip_arg()
    except:
        print("Error: invalid arguments, use -h for help", file=sys.stderr)
        raise
    try :
        if opt == "1":
            bisection_method(n)
        elif opt == "2":
            newton_method(n)
        elif opt == "3":
            secant_method(n)
    except ZeroDivisionError:
        print("divition by zero", file=sys.stderr)
        raise

def check_args():
    if len(sys.argv) not in [8, 2] or (len(sys.argv) == 2 and sys.argv[1] != "-h"):
        print("Error: invalid arguments, use -h for help", file=sys.stderr)
        raise
    if sys.argv[1] == "-h":
        print("""USAGE
    ./105torus opt a0 a1 a2 a3 a4 n

DESCRIPTION
    opt      method option:
                 1 for the bisection method
                 2 for the Newton's method
                 3 for the secant method
    a[0-4]   coefficients of the equation
    n        precision (the application of the polynomial to the solution
             should be smaller than 10^-n)
    """)
        raise return_zero
    if sys.argv[1] not in ["1", "2", "3"] or int(sys.argv[7]) < 0:
        print("Error: invalid arguments, use -h for help", file=sys.stderr)
        raise

if __name__ == "__main__":
    try :
        check_args()
        main()
    except return_zero:
        sys.exit(0)
    except:
        sys.exit(84)
