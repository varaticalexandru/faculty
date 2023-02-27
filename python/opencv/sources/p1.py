import os, sys
import cv2 as cv
import numpy as np

os.system("cls")

try:
    img = cv.imread(cv.samples.findFile(r"D:\UPT AC\Python\programs\opencv\resources\Photos\fruits.jpg"))
except:
    sys.exit("Could not read the image.")

# convert BGR to LAB space
lab = cv.cvtColor(img, cv.COLOR_BGR2LAB)

# store the a-channel
a_channel = lab[:, :, 1]

# automate threshold using Otsu method
mask = cv.threshold(a_channel, 70, 255, cv.THRESH_BINARY_INV + cv.THRESH_OTSU)[1]


# mask the threshold with the original image
res = cv.bitwise_and(img, img, mask= mask)

cv.imshow("image", img)   
cv.imshow("mask", mask)
cv.imshow("result", res)

cv.waitKey(0) 



print("Program Done")