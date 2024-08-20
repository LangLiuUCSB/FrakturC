#include "MAST.h"

MASTnode *numNode(Nnum *n)
{
    MASTnode *newNode = (MASTnode *)malloc(sizeof(MASTnode));
    if (!newNode)
    {
        perror("Failed to allocate memory for numNode");
        exit(EXIT_FAILURE);
    }
    newNode->NodeType = 'n';
    newNode->data.num = n;
    return newNode;
}

MASTnode *bopNode(char tor, MASTnode *nd1, MASTnode *nd2)
{
    MASTnode *newNode = (MASTnode *)malloc(sizeof(MASTnode));
    if (!newNode)
    {
        perror("Failed to allocate memory for bopNode");
        exit(EXIT_FAILURE);
    }
    newNode->NodeType = 'b';
    newNode->data.bop = (struct bop){tor, nd1, nd2};
    return newNode;
}

MASTnode *uopNode(char tor, MASTnode *nd)
{
    MASTnode *newNode = (MASTnode *)malloc(sizeof(MASTnode));
    if (!newNode)
    {
        perror("Failed to allocate memory for uopNode");
        exit(EXIT_FAILURE);
    }
    newNode->NodeType = 'u';
    newNode->data.uop = (struct uop){tor, nd};
    return newNode;
}

void freeMASTtree(MASTnode *rootnode)
{
    if (rootnode)
    {
        if (rootnode->NodeType == 'n')
        {
            Nfree(rootnode->data.num);
            rootnode->data.num = NULL;
        }
        else if (rootnode->NodeType == 'b')
        {
            freeMASTtree(rootnode->data.bop.nd1);
            freeMASTtree(rootnode->data.bop.nd2);
        }
        else if (rootnode->NodeType == 'u')
        {
            freeMASTtree(rootnode->data.uop.nd);
        }
        free(rootnode);
        rootnode = NULL;
    }
}

void printMASTtree(MASTnode *rootnode) // TODO finish
{
    printf("Unfinished: void printMASTtree(MASTnode *rootnode)\n");
    (void)rootnode;
}
