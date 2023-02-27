from modules import *


failure_count = 6
no_letters_guessed = 0


os.system("cls")
welcome()
secret_word, guessed_word = secret_word()

cover()
print("This is your secret word:\n")
print_word(guessed_word)


while failure_count > 0:
    print(hang_dict[failure_count])
    letter = get_letter()

    if letter in secret_word:
        no_letters_guessed += 1
        print("You guessed it !")
        guessed_word = list(guessed_word)
        for i in range(len(secret_word)):
            if secret_word[i] == letter:
                guessed_word[i] = letter
        guessed_word = "".join(guessed_word)
    else:
        failure_count -= 1
        if failure_count == 0:
            break
        print(f"Oops, {failure_count} tries left")

    if no_letters_guessed == len(secret_word):
        time.sleep(2)
        os.system("cls")
        cover()
        print(hang_dict[failure_count])
        print("Grats, you won !\nThanks for playing!")
        print("The word was: ")
        print_word(secret_word)
        break

    time.sleep(2)
    os.system("cls")
    cover()
    print("Here's your word:\n")
    print_word(guessed_word)
    

if no_letters_guessed < len(secret_word):
        os.system("cls")
        cover()
        print(hang_dict[failure_count])
        print("Here's your word:\n")
        print_word(guessed_word)
        print("\nSorry, you lost !\nThe word was:\n")
        print_word(secret_word)

print("\n\nExiting . . .")