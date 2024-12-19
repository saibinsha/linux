echo "enter file"
read fn
if [ ! -f "$fn" ]; then
echo "file not found"
else
tr 'a-z' 'A-Z' <"$fn"> output.txt
fi
