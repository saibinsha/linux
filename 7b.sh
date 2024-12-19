

echo "Enter file1:"
read f1

if [ ! -f "$f1" ]; then
    echo "File '$f1' not found"
    exit 1
fi

echo "Word count:"
wc -w "$f1"
echo "Line count:"
wc -l "$f1"
echo "Character count:"
wc -c "$f1"

