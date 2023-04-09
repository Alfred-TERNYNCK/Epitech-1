# pylint: disable-all

import os
import unittest

class TestArchitect(unittest.TestCase):
    def test_basic_test_t(self):
        str = "5 0 -t -1 1"
        str = os.popen(f"./102architect {str}").read()
        self.assertEqual(
            str,
            """Translation along vector (-1, 1)
1.00    0.00    -1.00
0.00    1.00    1.00
0.00    0.00    1.00
(5.00, 0.00) => (4.00, 1.00)
""")

    def test_basic_test_z(self):
        str =  "2 2 -z -1 1"
        str = os.popen(f"./102architect {str}").read()
        self.assertEqual(
            str,
            """Scaling by factors -1 and 1
-1.00   0.00    0.00
0.00    1.00    0.00
0.00    0.00    1.00
(2.00, 2.00) => (-2.00, 2.00)
""")

    def test_basic_test_r(self):
        str = "1 0 -r 90"
        str = os.popen(f"./102architect {str}").read()
        self.assertEqual(
            str,
            """Rotation by a 90 degree angle
0.00    -1.00   0.00
1.00    0.00    0.00
0.00    0.00    1.00
(1.00, 0.00) => (0.00, 1.00)
""")

    def test_basic_test_s(self):
        str = "3 -1 -s 270"
        str = os.popen(f"./102architect {str}").read()
        self.assertEqual(
            str,
            """Reflection over an axis with an inclination angle of 270 degrees
-1.00   0.00    0.00
0.00    1.00    0.00
0.00    0.00    1.00
(3.00, -1.00) => (-3.00, -1.00)
""")

    def test_complexe_test(self):
        str = "1 2 -t 2 3 -z 1 -2 -r 45 -s 30"
        str = os.popen(f"./102architect {str}").read()
        self.assertEqual(
            str,
            """Translation along vector (2, 3)
Scaling by factors 1 and -2
Rotation by a 45 degree angle
Reflection over an axis with an inclination angle of 30 degrees
0.97    -0.52   0.38
0.26    1.93    6.31
0.00    0.00    1.00
(1.00, 2.00) => (0.31, 10.44)
""")

    def test_robusteste(self):
        self.assertNotEqual(os.system("./102architect"), 0)
        self.assertNotEqual(os.system("./102architect 1 2"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -l 2 1"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -t 2 --"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -t r 2"), 0)
        self.assertNotEqual(os.system("./102architect 1 u -t 2 1"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -t 2 1 3"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -t 1"), 0)
        self.assertNotEqual(os.system("./102architect o 2 -t 2 1"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -z 2 j"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -z j 1"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -z 1"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -z 2 1 5"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -r"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -r 5 2"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -s"), 0)
        self.assertNotEqual(os.system("./102architect 1 2 -s 45 5"), 0)
