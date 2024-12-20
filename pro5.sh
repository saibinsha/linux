echo "Enter the file name:"; read f 
echo "\nThe content of the file is:" 
cat $f 
echo "\nLines with exactly 2 characters:" 
grep '^..$' $f 
echo "\nLines with more than 2 spaces:" 
grep '  ' $f 