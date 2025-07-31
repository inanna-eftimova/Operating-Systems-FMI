#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Usage: $0 file1 [file2 ...]"
  exit 1
fi

read -p "Enter search string: " search

for file in "$@"; do
  if [ -f "$file" ]; then
    count=$(grep -c "$search" "$file")
    echo "File '$file' contains $count lines with '$search'"
  else
    echo "File '$file' does not exist."
  fi
done
