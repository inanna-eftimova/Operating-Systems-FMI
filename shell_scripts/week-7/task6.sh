#!/bin/bash

read -p "Enter first filename: " file1
read -p "Enter second filename: " file2
read -p "Enter third filename: " file3

> len
> size

for file in "$file1" "$file2" "$file3"; do
    echo "${#file}" >> len
    if [ -f "$file" ]; then
        stat --format=%s "$file" >> size
    else
        echo "0" >> size
    fi
done
