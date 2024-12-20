echo "Files in current directory:" 
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" 
ls -l 
  
echo "\n\nFiles having all permissions [r/w/x]:" 
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" 
  
for f in *; do 
    [ -f $f -a -r $f -a -w $f -a -x $f ] && ls -l $f 
done 