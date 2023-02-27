from cv2 import bitwise_and, bitwise_not, bitwise_or
import numpy as np
import cv2 as cv
import os, sys

os.system("cls")

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\cats.jpg")
except:
    sys.exit("Could not read the file.")

blank = np.zeros((400,400), dtype='uint8')

rectangle = cv.rectangle(blank.copy(), (30,30), (370,370), 255, -1)
circle = cv.circle(blank.copy(), (200,200), 200, 255, -1)

# bitwise AND
bit_and = cv.bitwise_and(rectangle, circle)

# bitwise OR
bit_or = cv.bitwise_or(rectangle, circle)

# bitwise XOR
bit_xor = cv.bitwise_xor(rectangle, circle)

# bitwise NOT
b_not = cv.bitwise_not(rectangle)


# cv.imshow("blank", blank)
cv.imshow("rectangle", rectangle)
cv.imshow("circle", circle)
cv.imshow("AND", bit_and)
cv.imshow("OR", bit_or)
cv.imshow("XOR", bit_xor)
cv.imshow("NOT", b_not)
cv.waitKey(0)

print("Program done")