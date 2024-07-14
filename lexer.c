#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

int tokenize(const char *filename, Token *tokens) {
    // Dummy implementation for example purposes
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return 0;
    }

    int index = 0;
    while (fscanf(file, "%s", tokens[index].value) != EOF) {
        tokens[index].type = TOKEN_IDENTIFIER; // Simplified for example
        index++;
    }

    fclose(file);
    return index;
}
