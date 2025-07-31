count=$(find . -maxdepth 1 -type f -name "*.c" | wc -l)
echo "Number of C source files: $count"
