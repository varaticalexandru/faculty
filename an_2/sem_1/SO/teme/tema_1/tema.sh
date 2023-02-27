#!/bin/bash
start=`date +%s`

PrintLines()
{
    echo -e "\n"Liniile ce contin cuvantul introdus:
    grep $2 $1
}

Menu()
{
    echo
    echo -e "Meniu Interactiv\n\n1: Iesire\n2: Afisare PID, SO, timp, cale"
    echo -e "3: Date calendaristice\n4: Shell-uri instalate\n5: Utilizatori"
    echo -e "6: Protocols\n7: Cpuinfo\n8: Proc\n9: Log\n\nIntroduceti optiunea:"
}

while :
do
    Menu
    read opt
    echo
    case $opt in
        1)
            exit 0;;
        2)
            echo PID: $$
            echo PWD: $PWD
            echo Tip OS: $OSTYPE
            #echo Tip OS: `uname -s`
            end=`date +%s`
            echo Timp executie script: `expr $end - $start` s;;

        3)
            echo Nr. saptamanii din an: `date +%U`
            echo Ziua saptamanii Craciunului: `date -d 25-Dec +%A`;;

        4)
            echo Primele 2 shell-uri:
            awk 'FNR==1 || FNR==2 || FNR==3 {print}' /etc/shells;;

        5)
            echo Toti utilizatorii de sistem:"\n"
            awk -F : '{print $1,$3,$5,$6}' /etc/passwd;;

        6)
            echo Ultimele linii incepand cu linia 9:"\n"
            tail -n -$((`wc -lc | /etc/protocols`-9+1)) /etc/protocols;;

        7)
            echo -e Tipul procesorului si marimea cache-ului:"\n"
            awk 'FNR==5 || FNR==9 {print}' /proc/cpuinfo;;

        8)
            echo -e Directoarele "<>" imaginea unui proces:"\n"
            ls /proc | grep [a-zA-Z];;
            
        9)
            echo -e Toate fisierele log:"\n"
            ls | grep \.log$ 
            echo -e "\n"Introduceti numele unui fisier de log:
            read logfile
            echo -e "\n"Introduceti un text:
            read text
            PrintLines $logfile $text;;
        *)
            echo Eroare. Optiune nedefinita;;
       
            
    esac
done
