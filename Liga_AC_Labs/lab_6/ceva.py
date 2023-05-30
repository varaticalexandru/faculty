import json


# dict = {
#     "name": "John",
#     "age": 30,
#     "departament": "logistics" 
# }

# file = open("data.json", "w")
# json.dump(dict, file)

# file.close()


# file = open("data.json", "r")
# print(json.load(file))

# file.close()

##

try:
    with open("empsda.json", "r") as file:
        print(file.read())
except:
    print("Fisierul nu poate fi accesat")

