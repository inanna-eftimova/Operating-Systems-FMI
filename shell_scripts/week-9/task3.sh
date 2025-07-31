#!/bin/bash

if [ $# -lt 2 ]; then
  echo "Usage: $0 filename user1 [user2 ...]"
  exit 1
fi

file="$1"
shift
users=("$@")

if [ ! -f "$file" ]; then
  echo "File $file does not exist."
  exit 1
fi

echo "Enter message to send:"
read message

content=$(cat "$file")

for user in "${users[@]}"; do
  if who | grep -qw "^$user\b"; then
    echo -e "$message\n$content" | write "$user"
    echo "Message sent to $user"
  else
    echo "User $user is not logged in."
  fi
done
