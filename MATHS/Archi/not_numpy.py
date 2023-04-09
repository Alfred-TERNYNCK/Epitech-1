import math

class Notnumpy():

    def __init__(self, flag : list , x : int, y : int):
        self.help_achi="""USAGE
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
        self.flag = flag
        self.x = x
        self.y = y
        self.matrice_1 = [int(x),int(y), 1]
        self.matrice_2 = self.matrix_eye()
        self.matrice_res = None


    def matrix_eye(self):
        matrice=[[1, 0, 0],
                [0, 1, 0],
                [0, 0, 1]]
        return matrice


    def display(self):
        for i in self.matrice_2:
            c = 0
            for j in i:
                if round(j, 2) == 0:
                    j = 0
                print(f"""{j:.2f}{f"   {'' if j < 0 else ' '}" if c != 2 else ""}""", end='')
                c+=1
            print("")
        print(f"({self.x:.2f}, {self.y:.2f})", end='')
        print(" => ", end='')
        print(f"({float(self.matrice_res[0]):.2f}, {float(self.matrice_res[1]):.2f})")


    def multiply_matrix(self):
        """matrice_1 of size (3,1), matrice_2 of size (3,3)"""
        matrice_res = []
        for i in self.matrice_2:
            r = 0
            for j in range(3):
                r += i[j] * self.matrice_1[j]
            matrice_res.append(r)
        self.matrice_res = matrice_res


    def multiply_matrix_res(self, matrice):
        """multiplication between two matrices 3x3"""
        res2 = []
        for i_r in range(3):
            res = []
            for k in range(3):
                r = 0
                for i_c in range(3):
                    r += matrice[i_r][i_c] * self.matrice_2[i_c][k]
                res.append(r)
            res2.append(res)
        self.matrice_2 = res2


    def translation(self, i, j):
        matrice = self.matrix_eye()
        matrice[0][2] = i
        matrice[1][2] = j
        print(f"Translation along vector ({int(i)}, {int(j)})")
        self.multiply_matrix_res(matrice)


    def scaling(self, m, n):
        matrice = self.matrix_eye()
        matrice[0][0] = m
        matrice[1][1] = n
        print(f"Scaling by factors {int(m)} and {int(n)}")
        self.multiply_matrix_res(matrice)


    def rotation(self, d):
        matrice = self.matrix_eye()
        matrice[0][0] = math.cos(math.radians(d))
        matrice[0][1] = -math.sin(math.radians(d))
        matrice[1][0] = math.sin(math.radians(d))
        matrice[1][1] = math.cos(math.radians(d))
        print(f"Rotation by a {int(d)} degree angle")
        self.multiply_matrix_res(matrice)


    def reflection(self, d):
        matrice = self.matrix_eye()
        matrice[0][0] = math.cos(math.radians(d) * 2)
        matrice[0][1] = math.sin(math.radians(d) * 2)
        matrice[1][0] = math.sin(math.radians(d) * 2)
        matrice[1][1] = -math.cos(math.radians(d) * 2)
        print(f"Reflection over an axis with an inclination angle of {int(d)} degrees")
        self.multiply_matrix_res(matrice)
