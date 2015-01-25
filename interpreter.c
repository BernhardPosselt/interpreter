#include "interpreter.h"
#include <stdlib.h>

int symbols[26];
int subs[26];

int interpret(Node* node) {
    switch (node->type) {

    case N_STMT:
        interpret(node->left);
        interpret(node->middle);
        break;

    case N_IF:
        if (interpret(node->left)) {
            return interpret(node->middle);
        }
        return 0;

    case N_IF:
        if (interpret(node->left)) {
            return interpret(node->middle);
        } else {
            return interpret(node->right);
        }
        return 0;

    case N_INT:
        return node->value;

    case N_VARIABLE:
        return symbols[node->value];

    case N_EQUAL:
        return interpret(node->left) == interpret(node->middle);

    case N_ADDITION:
        return interpret(node->left) + interpret(node->middle);

    case N_SUBTRACTION:
        return interpret(node->left) - interpret(node->middle);

    case N_MULTIPLY:
        return interpret(node->left) * interpret(node->middle);

    case N_DIVIDE:
        return interpret(node->left) / interpret(node->middle);

    case N_MODULO:
        return interpret(node->left) % interpret(node->middle);

    case N_ASSIGNMENT:
        symbols[(int) node->left] = interpret(node->middle);
        return 0;

    case N_PRINT:
        printf("%d\n", interpret(node->left));
        return 0;

    default:
        printf("Unknown node type!\n", );
        return EXIT_FAILURE;
    }
}