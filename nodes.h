#pragma once

typedef enum {
    N_EMPTY,
    N_ASSIGNMENT,
    N_INT,
    N_VARIABLE,
    N_ADDITION,
    N_SUBTRACTION,
    N_MULTIPLY,
    N_DIVIDE,
    N_MODULO,
    N_LOOP_BLOCK_FOR,
    N_LOOP_FOR_BLOCK,
    N_IF,
    N_IF_ELSE,
    N_SUB,
    N_CALL,
    N_PRINT,
    N_STMT,
    N_EQUAL,
    N_NOT,
    N_MINUS,
    N_RETURN,
    N_ARGUMENT,
    N_BINARY_OR,
    N_BINARY_AND
} NodeType;

typedef struct node {
    NodeType type;
    int value;
    struct node* left;
    struct node* middle;
    struct node* right;
} Node;


Node* create_node(NodeType type, Node* left, Node* middle, Node* right, int value);
