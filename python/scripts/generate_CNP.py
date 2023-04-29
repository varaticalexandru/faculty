# importuri
import argparse, random, re, datetime, calendar, csv

# working datasets
S_ds = {1, 2, 5, 6, 7, 8, 9}    # 1,2: sec. XX || 5,6: sec. XXI || 7,8: rezidente || 9: cetateni straini
CNP_ref = [2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9]  # CNP de referinta

# functie generare CNP valid
def generate_CNP():

    CNP = ""

    S = str(list(S_ds)[random.randint(0, len(S_ds) - 1)])  # random S

    # random AA
    AA = str(random.randint(1800, datetime.datetime.now().year-1))[2:]

    # random LL
    aux = str(random.randint(1, 12))
    LL = aux if (len(aux) == 2) \
        else '0' + aux

    # random ZZ
    aux = str(random.randint(1, 31)) if LL in ['01', '03', '05', '07', '08', '10', '12'] \
        else str(random.randint(1, 30)) if LL in ['04', '06', '09', '11'] \
        else str(random.randint(1, 29)) if calendar.isleap(datetime.datetime.now().year) \
        else str(random.randint(1, 28))
    
    ZZ = aux if (len(aux) == 2) \
        else '0' + aux 

    # random JJ
    aux = str(random.randint(1, 52))
    JJ = aux if (len(aux) == 2) \
        else '0' + aux

    # random NNN
    aux = random.randint(1, 999)
    NNN = str(aux) if aux >= 100 else '0' + str(aux) if aux >= 10 else '00' + str(aux)
    
    CNP = S + AA + LL + ZZ + JJ + NNN # 12 cifre

    sum = 0

    for i in range(0, 12):
        sum += CNP_ref[i] * int(CNP[i])

    CNP += str(sum % 11) if sum % 11 < 10 else '1'  # ultima cifra (de control)

    return CNP
    
# functie verificare CNP valid
def is_valid(cnp):
    
    sum = 0

    for i in range(12):
        sum += int(cnp[i]) * int(CNP_ref[i])

    cifra_control = int(cnp[-1])

    condition_1 = bool(re.match("^[1256789]\\d{12}$", cnp))

    condition_2 = (cifra_control == 1) if sum % 11 == 10 else (cifra_control == sum % 11)

    return condition_1 and condition_2

# functie generare n CNP-uri valide & serializare in fisier CSV
def generate(n):


    with open('CNP.csv', 'w', newline='') as csvfile:

        writer = csv.writer(csvfile, delimiter=" ")

        for i in range(0, n):
                CNP = generate_CNP()
                #print(CNP, "Valid\n" if is_valid(CNP) else "Invalid\n")
                writer.writerow([CNP])


# functie main
if __name__ == "__main__":

    print()

    parser = argparse.ArgumentParser(description='Generate CNP')
    parser.add_argument('--number', type=int, default=1, help='numar de CNP-uri de generat')

    args = parser.parse_args()

    if args.number >= 1:
        generate(args.number)