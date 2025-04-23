#!/bin/bash

echo "🛠️ Building using lex + yacc..."

yacc -d symbol_table.y || { echo "Yacc failed"; exit 1; }
lex symbol_table.l || { echo "Lex failed"; exit 1; }
gcc lex.yy.c y.tab.c -o parser -ll || { echo "GCC failed"; exit 1; }

echo "✅ Build successful."
echo "Run with: ./parser < sample.c"
