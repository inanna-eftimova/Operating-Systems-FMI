#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Usage: $0 dirname size"
  exit 1
fi

dir="$1"
size="$2"

if [ -d "$dir" ]; then
  find "$dir" -maxdepth 1 -type f -size +"${size}c" -printf "%f\n"
else
  echo "Directory '$dir' does not exist."
fi
