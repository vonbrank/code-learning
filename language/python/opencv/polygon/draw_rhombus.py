import cv2
import time
import numpy as np
import os
import sys
import math



img = np.full((360, 640, 3), 0, np.uint8)


def draw_rhb(x1, y1, x2, y2, color, size):
    # if PO(s1) == (0.0, 0.0) or PO(s2) == (0.0, 0.0): return

    xC = int(3/4*x1 + 1/4*x2)
    yC = int(3/4*y1 + 1/4*y2)

    xD = int(3/4*x1 + 1/4*x2 + 1/3**0.5*(-1/4*y1 + 1/4*y2))
    yD = int(3/4*y1 + 1/4*y2 + 1/3**0.5*(1/4*x1 - 1/4*x2))

    xE = int(3/4*x1 + 1/4*x2 + 1/3**0.5*(1/4*y1 - 1/4*y2))
    yE = int(3/4*y1 + 1/4*y2 + 1/3**0.5*(-1/4*x1 + 1/4*x2))

    cv2.line(img, (x1, y1), (x2, y2), color, size)
    cv2.line(img, (x1, y1), (xD, yD), color, size)
    cv2.line(img, (x1, y1), (xE, yE), color, size)
    cv2.line(img, (x2, y2), (xD, yD), color, size)
    cv2.line(img, (x2, y2), (xE, yE), color, size)
    cv2.line(img, (xE, yE), (xD, yD), color, size)
    # cv2.line(img, x2, y2, color, size)

    # cv2.line(img, x3, y3, color, size)

draw_rhb(100, 100, 200, 200, (255,255,255), 3)

cv2.imshow("img", img)
cv2.waitKey()