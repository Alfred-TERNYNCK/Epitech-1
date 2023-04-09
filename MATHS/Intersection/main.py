import sys
import math

def cone(dc):
    alpha = math.radians(dc['p'])
    a = dc["xv"]**2 + dc["yv"]**2 - dc["zv"]**2*math.tan(alpha)**2
    b = 2 * (dc["xp"] * dc["xv"] + dc["yp"] * dc["yv"] - dc["zp"] * dc["zv"]*math.tan(alpha)**2)
    c = dc["xp"]**2 + dc["yp"]**2 - dc["zp"]**2*math.tan(alpha)**2
    delta = b**2 - 4 * a * c
    print(f"Cone with a {int(dc['p'])} degree angle")
    print('Line passing through the point ({}, {}, {}) and parallel to the vector ({}, {}, {})'.format(
        int(dc["xp"]),int(dc["yp"]),int(dc["zp"]),int(dc["xv"]),int(dc["yv"]),int(dc["zv"])))
    try :
        if delta < 0:
            print("No intersection point.")
        elif delta == 0:
            t = -b / (2 * a)
            print("1 intersection point:")
            print("({:.3f}, {:.3f}, {:.3f})".format(dc["xp"] + t * dc["xv"], dc["yp"] + t * dc["yv"], dc["zp"] + t * dc["zv"]))
        else:
            t1 = (-b - math.sqrt(delta)) / (2 * a)
            t2 = (-b + math.sqrt(delta)) / (2 * a)
            print("2 intersection points:")
            print("({:.3f}, {:.3f}, {:.3f})".format(dc["xp"] + t2 * dc["xv"], dc["yp"] + t2 * dc["yv"], dc["zp"] + t2 * dc["zv"]))
            print("({:.3f}, {:.3f}, {:.3f})".format(dc["xp"] + t1 * dc["xv"], dc["yp"] + t1 * dc["yv"], dc["zp"] + t1 * dc["zv"]))
    except:
        print("There is an infinite number of intersection points.")


def cylinder(dc):
    a = dc["xv"]**2 + dc["yv"]**2
    b = 2 * (dc["xp"] * dc["xv"] + dc["yp"] * dc["yv"])
    c = dc["xp"]**2 + dc["yp"]**2 - dc["p"]**2
    delta = b**2 - 4 * a * c
    print(f"Cylinder of radius {int(dc['p'])}")
    print('Line passing through the point ({}, {}, {}) and parallel to the vector ({}, {}, {})'.format(
        int(dc["xp"]),int(dc["yp"]),int(dc["zp"]),int(dc["xv"]),int(dc["yv"]),int(dc["zv"])))
    if delta < 0:
        print("No intersection point.")
    try :
        if delta == 0:
                t = -b / (2 * a)
                print("1 intersection point:")
                print("({:.3f}, {:.3f}, {:.3f})".format(dc["xp"] + t * dc["xv"], dc["yp"] + t * dc["yv"], dc["zp"] + t * dc["zv"]))
        else:
            t1 = (-b - math.sqrt(delta)) / (2 * a)
            t2 = (-b + math.sqrt(delta)) / (2 * a)
            print("2 intersection points:")
            print("({:.3f}, {:.3f}, {:.3f})".format(dc["xp"] + t2 * dc["xv"], dc["yp"] + t2 * dc["yv"], dc["zp"] + t2 * dc["zv"]))
            print("({:.3f}, {:.3f}, {:.3f})".format(dc["xp"] + t1 * dc["xv"], dc["yp"] + t1 * dc["yv"], dc["zp"] + t1 * dc["zv"]))
    except :
        print("There is an infinite number of intersection points.")


def sphere(dc):
    a = dc["xv"]**2 + dc["yv"]**2 + dc["zv"]**2
    b = 2 * (dc["xp"] * dc["xv"] + dc["yp"] * dc["yv"] + dc["zp"] * dc["zv"])
    c = dc["xp"]**2 + dc["yp"]**2 + dc["zp"]**2 - dc["p"]**2
    delta = b**2 - 4 * a * c
    print(f"Sphere of radius {int(dc['p'])}")
    print('Line passing through the point ({}, {}, {}) and parallel to the vector ({}, {}, {})'.format(
        int(dc["xp"]),int(dc["yp"]),int(dc["zp"]),int(dc["xv"]),int(dc["yv"]),int(dc["zv"])))
    try :
        if delta < 0:
            print("No intersection point.")
        elif delta == 0:
            t = -b / (2 * a)
            print("1 intersection point:")
            print("({:.3f}, {:.3f}, {:.3f})".format(dc["xp"] + t * dc["xv"], dc["yp"] + t * dc["yv"], dc["zp"] + t * dc["zv"]))
        else:
            t1 = (-b - math.sqrt(delta)) / (2 * a)
            t2 = (-b + math.sqrt(delta)) / (2 * a)
            print("2 intersection points:")
            print("({:.3f}, {:.3f}, {:.3f})".format(dc["xp"] + t2 * dc["xv"], dc["yp"] + t2 * dc["yv"], dc["zp"] + t2 * dc["zv"]))
            print("({:.3f}, {:.3f}, {:.3f})".format(dc["xp"] + t1 * dc["xv"], dc["yp"] + t1 * dc["yv"], dc["zp"] + t1 * dc["zv"]))
    except :
        print("There is an infinite number of intersection points.")


def init(dc):
    try :
        dc["opt"] = int(sys.argv[1])
        dc["xp"] = float(sys.argv[2])
        dc["yp"] = float(sys.argv[3])
        dc["zp"] = float(sys.argv[4])
        dc["xv"] = float(sys.argv[5])
        dc["yv"] = float(sys.argv[6])
        dc["zv"] = float(sys.argv[7])
        dc["p"] = float(sys.argv[8])
    except :
        print("Error: invalid arguments", file=sys.stderr)
        exit(84)
    if (dc["opt"] in [1, 2, 3] and dc["p"] <= 0) or (dc["opt"] == 3 and dc["p"] >= 90):
        print("Error: invalid arguments", file=sys.stderr)
        exit(84)
    if dc["xp"] == dc["xv"] and dc["yp"] == dc["yv"] and dc["zp"] == dc["zv"]:
        print("Error: Null direction vector", file=sys.stderr)
        exit(84)
    return dc


def main():
    dc = {}
    init(dc)
    if dc["opt"] not in [1, 2, 3]:
        print("Error: invalid option", file=sys.stderr)
        exit(84)
    try :
        if dc["opt"] == 1:
            sphere(dc)
        elif dc["opt"] == 2:
            cylinder(dc)
        elif dc["opt"] == 3:
            cone(dc)
    except :
        print("Error: invalid arguments", file=sys.stderr)
        exit(84)


def check_args():
    if len(sys.argv) == 1 or len(sys.argv) not in [9, 2] or (len(sys.argv) == 2 and sys.argv[1] != "-h"):
        print("Error: invalid arguments, use -h for help", file=sys.stderr)
        exit(84)
    if sys.argv[1] == "-h":
        print("""USAGE
    ./104intersection opt xp yp zp xv yv zv p

DESCRIPTION
    opt             surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone
    (xp, yp, zp)    coordinates of a point by which the light ray passes through
    (xv, yv, zv)    coordinates of a vector parallel to the light ray
    p               parameter: radius of the sphere, radius of the cylinder, or
                    angle formed by the cone and the Z-axis
""")
        sys.exit(0)


if __name__ == "__main__":
    check_args()
    main()
