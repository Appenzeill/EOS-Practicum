#!/usr/bin/env bash

# ooit gemakkelijk je eigen versie van de GNU/Linux copypasta willen maken?
# hier is je kans. geef een argument mee om Linux te veranderen naar keuze.
# voer het script uit met 1 of 2 argumenten. Bijvoorbeeld ./generateGNUpasta.sh NT Windows
# Zonder arguments zal de default copy pasta worden uitgevoerd.

ARGUMENT1=$1
ARGUMENT2=$2

touch "copypasta.txt"

if [ "$ARGUMENT1" == "" ]; then
    ARGUMENT1="GNU"
fi
if [ "$ARGUMENT2" == "" ]; then
    ARGUMENT2="Linux"
fi

echo "I’d just like to interject for a moment. What you’re refering to as $ARGUMENT2, is in fact, $ARGUMENT1/$ARGUMENT2, or as I’ve recently taken to calling it, $ARGUMENT1 plus $ARGUMENT2." >> copypasta.txt
echo "$ARGUMENT1 is not an operating system unto itself, but rather another free component of a fully functioning $ARGUMENT2 system made useful by the $ARGUMENT1 corelibs, shell utilities and vital system components comprising a full OS as defined by POSIX." >> copypasta.txt
echo "" >> copypasta.txt
echo "Many computer users run a modified version of the $ARGUMENT1 system every day, without realizing it." >> copypasta.txt
echo "Through a peculiar turn of events, the version of $ARGUMENT1 which is widely used today is often called $ARGUMENT2, and many of its users are not aware that it is basically the $ARGUMENT1 system, developed by the $ARGUMENT1 Project." >> copypasta.txt
echo "" >> copypasta.txt
echo "There really is a $ARGUMENT2, and these people are using it, but it is just a part of the system they use." >> copypasta.txt
echo "$ARGUMENT1 is the kernel: the program in the system that allocates the machine’s resources to the other programs that you run." >> copypasta.txt
echo "The kernel is an essential part of an operating system, but useless by itself; it can only function in the context of a complete operating system." >> copypasta.txt
echo "$ARGUMENT2 is normally used in combination with the $ARGUMENT1 operating system: the whole system is basically $ARGUMENT2 with $ARGUMENT1 added, or $ARGUMENT1/$ARGUMENT2." >> copypasta.txt
echo "All the so-called $ARGUMENT2 distributions are really distributions of $ARGUMENT1/$ARGUMENT2!" >> copypasta.txt
