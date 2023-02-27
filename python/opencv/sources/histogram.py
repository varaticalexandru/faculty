from cv2 import bitwise_and, bitwise_not, bitwise_or, circle
import numpy as np
import cv2 as cv
import os, sys
import matplotlib.pyplot as plt

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\cats.jpg")
except:
    sys.exit("Could not read the file.")

blank = np.zeros(img.shape[:2], dtype='uint8')
img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

mask = cv.circle(blank.copy(), (img.shape[1]//2, img.shape[0]//2), 100, 255, -1)
img_masked = cv.bitwise_and(img_gray, img_gray, mask=mask)

# # grayscale histogram
# gray_hist = cv.calcHist([img_gray], [0], mask, [256], [0,255])

# plt.figure()
# plt.title("Grayscale Histogram")
# plt.xlabel("Pixel intensity")
# plt.ylabel("# of pixels")
# plt.plot(gray_hist)
# plt.xlim([0,256])
# plt.show()

# colour histogram
colors = ('b', 'r', 'g')

for i, col in enumerate(colors):
    hist = cv.calcHist([img], [i], None, [256], [0, 255])
    plt.plot(hist, color=col)
    plt.xlim([0, 255])

plt.title("Colour Histogram")
plt.xlabel("Pixel intensity")
plt.ylabel("# of pixels")
plt.show()

cv.imshow("img", img)
# cv.imshow("img_grayscale", img_gray)
# cv.imshow("mask", mask)
# cv.imshow("img_masked", img_masked)
cv.waitKey(0)

print("Program done")