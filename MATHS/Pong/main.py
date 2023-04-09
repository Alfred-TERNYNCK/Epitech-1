#!/usr/bin/python3

import sys
import math

params={}
help_str= """USAGE
    ./101pong x0 y0 z0 x1 y1 z1 n
DESCRIPTION
    x0 ball abscissa at time t - 1
    y0 ball ordinate at time t - 1
    z0 ball altitude at time t - 1
    x1 ball abscissa at time t
    y1 ball ordinate at time t
    z1 ball altitude at time t
    n time shift (greater than or equal to zero, integer)"""

def get_sys_params():
    params["x0"] = float(sys.argv[1])
    params["y0"] = float(sys.argv[2])
    params["z0"] = float(sys.argv[3])
    params["x1"] = float(sys.argv[4])
    params["y1"] = float(sys.argv[5])
    params["z1"] = float(sys.argv[6])
    params["n"]  = int(sys.argv[7])


def calculate_angle(n, v, z0, s):
    for _ in range(0, n + 1):
        if (z0 <= 0 and s == 1) or (z0 >= 0 and s == 0):
            vecteur = math.sqrt(math.pow(v[0], 2) + math.pow(v[1], 2) + math.pow(v[2], 2))
            return abs(90 - math.degrees(math.acos(v[2] / vecteur)))
        z0 += v[2]
    return "notr"


def main():
    try:
        if sys.argv[1] == "-h":
            print(help_str)
            return 0
        if int(sys.argv[7]) < 0:
            print("n must be a positive integer", file=sys.stderr)
            return 84
        if len(sys.argv) != 8:
            print("Invalid number of arguments", file=sys.stderr)
            return 84
        else:
            get_sys_params()
    except:
        sys.stderr.write("Invalid input parameters")
        return 84
    i = params["n"]
    vx = (params["x1"] - params["x0"])
    vy = (params["y1"] - params["y0"])
    vz = (params["z1"] - params["z0"])
    print(f"The velocity vector of the ball is:\n({vx:.2f}, {vy:.2f}, {vz:.2f})")
    print("At time t + {}, ball coordinates will be:\n({:.2f}, {:.2f}, {:.2f})".format(i, (params['x1']+vx*i), (params['y1']+vy*i), (params['z1']+vz*i)))
    angle = calculate_angle(i, [vx, vy, vz], params["z1"], 1 if vz >= 0 else 0)
    if angle == "notr":
        print("The ball won't reach the paddle.")
    else:
        print(f"The incidence angle is:\n{angle:.2f} degrees")
    return 0

if __name__ == "__main__":
    exit(main())
