#!/bin/bash

for file in *; do 
    if [ -f "$file" ]; then 
	if $2 $file ; then
	    echo "succes"
	else
	    echo "fail"
	    echo $file >> $3
	fi
    fi 
done
