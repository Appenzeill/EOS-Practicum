#!/bin/bash

mkdir "Afbeeldingen"
if [ ! -d "Afbeeldingen" ]; then
  mkdir -p "Afbeeldingen";
fi

find $1 -iname '*.png' -exec mv '{}' Afbeeldingen \;
find $1 -iname '*.PNG' -exec mv '{}' Afbeeldingen \;
find $1 -iname '*.JPEG' -exec mv '{}' Afbeeldingen \;
find $1 -iname '*.jpeg' -exec mv '{}' Afbeeldingen \;
find $1 -iname '*.jpg' -exec mv '{}' Afbeeldingen \;
find $1 -iname '*.JPG' -exec mv '{}' Afbeeldingen \;
