#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct AstNode {
    char type[20];           // Type of AST node
    char identifier[64];     // Variable or assignment identifier
    struct AstNode* children[2];  // For simplicity, assuming max 2 children
} AstNode;

AstNode* parse(Token *tokens, int num_tokens);

#endif // PARSER_H
