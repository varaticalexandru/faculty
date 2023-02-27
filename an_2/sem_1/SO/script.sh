echo "Introdu numele fisierului de loguri:"
read file


while :
do

echo "\nMeniu:\n0. Exit\n1. Hours \n2. Count"
echo "\nIntroduceti o optiune: "
read opt

case $opt in

    0)
        exit 0;;
    1)
        echo "Orele log-urilor:\n"
        awk '{print $2}' $file;;

    2) 
        echo "Introduceti un cuvant: "
        read str
        echo "Nr. de linii: "
        grep -c $str $file;;

    *) 
        echo "Eroare. Optiune nedefinita";;

esac

done
