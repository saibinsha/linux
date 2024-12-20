echo "Enter the list of file names:"; read fn 
set -- $fn 
  
[ $# -lt 1 ] && { echo "Program needs at least 1 filename"; exit 1; } 
  
for i; do 
    echo "\nAfter converting to uppercase file $i" 
    echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" 
    tr 'a-z' 'A-Z' < $i 
done 