#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Usage: $0 username"
  exit 1
fi

user="$1"

while true; do
  if who | grep -qw "^$user\b"; then
    echo "User $user is logged in. Stopping check."
    break
  else
    echo "User $user not logged in yet."
  fi
  sleep 30
done
