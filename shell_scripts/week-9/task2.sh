#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Usage: $0 dir1 dir2"
  exit 1
fi

dir1="$1"
dir2="$2"

count1=$(find "$dir1" -maxdepth 1 -type f -name "*.out" | wc -l)
count2=$(find "$dir2" -maxdepth 1 -type f -name "*.out" | wc -l)

if [ "$count1" -gt "$count2" ]; then
  read -p "Enter name for new subdirectory: " newdir
  mkdir -p "$newdir"

  find "$dir1" -maxdepth 1 -type f ! -perm -u=x -perm -u=rw -exec mv {} "$newdir" \;
  echo "Moved files to $newdir"
else
  echo "Number of .out files in $dir1 is not greater than in $dir2."
fi
