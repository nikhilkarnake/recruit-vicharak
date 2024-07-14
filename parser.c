#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static Token current_token;
static int token_index = 0;
static Token* tokens;

void next_token() {
    current_token = tokens[token_index++];
}

int match(TokenType expected_type) {
    if (current_token.type == expected_type) {
        next_token();
        return 1;
    }
    return 0;
}

AstNode* parse_program();
AstNode* parse_statement();
AstNode* parse_variable_declaration();
AstNode* parse_assignment();

AstNode* parse_program() {
    AstNode* program = (AstNode*)malloc(sizeof(AstNode));
    strcpy(program->type, "Program");
    program->children[0] = parse_statement();
    return program;
}

AstNode* parse_statement() {
    if (match(TOKEN_INT)) {
        return parse_variable_declaration();
    } else if (current_token.type == TOKEN_IDENTIFIER) {
        return parse_assignment();
    } else {
        printf("Syntax error: Unexpected token %s\n", current_token.value);
        exit(1);
    }
}

AstNode* parse_variable_declaration() {
    AstNode* var_decl = (AstNode*)malloc(sizeof(AstNode));
    strcpy(var_decl->type, "VarDeclaration");
    strcpy(var_decl->identifier, current_token.value);
    match(TOKEN_IDENTIFIER);  // consume identifier
    match(TOKEN_SEMICOLON);   // consume ;
    var_decl->children[0] = NULL;
    var_decl->children[1] = NULL;
    return var_decl;
}

AstNode* parse_assignment() {
    AstNode* assign = (AstNode*)malloc(sizeof(AstNode));
    strcpy(assign->type, "Assignment");
    strcpy(assign->identifier, current_token.value);
    match(TOKEN_IDENTIFIER);  // consume identifier
    match(TOKEN_ASSIGN);      // consume =
    // Parse expression (not implemented in this example)
    match(TOKEN_SEMICOLON);   // consume ;
    assign->children[0] = NULL;
    assign->children[1] = NULL;
    return assign;
}

AstNode* parse(Token *token_list, int num_tokens) {
    tokens = token_list;
    token_index = 0;
    next_token();
    return parse_program();
}
