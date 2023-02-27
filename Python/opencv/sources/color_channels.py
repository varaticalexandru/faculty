import numpy as np
import cv2 as cv
import os, sys

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\park.jpg")
except:
    sys.exit("Could not read the file.")


blank = np.zeros(img.shape[:2], dtype='uint8')

b, g, r = cv.split(img)
merged = cv.merge([b, g, r])
blue = cv.merge([b, blank, blank])
green = cv.merge([blank, g,blank])
red = cv.merge([blank, blank,r ])



cv.imshow("img", img)  
cv.imshow("b channel", b)
cv.imshow("g channel", g)
cv.imshow("r channel", r)
cv.imshow("merged", merged)
cv.imshow("blue", blue)
cv.imshow("red", red)
cv.imshow("green", green)
cv.waitKey(0)


print(img.shape)
print(b.shape)
print(g.shape)
print(r.shape)
print(merged.shape)

print("Program done")