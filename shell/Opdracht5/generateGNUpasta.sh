#!/usr/bin/env bash

# ooit gemakkelijk je eigen versie van de GNU/Linux copypasta willen maken?
# hier is je kans. geef een argument mee om Linux te veranderen naar keuze.
# Zonder arguments zal de default copy pasta worden uitgevoerd.

ARGUMENT1=$1
ARGUMENT2=$2

if [ "$ARGUMENT1" == "" ]; then
    ARGUMENT1="GNU"
fi
if [ "$ARGUMENT2" == "" ]; then
    ARGUMENT2="Linux"
fi

echo "I’d just like to interject for a moment. What you’re refering to as $ARGUMENT2, is in fact, $ARGUMENT1/$ARGUMENT2, or as I’ve recently taken to calling it, $ARGUMENT1 plus $ARGUMENT2."
echo "$ARGUMENT1 is not an operating system unto itself, but rather another free component of a fully functioning $ARGUMENT2 system made useful by the $ARGUMENT1 corelibs, shell utilities and vital system components comprising a full OS as defined by POSIX."
