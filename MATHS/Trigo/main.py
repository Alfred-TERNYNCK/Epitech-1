import sys
import math

class Help(Exception):
    def __init__(self):
        pass

def matrix_eye(size):
    result = []
    for i in range(size):
        row = []
        for j in range(size):
            if i == j:
                row.append(1)
            else:
                row.append(0)
        result.append(row)
    return result

def power_of_matrix(matrix, power):
    result = matrix.copy()
    for _ in range(power - 1):
        result = matrix_multiply(result, matrix)
    return result

def matrix_add(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

def matrix_sub(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result

def matrix_multiply(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            value = 0
            for k in range(len(matrix2)):
                value += matrix1[i][k] * matrix2[k][j]
            row.append(value)
        result.append(row)
    return result

def matrix_div(matrix, value):
    result = []
    for i in range(len(matrix)):
        row = []
        for j in range(len(matrix[0])):
            row.append(matrix[i][j] / value)
        result.append(row)
    return result

def get_matrix(arg):
    lenmat = int(math.sqrt(len(arg)))
    matrix = []
    for i in range(lenmat):
        row = []
        for j in range(lenmat):
            row.append(float(arg[i * lenmat + j]))
        matrix.append(row)
    return matrix

def print_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            int_to_print = round(matrix[i][j], 2)
            endprint = " " * (10 - len(f"{int_to_print:.2f}")) if j != len(matrix[0]) - 1 else "\n"
            print(f"{int_to_print:.2f}", end=endprint)

def exp(matrix):
    result = matrix_eye(len(matrix))
    result = matrix_add(result, matrix)
    for i in range(2, 100):
        div = matrix_div(power_of_matrix(matrix, i), math.factorial(i))
        result = matrix_add(result, div)
    return result

def sin(matrix):
    result = matrix.copy()
    div = matrix_div(power_of_matrix(matrix, 3), math.factorial(3))
    result = matrix_sub(result, matrix_eye(len(matrix)))
    for i in range(5, 100, 2):
        div = matrix_div(power_of_matrix(matrix, i), math.factorial(i))
        result = matrix_add(result, div)
    return result

def cos(matrix):
    result = matrix_eye(len(matrix))
    div = matrix_div(power_of_matrix(matrix, 2), math.factorial(2))
    result = matrix_sub(result, div)
    for i in range(4, 100, 2):
        div = matrix_div(power_of_matrix(matrix, i), math.factorial(i))
        result = matrix_add(result, div)
    return result

def sinh(matrix):
    result = matrix.copy()
    for i in range(3, 100, 2):
        div = matrix_div(power_of_matrix(matrix, i), math.factorial(i))
        result = matrix_add(result, div)
    return result

def cosh(matrix):
    result = matrix_eye(len(matrix))
    for i in range(2, 100, 2):
        div = matrix_div(power_of_matrix(matrix, i), math.factorial(i))
        result = matrix_add(result, div)
    return result

def error_handling():
    try:
        for i in range(2, len(sys.argv)):
                float(sys.argv[i])
    except ValueError:
        print("Error: invalid matrix")
        raise SystemExit(84)
    if len(sys.argv) < 3:
        print("Error: not enough arguments")
        raise SystemExit(84)
    if sys.argv[1] not in ['EXP', 'SIN', 'COS', 'SINH', 'COSH']:
        print("Error: invalid function")
        raise SystemExit(84)
    if len(sys.argv) - 2 != int(math.sqrt(len(sys.argv) - 2)) ** 2:
        print("Error: invalid matrix")
        raise SystemExit(84)
    return 0

def main():
    if (len(sys.argv) == 2 and sys.argv[1] == '-h'):
        print("""USAGE :
    ./108trigo EXP | SIN | COS | SINH | COSH a1 a2 a3 ... an
...""")
        raise Help
    error_handling()
    matrix = get_matrix(sys.argv[2:])
    if sys.argv[1] == 'EXP':
        matrix = exp(matrix)
    if sys.argv[1] == 'SIN':
        matrix = sin(matrix)
    if sys.argv[1] == 'COS':
        matrix = cos(matrix)
    if sys.argv[1] == 'SINH':
        matrix = sinh(matrix)
    if sys.argv[1] == 'COSH':
        matrix = cosh(matrix)
    print_matrix(matrix)


if __name__ == '__main__':
    try :
        main()
    except Help:
        sys.exit(0)
    except :
        raise SystemExit(84)
