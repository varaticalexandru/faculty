from pickle import TRUE
from cv2 import rectangle
import numpy as np
import cv2 as cv
import os

os.system("cls")

haar_cascade = cv.CascadeClassifier(r"D:\UPT AC\Python\programs\opencv\sources\haarcascade_face.xml")
features = np.load(r"D:\UPT AC\Python\programs\opencv\sources\features.npy", allow_pickle=True)
labels = np.load(r"D:\UPT AC\Python\programs\opencv\sources\labels.npy", allow_pickle=True)
people = [x for x in os.listdir(r"D:\UPT AC\Python\programs\opencv\resources\Faces\train")]

face_recognizer = cv.face.LBPHFaceRecognizer_create()
face_recognizer.read(r"D:\UPT AC\Python\programs\opencv\sources\face_trained.yml")

img = cv.imread(r"D:\UPT AC\Python\programs\opencv\resources\Faces\val\madonna\3.jpg")
img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# detect the face in the image
faces_rect = haar_cascade.detectMultiScale(img_gray, 1.1, 4)
for (x,y,w,h) in faces_rect:
    roi = img_gray[y:y+h, x:x+w]
    label, confidence = face_recognizer.predict(roi)
    print(f"label = {people[label]}, confidence = {confidence}")
    cv.putText(img, str(people[label]), (20,20), cv.FONT_HERSHEY_COMPLEX, 1.1, (0,255,0), 2)
    cv.rectangle(img, (x,y), (x+w, y+h), (0,255,0), 2)

cv.imshow("Val img", img)
cv.waitKey(0)

print("\nProgram done")




