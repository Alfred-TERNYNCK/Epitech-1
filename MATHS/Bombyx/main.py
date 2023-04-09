import math
import sys

def calc_bombyx(n, k):
    if k < 1 or k > 4:
        raise Exception
    for i in range(1, 101):
        n_tmp = k * n * (1000 - n) / 1000
        print(f"{i} {n:.2f}")
        n = n_tmp

def calc_bombyx_2(n, i0, i1):
    k = 1.0
    while k < 4:
        i = 1
        tmp_n = float(n)
        while i < i0:
            tmp_n = k * tmp_n * ((1000 - tmp_n) / 1000)
            tmp_n = max(0, tmp_n)
            i += 1
        while i <= i1:
            formatted_n = "{:.2f}".format(tmp_n)
            if formatted_n[-1] == '0':
                print("{:.2f} {:.2f}0".format(k, round(tmp_n, 2)))
            else:
                print("{:.2f} {:.2f}".format(k, round(tmp_n, 2)))

            tmp_n = k * tmp_n * ((1000 - tmp_n) / 1000)
            tmp_n = max(0, tmp_n)
            i += 1
        k += 0.01

def main():
    if (len(sys.argv) == 4):
        calc_bombyx_2(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))
    elif (len(sys.argv) == 3):
        calc_bombyx(int(sys.argv[1]), float(sys.argv[2]))

def check_args():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        print("""USAGE
    ./106bombyx n [k | i0 i1]

DESCRIPTION
    n number of first generation individuals
    k growth rate from 1 to 4
    i0 initial generation (included)
    i1 final generation (included)""")
        exit(0)


if __name__ == "__main__":
    check_args()
    try :
        main()
    except:
        print("Error: invalid arguments, use -h for help", file=sys.stderr)
        sys.exit(84)
