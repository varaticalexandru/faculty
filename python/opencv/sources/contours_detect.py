import numpy as np
import cv2 as cv
import os, sys

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\cats.jpg")
except:
    sys.exit("Could not read the file.")

blank = np.zeros(img.shape, "uint8")
blank_ = np.zeros(img.shape, "uint8")

# convert 2 grayscale
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# blur
blur = cv.GaussianBlur(gray, (5,5), cv.BORDER_DEFAULT)

# canny edge detection
canny = cv.Canny(blur, 125, 175)

# threshold
ret, thresh = cv.threshold(gray, 125, 255, cv.THRESH_BINARY)



# find contours
contours, hierarchy = cv.findContours(thresh, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
print(f"{len(contours)} contours found (threshold)")

contours_canny, hierarchy_canny = cv.findContours(canny, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
print(f"{len(contours_canny)} contours found (canny)")

# draw contours
cv.drawContours(blank, contours, -1, (0,0,255), 1)
cv.drawContours(blank_, contours_canny, -1, (0,0,255), 1)

 


cv.imshow("img", img)
cv.imshow("gray", gray)
# cv.imshow("blur", blur)
# cv.imshow("canny", canny)
cv.imshow("threshold", thresh)
cv.imshow("blank (threshold contours)", blank)
cv.imshow("blank_ (canny contours)", blank_)
cv.waitKey(0)

print("Program done")