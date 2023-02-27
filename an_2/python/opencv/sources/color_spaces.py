import numpy as np
import cv2 as cv
import os, sys

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\park.jpg")
except:
    sys.exit("Could not read the file.")

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
lab = cv.cvtColor(img, cv.COLOR_BGR2LAB)


cv.imshow("img", img)
cv.imshow("grayscale", gray)
cv.imshow("hsv", hsv)
cv.imshow("lab", lab)
cv.waitKey(0)

print("Program done")