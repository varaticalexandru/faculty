from cv2 import bitwise_and, bitwise_not, bitwise_or
import numpy as np
import cv2 as cv
import os, sys

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\cats.jpg")
except:
    sys.exit("Could not read the file.")

blank = np.zeros(img.shape[:2], dtype='uint8')
mask = cv.circle(blank, (img.shape[1]//2+45,img.shape[0]//2), 100, 255, -1)

masked = cv.bitwise_and(img, img,mask=mask)

cv.imshow("img", img) 
cv.imshow("blank", blank)
cv.imshow("mask", mask)
cv.imshow("masked img", masked)
cv.waitKey(0)

print("Program done")