#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Usage: $0 directory username"
  exit 1
fi

dir="$1"
user="$2"

if [ ! -d "$dir" ]; then
  echo "Directory $dir does not exist."
  exit 1
fi

size=$(du -sb "$dir" | cut -f1)

if who | grep -qw "^$user\b"; then
  echo "User $user is logged in."
  echo "Total size of files in $dir: $size bytes" | write "$user"
else
  echo "User $user is not logged in."
fi
