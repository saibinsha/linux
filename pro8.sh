echo "Enter directory name:"; read d 
if [ -d $d ]; then 
    echo "Files in $d:"; ls -l $d | grep '^-'  
else 
    echo "Invalid directory name." 
fi