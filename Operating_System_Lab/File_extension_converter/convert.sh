#!/bin/bash

source_dir="$HOME/tmp"

target_extension=".png"


for file in "$HOME/tmp"/*.jpg; do
    if [ -f "$file" ]; then
        
        filename=$(basename "$file" .jpg)
        
        
        mv "$file" "$HOME/tmp/$filename$target_extension"
        
        echo "Changed extension of $file to $filename$target_extension"
    fi
done

echo "Done!"

