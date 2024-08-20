#ifndef MAST_H
#define MAST_H

#include "utils.h"
#include "Nnum.h"

typedef struct MASTnode MASTnode;

struct MASTnode
{
    char NodeType;
    union
    {
        Nnum *num;
        struct bop
        {
            char tor;
            MASTnode *nd1;
            MASTnode *nd2;
        } bop;
        struct uop
        {
            char tor;
            MASTnode *nd;
        } uop;
    } data;
};

MASTnode *numNode(Nnum *n);
MASTnode *bopNode(char tor, MASTnode *nd1, MASTnode *nd2);
MASTnode *uopNode(char tor, MASTnode *nd);
void freeMASTtree(MASTnode *rootnode);
void printMASTtree(MASTnode *rootnode);

#endif
