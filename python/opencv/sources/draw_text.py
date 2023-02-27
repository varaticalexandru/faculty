from cv2 import FONT_HERSHEY_TRIPLEX
import numpy as np
import cv2 as cv
import os, sys

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\cat.jpg")
except:
    sys.exit("Could not read the image.")

blank = np.zeros((500, 500, 3), dtype= 'uint8')

# 1. paint the image a certain color
blank[200:300, 200:300] = (0, 0, 255)

# 2. draw a rectangle
cv.rectangle(blank, (100, 100), (400, 400), (0, 255, 0), thickness= 1)

# 3. draw a circle
cv.circle(blank, (blank.shape[1]//2, blank.shape[0]//2), 100, (0, 0, 255), thickness= 1)

# 4. draw a line
cv.line(blank, (0,0), (blank.shape[1], blank.shape[0]), (255, 0, 0), thickness= 1)
cv.line(blank, (blank.shape[1], 0), (0, blank.shape[0]), (255, 0, 0), thickness= 1)

# 5. write text
cv.putText(blank, "Zdarova", (180, 180), cv.FONT_HERSHEY_TRIPLEX, 1.0, (255, 255, 255), thickness= 2)

cv.imshow("window", blank)
cv.waitKey(0)


print("Program done")