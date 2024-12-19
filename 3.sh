echo "Enter the list of file names"
read fn
set $fn
if [ $# -lt 2 ]
then
echo "Program needs at least 2 filenames"
exit;
fi
for str in `cat $1 | tr ' ' '\n' | sort | uniq`
do
echo "Words to be searched is $str"
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo "The number of occurrences in"
grep -c "$str" $*
done
