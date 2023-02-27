import matplotlib.pyplot as plt
import numpy as np
import os, sys
import cv2 as cv

os.system("cls")

# face detection with trained classifiers (Haar Cascades)
haar_cascade = cv.CascadeClassifier(r"D:\UPT AC\Python\programs\opencv\sources\haarcascade_face.xml")
capture = cv.VideoCapture(0)
capture.set(cv.CAP_PROP_FPS, 10)

while True:

    isTrue, frame = capture.read()
    
    if cv.waitKey(20) & 0xFF == ord('d') or not isTrue:
        print("Video ended.")
        break
        
    frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    faces_rect = haar_cascade.detectMultiScale(frame_gray, scaleFactor=1.1, minNeighbors=3)

    print(f"Number of faces detected: {len(faces_rect)}")
    print(faces_rect) 

    for (x,y,w,h) in faces_rect:
        cv.rectangle(frame, (x,y), (x+w, y+h), (0,255,0), 2)

    cv.imshow("Video", frame)

capture.release()
cv.destroyAllWindows()

print("Program done")