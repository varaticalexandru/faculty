import numpy as np
import cv2 as cv
import os, sys

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\cats.jpg")
except:
    sys.exit("Could not read the file.")

# averaging
average = cv.blur(img, (7,7)) 

# gaussian
gaussian = cv.GaussianBlur(img, (7,7), 0)

# median
median = cv.medianBlur(img, 3)

# bilateral (retain edges)
bilateral = cv.bilateralFilter(img, 50, 100, 100)
 

cv.imshow("img", img)
cv.imshow("average", average)
cv.imshow("gaussian", gaussian)
cv.imshow("median", median)
cv.imshow("bilateral", bilateral)
cv.waitKey(0)

print("Program done")