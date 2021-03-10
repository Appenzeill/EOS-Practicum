#!/usr/bin/env bash
for i in *.jpeg, *.JPEG; do
   convert $i -resize 128x128 ${i::-3}png
done
