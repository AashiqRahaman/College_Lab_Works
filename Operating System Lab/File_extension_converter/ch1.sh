#!/bin/bash

# png to jpg

# for f in *.jpg; do mv -- "$f" "${f%.jpg}.png"; done


#  png to jpg

for f in *.png; do mv -- "$f" "${f%.png}.jpg"; done