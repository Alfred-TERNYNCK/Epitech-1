#!/usr/bin/python3

import sys
from not_numpy import Notnumpy

flag = {
    '-t': False,
    '-z': False,
    '-r': False,
    '-s': False,
}

str_h = """USAGE
    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...

DESCRIPTION
    x   abscissa of the original point
    y   ordinate of the original point

    transfo arg1 [arg2]
    -t i j  translation along vector (i, j)
    -z m n  scaling by factors m (x-axis) and n (y-axis)
    -r d    rotation centered in O by a d degree angle
    -s d    reflection over the axis passing through O with an inclination
            angle of d degrees"""

def is_num(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

def valide_params(av):
    if len(av) < 5:
        exit(84)
    if is_num(av[1]) == False or is_num(av[2]) == False:
        exit(84)
    for i in range(1, len(av)):
        if av[i] != '-t' and av[i] != '-z' and av[i] != '-r' and av[i] != '-s' and is_num(av[i]) == False:
            exit(84)
        if av[i] == '-t':
            if len(av) < i + 3:
                exit(84)
            if is_num(av[i + 1]) == False or is_num(av[i + 2]) == False:
                exit(84)
            if len(av) > i + 3:
                if av[i + 3] != '-z' and av[i + 3] != '-r' and av[i + 3] != '-s':
                    exit(84)
        elif av[i] == '-z':
            if len(av) < i + 3:
                exit(84)
            if is_num(av[i + 1]) == False or is_num(av[i + 2]) == False:
                exit(84)
            if len(av) > i + 3:
                if av[i + 3] != '-t' and av[i + 3] != '-r' and av[i + 3] != '-s':
                    exit(84)
        elif av[i] == '-r':
            if len(av) < i + 2:
                exit(84)
            if is_num(av[i + 1]) == False:
                exit(84)
            if len(av) > i + 2:
                if av[i + 2] != '-t' and av[i + 2] != '-z' and av[i + 2] != '-s':
                    exit(84)
        elif av[i] == '-s':
            if len(av) < i + 2:
                exit(84)
            if is_num(av[i + 1]) == False:
                exit(84)
            if len(av) > i + 2:
                if av[i + 2] != '-t' and av[i + 2] != '-z' and av[i + 2] != '-r':
                    exit(84)


def append_params_to_list(av, matrice):
    global flag
    flag['x'] = int(av[1])
    flag['y'] = int(av[2])
    for i in range(1, len(av)):
        if av[i] == '-t':
            matrice.translation(float(av[i + 1]), float(av[i + 2]))
        elif av[i] == '-z':
            matrice.scaling(float(av[i + 1]), float(av[i + 2]))
        elif av[i] == '-r':
            matrice.rotation(float(av[i + 1]))
        elif av[i] == '-s':
            matrice.reflection(float(av[i + 1]))


def main():
    av = sys.argv
    if len(av) == 2 and av[1] == '-h':
        print(str_h)
        exit(0)
    valide_params(av)
    try :
        matrice = Notnumpy(flag, int(av[1]), int(av[2]))
        append_params_to_list(av, matrice)
        matrice.multiply_matrix()
        matrice.display()
    except:
        exit(84)


if __name__ == "__main__":
    main()
    exit(0)
