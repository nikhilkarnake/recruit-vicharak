#include "code_generator.h"
#include <stdio.h>
#include <string.h>

void generate_assembly(AstNode* node, char* assembly_code) {
    if (node == NULL) return;

    // Perform actions based on node type
    if (strcmp(node->type, "Program") == 0) {
        generate_assembly(node->children[0], assembly_code);  // Traverse statements
    } else if (strcmp(node->type, "VarDeclaration") == 0) {
        // Generate assembly for variable declaration (e.g., reserve memory)
        strcat(assembly_code, "RESERVE ");
        strcat(assembly_code, node->identifier);
        strcat(assembly_code, "\n");
    } else if (strcmp(node->type, "Assignment") == 0) {
        // Generate assembly for assignment (e.g., move values)
        strcat(assembly_code, "MOV ");
        strcat(assembly_code, node->identifier);
        strcat(assembly_code, ", ");
        strcat(assembly_code, node->children[0]->identifier);
        strcat(assembly_code, "\n");
    }

    // Recursively process children nodes
    generate_assembly(node->children[0], assembly_code);
    generate_assembly(node->children[1], assembly_code);
}
