#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Usage: $0 filename search_string"
  exit 1
fi

filename="$1"
search="$2"

if [ ! -f "$filename" ]; then
  echo "File $filename does not exist."
  exit 1
fi

cp "$filename" "${filename}_copy1"
cp "$filename" "${filename}_copy2"
cp "$filename" "${filename}_copy3"

grep "$search" "$filename"
count=$(grep -c "$search" "$filename")

read -p "Enter output filename to save count: " outputfile
echo "$count" > "$outputfile"

target_dir="$HOME/../info"
mkdir -p "$target_dir"
mv "$outputfile" "$target_dir/"

echo "Count saved to $target_dir/$outputfile"
