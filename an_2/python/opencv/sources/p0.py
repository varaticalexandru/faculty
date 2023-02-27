import os, sys
import cv2 as cv

img = cv.imread(cv.samples.findFile(r"C:\Users\Admin\Downloads\images.png"))

if img is None:
    sys.exit("Could not read the image.")

cv.imshow("Display window", img)

k = cv.waitKey()

if k == ord("s"):
    print(cv.imwrite(r"D:\new.png", img))

print("Program done")