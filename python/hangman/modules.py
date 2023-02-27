import os, sys, random_word, time

__version__ = '0.1'

# secret word
def secret_word():
    secret_word = str(random_word.RandomWords().get_random_word())
    guessed_word = "_" * len(secret_word)
    return (secret_word, guessed_word)

# top-cover
def cover():
    print("----------------------   H a n g m a n    G a m e   ----------------------\n")

# welcome to the game
def welcome():
    cover()
    name = input("Print your name: ")
    print(f"Hello, {name}. Best of luck !")
    time.sleep(2)
    os.system("cls")
    cover()
    print("The game is about to start !\nLet's play Hangman !")
    time.sleep(2)
    os.system("cls")

# get a valid letter from i/p
def get_letter():
    while True:
         c = str(input("\n\nTry a letter: "))[0]
         if c.isalpha():
            break

    return c


# print word (spaced between chars)
def print_word(word):
    word = str(word)
    for x in word:
        print(x, " ", end='')

# print hang dictionary (key: number of tries left[0..6])
hang_dict = {
    6:
        '''
           _____ 
          |     | 
          |     |
          |     |
          |      
          |      
          |      
        __|__'''
    ,
    5:
          '''
           _____ 
          |     |
          |     |
          |     |
          |     O
          |      
          |      
        __|__'''
    ,
    4:
        '''
           _____ 
          |     |
          |     |
          |     |
          |     O
          |     |
          |      
        __|__'''
    ,
    3:
        '''
           _____ 
          |     | 
          |     |
          |     | 
          |     O 
          |    /|  
          |        
        __|__'''
    ,
    2:
       '''
           _____ 
          |     |
          |     |
          |     | 
          |     O 
          |    /|\ 
          |        
        __|__'''
    ,
    1:
       '''
           _____ 
          |     | 
          |     |
          |     | 
          |     O 
          |    /|\ 
          |    /   
        __|__'''
    ,
    0:
        '''
           _____ 
          |     | 
          |     |
          |     | 
          |     O 
          |    /|\ 
          |    / \ 
        __|__'''
    ,
}


