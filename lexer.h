#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_INT,
    TOKEN_IDENTIFIER,
    TOKEN_ASSIGN,
    TOKEN_SEMICOLON,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char value[64];  // Assuming token values can be stored as strings
} Token;

int tokenize(const char *filename, Token *tokens);

#endif // LEXER_H
