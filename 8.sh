

echo "Enter file1:"
read f1

if [ ! -d "$f1" ]; then
    echo "File '$f1' not found"
    exit 1
fi

ls -l "$f1"

