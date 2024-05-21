#!/bin/bash
for filename in *.jpg; do 
  new_filename="${filename%.jpg}"
  if [ -e "${new_filename}.png" ]; then
    echo "WARNING: Skipping ${filename} as ${new_filename}.png already exists."
  else
    mv -- "$filename" "${new_filename}.png"
    echo "Converted ${filename} to ${new_filename}.png"
  fi
done
