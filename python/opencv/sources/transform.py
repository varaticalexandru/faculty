import numpy as np
import cv2 as cv
import os, sys

try:
    img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\fruits.jpg")
except:
    sys.exit("Could not read the file.")

# translation
def translate(img, x, y):
    transMat = np.float32([ [1,0,x], [0,1,y]])
    dimensions = (img.shape[1], img.shape[0] )

    return cv.warpAffine(img, transMat, dimensions)

# rotation
def rotate(img, angle, rot_point= None):
    (height, width) = img.shape[:2]
    dimensions = (width, height)

    if rot_point is None:
        rot_point = (width//2, height//2)

    rot_mat = cv.getRotationMatrix2D(rot_point, angle, 1.0)

    return cv.warpAffine(img, rot_mat, dimensions)

# resize/rescale
def rescale(img, scale):
    width = int(img.shape[1] * scale)
    height = int(img.shape[0] * scale)
    dimensions = (width, height)

    return cv.resize(img, dimensions, interpolation= cv.INTER_CUBIC)

# flipping
flipped = cv.flip(img, 1)

# cropping
cropped = img[100:500, 100:500]




translated = translate(img, -100, 100)
rotated = rotate(img, 45)


cv.imshow("translated", translated)
cv.imshow("rotated", rotated)
cv.imshow("flipped", flipped)
cv.imshow("cropped", cropped)
cv.waitKey(0)

print("Program done")