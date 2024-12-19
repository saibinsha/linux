echo "Enter file1:"
read f1
if [ ! -f "$f1" ]; then
    echo "File '$f1' not found"
    exit 1
fi

echo "Enter file2:"
read f2
if [ ! -f "$f2" ]; then
    echo "File '$f2' not found"
    exit 1
fi

echo "Enter file3:"
read f3
if [ ! -f "$f3" ]; then
    echo "File '$f3' not found"
    exit 1
fi

cat "$f1" "$f2" "$f3" > f4
echo "Merged file is f4"

