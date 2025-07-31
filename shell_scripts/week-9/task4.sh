#!/bin/bash

dir1="$1"
dir2="$2"
str="$3"

if [ -z "$str" ]; then
  if [ -f "/home/KN/student/f_niz" ]; then
    str=$(cat /home/KN/student/f_niz)
  else
    echo "String not provided and file /home/KN/student/f_niz not found."
    exit 1
  fi
fi

mkdir -p "$str"

# Move .с files to dir1
mv_count1=$(find . -maxdepth 1 -type f -name "*.с" -exec mv {} "$dir1" \; -print | wc -l)

# Move .out files to dir2
mv_count2=$(find . -maxdepth 1 -type f -name "*.out" -exec mv {} "$dir2" \; -print | wc -l)

# Count files not moved (.с or .out)
not_moved=$(find . -maxdepth 1 -type f \( -name "*.с" -o -name "*.out" \) | wc -l)

# Write transferred file names in names
{
  find "$dir1" -maxdepth 1 -type f -name "*.с" -printf "%f\n"
  find "$dir2" -maxdepth 1 -type f -name "*.out" -printf "%f\n"
} > "$str/names"

echo "Not transferred files count: $not_moved"
