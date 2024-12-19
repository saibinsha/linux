#!/bin/bash

echo "Enter file1:"
read f1

if [ ! -f "$f1" ]; then
    echo "File '$f1' not found"
    exit 1
fi

grep -vi '[aeiou]' "$f1" | wc -l

