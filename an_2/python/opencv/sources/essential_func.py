from cv2 import dilate, erode
import numpy as np
import cv2 as cv
import os, sys

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\fruits.jpg")
except:
    sys.exit("Could not read the file.")

# converting 2 grayscale
img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# blur (reduce noise)
img_blur = cv.GaussianBlur(img, (5,5), cv.BORDER_DEFAULT)

# edge cascade (detection)
canny = cv.Canny(img, 125, 175)
canny_blur = cv.Canny(img_blur, 125, 175)

# dilating (using a structuring element: canny edges)
dilated = cv.dilate(canny_blur, (3,3), iterations= 3)

# eroding (using a structuring element: dilated)
eroded = cv.erode(dilated, (3,3), iterations= 3)

# resize
resized = cv.resize(img, (1024,720), interpolation= cv.INTER_CUBIC)

# cropping
cropped = img[50:200, 200:400]

cv.imshow("img", img)
cv.imshow("gray img", img_gray) 
cv.imshow("blur", img_blur)
cv.imshow("canny", canny)
cv.imshow("canny blur", canny_blur)
cv.imshow("dilated", dilated)
cv.imshow("eroded", eroded)
cv.imshow("resized", resized)
cv.imshow("cropped", cropped)

cv.waitKey(0)

print("Program done")
