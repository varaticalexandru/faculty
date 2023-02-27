from cv2 import bitwise_and, bitwise_not, bitwise_or, circle, threshold
import numpy as np
import cv2 as cv
import os, sys
import matplotlib.pyplot as plt

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\cats.jpg")
except:
    sys.exit("Could not read the file.")

img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY) 

# simple thresholding
threshold, thresh = cv.threshold(img_gray, 150, 255, cv.THRESH_BINARY)
threshold, thresh_inv = cv.threshold(img_gray, 150, 255, cv.THRESH_BINARY_INV)

# adaptive thresholding
adaptive_thresh = cv.adaptiveThreshold(img_gray, 255, cv.ADAPTIVE_THRESH_GAUSSIAN_C, cv.THRESH_BINARY, 11, 3)




cv.imshow("img", img)
cv.imshow("simple thresholded", thresh)
cv.imshow("simple thresholded inverse", thresh_inv)
cv.imshow("adaptive thresholded", adaptive_thresh)
cv.waitKey(0)

print("Program done")