echo "Enter the file name:"; read f 
if [ -f $f ]; then 
    c=$(wc -c < $f) 
    c=$((c - 1)) 
    w=$(wc -w < $f) 
    l=$(wc -l < $f) 
    echo "Number of characters: $c" 
    echo "Number of words: $w" 
    echo "Number of lines: $l" 
else 
    echo "File does not exist" 
fi 