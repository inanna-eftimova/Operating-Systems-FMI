#!/bin/bash

echo "Initial params: $@"
echo "Count: $#"

for file in "$@"; do
  if [ -f "$file" ]; then
    chmod +x "$file"
    echo "Made $file executable."
  else
    echo "File $file does not exist."
  fi
done

shift
shift

echo "After two shifts: $@"
echo "Count after shift: $#"
