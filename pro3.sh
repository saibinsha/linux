echo "Enter the list of file names"; read fn 
set $fn 
  
[ $# -lt 2 ] && { echo "Program needs at least 2 filenames"; exit 1; } 
  
for str in $(tr ' ' '\n' < $1 | sort -u); do 
    echo "Words to be searched is $str" 
    echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" 
    echo "The number of occurrences in" 
    grep -c "$str" $@ 
done 