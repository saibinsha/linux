echo "Enter the first and second filenames:"; read f1 f2 
if [ -f $f1 ] && [ -f $f2 ]; then 
    if cmp -s $f1 $f2; then 
        rm $f2 
        echo "Files are the same. $f2 deleted." 
    else 
        echo "Files are different. $f2 not deleted." 
    fi 
else 
    echo "Input should be regular files." 
fi 