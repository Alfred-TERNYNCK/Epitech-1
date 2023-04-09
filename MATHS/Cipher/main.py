import sys
import math

matric_key = []
matric_sentence = []
taille_n = 0
taille_k = 0

def encrypt(matric_key, matric_sentence):
    res2 = []
    for i in range(taille_k):
        res = []
        for k in range(taille_n):
            r = 0
            for j in range(taille_n):
                r += float(matric_sentence[i][j]) * float(matric_key[j][k])
            res.append(r)
        res2.append(res)
    return res2

def display(matrix, flag):
    print("Key matrix:")
    for i in range(len(matric_key)):
        for j in range(len(matric_key[0])):
            if flag == "0":
                space = "".join(" " for _ in range(8 - len(str(matric_key[i][j]))))
                str_print = str(int(matric_key[i][j]))
            else:
                str_print = str(round(matric_key[i][j], 3)) if str(round(matric_key[i][j], 3)) != "-0.0" else "0.0"
                space = "".join(" " for _ in range(8 - len(str_print)))
            print(str_print, end = space if not j + 1 == len(matric_key) else "\n")
    print("\nEncrypted message:")
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if flag == 0:
                print(int(matrix[i][j]), end = " " if not(i + 1 == len(matrix) and j + 1 == len(matrix[0])) else "\n")
            elif round(matrix[i][j]) != 0:
                print(chr(round(matrix[i][j])), end = "")
    print("") if flag == 1 else None

def check_args():
    if len(sys.argv) != 4:
        sys.stderr.write("Invalide Number of Arguments")
        exit(84)
    if sys.argv[3] not in ["0", "1"]:
        sys.stderr.write("last argument must be 0 or 1")
        exit(84)
    if sys.argv[3] == "1":
        for char in sys.argv[1].split(" "):
            if not char.isdigit():
                sys.stderr.write("sentence must be numbers")
                exit(84)
    if sys.argv[1].isascii() == False or sys.argv[2].isascii() == False:
        sys.stderr.write("sentence must be only ascii charactere")
        exit(84)

def transform_sentence(arg, matric_sentence, taille_n):
    global taille_k
    ascii_sentence = []
    for char in arg:
        ascii_sentence.append(ord(char))
    taille_k = math.ceil(len(ascii_sentence) / taille_n)
    for i in range(taille_k):
        matric_sentence.append(ascii_sentence[i * taille_n: i * taille_n + taille_n])
        if len(matric_sentence[i]) < taille_n:
            for j in range(taille_n - len(matric_sentence[i])):
                matric_sentence[i].append(0)
    return matric_sentence

def transform_key_into_ascii(arg, matric_key):
    global taille_n
    ascii_key = []
    for char in arg:
        ascii_key.append(ord(char))
    taille_n = math.ceil(math.sqrt(len(ascii_key)))
    for i in range(taille_n):
        matric_key.append(ascii_key[i * taille_n: i * taille_n + taille_n])
        if len(matric_key[i]) < taille_n:
            for j in range(taille_n - len(matric_key[i])):
                matric_key[i].append(0)
    return matric_key

def transform_encrypted_sentence(arg, matric_sentence, taille_n):
    global taille_k
    ascii_sentence = arg.split(" ")
    taille_k = math.ceil(len(ascii_sentence) / taille_n)
    for i in range(taille_k):
        matric_sentence.append(ascii_sentence[i * taille_n: i * taille_n + taille_n])
        if len(matric_sentence[i]) < taille_n:
            for j in range(taille_n - len(matric_sentence[i])):
                matric_sentence[i].append(0)
    return matric_sentence

def get_minor(m,i,j):
    return [row[:j] + row[j+1:] for row in (m[:i]+m[i+1:])]

def get_determinant(m):
    determinant = 0
    if len(m) == 2:
        return m[0][0]*m[1][1]-m[0][1]*m[1][0]
    for c in range(len(m)):
        determinant += ((-1)**c)*m[0][c]*get_determinant(get_minor(m,0,c))
    return determinant

def get_inverse(m):
    determinant = get_determinant(m)
    if len(m) == 2:
        return [[m[1][1]/determinant, -1*m[0][1]/determinant], [-1*m[1][0]/determinant, m[0][0]/determinant]]
    cofactors = []
    for r in range(len(m)):
        cofactorRow = []
        for c in range(len(m)):
            cofactorRow.append(((-1)**(r+c)) * get_determinant(get_minor(m,r,c)))
        cofactors.append(cofactorRow)
    cofactors = list(map(list,zip(*cofactors)))
    for r in range(len(cofactors)):
        for c in range(len(cofactors)):
            cofactors[r][c] = cofactors[r][c]/determinant
    return cofactors

def main():
    global matric_key, taille_n, matric_sentence
    if sys.argv[3] == "0":
        matric_key = transform_key_into_ascii(sys.argv[2], matric_key)
        matric_sentence = transform_sentence(sys.argv[1], matric_sentence, taille_n)
        display(encrypt(matric_key, matric_sentence), 0)
    if sys.argv[3] == "1":
        matric_key = transform_key_into_ascii(sys.argv[2], matric_key)
        matric_sentence = transform_encrypted_sentence(sys.argv[1], matric_sentence, taille_n)
        matric_key = get_inverse(matric_key)
        display(encrypt(matric_key, matric_sentence), 1)

if __name__ == "__main__":
    check_args()
    main()
