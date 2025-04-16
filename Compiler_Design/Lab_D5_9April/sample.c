int main() {
    int count;
    float total;
    count = 10;
    return 0;
}




// bison -d symbol_table.y
// flex symbol_table.l
// gcc lex.yy.c y.tab.c -o parser -lfl
// ./parser < sample.c


// # Step 1: Generate parser and header
// bison -d symbol_table.y

// # Step 2: Generate lexer
// flex symbol_table.l

// # Step 3: Compile with correct names
// gcc lex.yy.c symbol_table.tab.c -o parser -lfl

// # Step 4: Run with input file
// ./parser < sample.c