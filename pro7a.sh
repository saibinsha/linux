echo "Enter the file name:"; read f 
if [ -f $f ]; then 
    echo "Lines without vowels: $(grep -cv '[aeiou]' $f)" 
else 
    echo "File does not exist" 
fi 