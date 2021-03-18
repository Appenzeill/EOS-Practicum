#!/bin/bash

FILE=$1

if [ "$FILE" == "" ]; then
    echo "Geen file naam meegegeven"
    exit 1
fi

read -p "Enter Your Name: "  gebruikersnaam

if [ "$gebruikersnaam" != "" ]; then
    echo "Welkom $gebruikersnaam"
else
    echo "Welkom $(whoami)"
    gebruikersnaam="$(whoami)"
fi

while :
do
    read -p "Uw wachtwoord: " wachtwoord
    password_length=`expr length "$wachtwoord"`
    
    if [ ${password_length} -ge 8 ]; then
	read -p "Herhaal uw wachtwoord: " herhaald_wachtwoord
	if [ $herhaald_wachtwoord != "$wachtwoord" ]; then
	    echo "onjuist"
	else
	    break
	fi 
    else
	echo "Uw wachtwoord is te kort"
    fi
done

touch $FILE
echo -n "$gebruikersnaam " > $FILE
echo -n $wachtwoord | md5sum | awk '{print $1}' >> $FILE

