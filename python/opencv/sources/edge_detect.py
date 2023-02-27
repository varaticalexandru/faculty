import numpy as np
import cv2 as cv
import os, sys
import matplotlib.pyplot as plt

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\park.jpg")
except:
    sys.exit("Could not read the file.")

img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)


# Canny (edge detector) ...

# Laplacian (edge detector)
lap = cv.Laplacian(img_gray, cv.CV_64F)
lap = np.uint8(np.absolute(lap))

# Sobel (gradient magnitude representation)
sobel_x = cv.Sobel(img_gray, cv.CV_64F, 1, 0)
sobel_y = cv.Sobel(img_gray, cv.CV_64F, 0, 1)
combined_sobel = cv.bitwise_or(sobel_x, sobel_y)
 
cv.imshow("img", img)
cv.imshow("img_gray", img_gray)
cv.imshow("img_lap", lap)
cv.imshow("Sobel combined", combined_sobel)

cv.waitKey(0)

print("Program done")