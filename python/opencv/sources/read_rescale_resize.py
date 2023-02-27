import cv2 as cv
import numpy as np
import os, sys

os.system("cls")

# rescale frame
def rescale_frame(frame, scale=0.75):
    # images, videos, live videos
    height = int(frame.shape[0] * scale)
    width = int(frame.shape[1] * scale)
    dimensions = (width, height)

    return cv.resize(frame, dimensions, interpolation= cv.INTER_AREA)

def change_res(width, height):
    # live video
    capture.set(3, width)
    capture.set(4, height)

# reading images
img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Photos\cat_large.jpg")
cv.imshow("Cat", img)
img_rescaled = rescale_frame(img, 0.5)
cv.imshow("Rescaled Image", img_rescaled)
if cv.waitKey(0) == ord("d"):
    cv.destroyAllWindows()

# reading videos
capture = cv.VideoCapture(r"D:\UPT AC\Python\programs\opencv\resources\Videos\dog.mp4")

while True:
    isTrue, frame = capture.read()
    if not isTrue:
        break

    frame_rescaled = rescale_frame(frame, scale= .2)

    cv.imshow('Video', frame)
    cv.imshow('Video Rescaled', frame_rescaled)
    
    if cv.waitKey(20) & 0xFF == ord('d'):
        break

capture.release()
cv.destroyAllWindows()

print("Program Done")