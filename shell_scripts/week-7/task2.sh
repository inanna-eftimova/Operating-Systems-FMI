count=$(ps -e | grep -w man | grep -v grep | wc -l)
echo "Number of 'man' processes: $count"
