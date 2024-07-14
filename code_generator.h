#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "parser.h"

void generate_assembly(AstNode* node, char* assembly_code);

#endif // CODE_GENERATOR_H
