from cProfile import label
import matplotlib.pyplot as plt
import numpy as np
import os, sys
import cv2 as cv

os.system("cls")
# face recognition model with built-in recognizer (train the recognizer)

dir = r"D:\UPT AC\Python\programs\opencv\resources\Faces\train"
haar_cascade = cv.CascadeClassifier(r"D:\UPT AC\Python\programs\opencv\sources\haarcascade_face.xml")

people = []
people = [x for x in os.listdir(dir)]

features = []
labels = []

def create_train():
    for person in people:
        path = os.path.join(dir, person)
        label = people.index(person)
    
        for file in os.listdir(path):
            img_path = os.path.join(path, file)

            img = cv.imread(img_path)
            img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
            faces_rect = haar_cascade.detectMultiScale(img_gray, scaleFactor=1.1, minNeighbors=3)
            
            for (x,y,w,h) in faces_rect:
                face_roi = img_gray[y:y+h, x:x+w]
                features.append(face_roi)
                labels.append(label)
                    
create_train()

features = np.array(features, dtype=object)
labels = np.array(labels)

face_recognizer = cv.face.LBPHFaceRecognizer_create()

# train the recognizer on features list & labels list
face_recognizer.train(features, labels)

np.save("features.npy", features)
np.save("labels.npy", labels)
face_recognizer.save("face_trained.yml")

print("\nProgram Done")
    