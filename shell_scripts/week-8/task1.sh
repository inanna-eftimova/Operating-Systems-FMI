#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Usage: $0 file1 file2"
  exit 1
fi

file1="$1"
file2="$2"

if [ ! -f "$file1" ] || [ ! -f "$file2" ]; then
  echo "Both files must exist."
  exit 1
fi

tmpfile=$(mktemp)

mv "$file1" "$tmpfile"
mv "$file2" "$file1"
mv "$tmpfile" "$file2"

echo "Files swapped: $file1 <-> $file2"
