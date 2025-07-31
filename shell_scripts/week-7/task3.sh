count=$(find . -maxdepth 1 -type f -perm 644 -printf "%f\n" | tee /dev/tty | wc -l)
echo "Number of files with permission 644: $count"
