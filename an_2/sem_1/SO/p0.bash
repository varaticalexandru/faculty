#!/bin/bash

Menu()
{
    echo -e "\n----------------------------"
    echo -e "\tMain Menu"
    echo "----------------------------"
    echo "[1] Data"
    echo "[2] Fisierele din directorul curent"
    echo "[3] Calendar"
    echo "[4] Start editor"
    echo "[5] Exit"
    echo "----------------------------"
    echo -n "Optiune [1-5]: "
}


clear

while :
do
    Menu
    read opt
    echo
    case $opt in
        1)
            date;;
        2)
            ls | cat;;
        3)
            cal;;
        4)
            nano;;
        5)
            exit 0;;
        *)
            echo -n "Eroare. Optiune nedefinita.";;            

    esac
done


