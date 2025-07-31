#!/bin/bash

read -p "Enter first username: " user1
read -p "Enter second username: " user2

all_terminals=$(who | awk '{print $2}' | sort -u)
active_terminals=$(who | grep -E "^($user1|$user2) " | awk '{print $2}' | sort -u)

count=0

for term in $all_terminals; do
    if ! echo "$active_terminals" | grep -q "^$term$"; then
        count=$((count + 1))
    fi
done

echo "Number of terminals not used by $user1 or $user2: $count"
