echo "Enter three file names:"; read f1 f2 f3 
cat $f1 $f2 $f3 > f5 
echo "Merged file created: f5" 
cat f5 