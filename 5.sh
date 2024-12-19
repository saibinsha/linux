echo "Enter a filename"
read f
echo "\nThe content of the file is:"
cat $f
echo "\nThe lines that have exactly 2 characters:"
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
grep "^.\{2\}$" $f
echo "\nThe lines that have more than 2 spaces:"
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
grep "[[:space:]]\{2,\}" $f
