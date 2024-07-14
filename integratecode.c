#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"          // Include your lexer header file
#include "parser.h"         // Include your parser header file
#include "code_generator.h" // Include your code generator header file

#define MAX_TOKENS 100      // Define the maximum number of tokens
#define MAX_ASSEMBLY_CODE 1000 // Define the maximum size of assembly code buffer

int main() {
    // Tokenize SimpleLang program
    Token tokens[MAX_TOKENS];
    int num_tokens = tokenize("example.sl", tokens); // Example function for lexer

    // Parse tokens to AST
    AstNode* ast = parse(tokens, num_tokens); // Example function for parser

    // Generate assembly code from AST
    char assembly_code[MAX_ASSEMBLY_CODE] = {0};
    generate_assembly(ast, assembly_code); // Call the function with correct parameters

    // Print generated assembly code for verification
    printf("Generated Assembly Code:\n%s\n", assembly_code);

    // Optionally, write assembly_code to a file for further testing or execution

    return 0;
}
