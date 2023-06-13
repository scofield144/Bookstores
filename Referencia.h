#include <stdio.h>
#include <stdlib.h>

#ifndef Arvore_Tad
#define Arvore_Tad

typedef struct livro Livro;
typedef struct bstNode BSTNode;
typedef struct bst BST;
typedef struct hashTable HashTable;

BSTNode* criarNo(Livro livro);
BST* criarBST();
BSTNode* inserirNo(BSTNode* raiz, Livro livro);
BSTNode* buscarNo(BSTNode* raiz, char* titulo);
Livro* buscarLivro(BST* bst, char* titulo);
void imprimirLivro(Livro* livro);
void inorder(BSTNode* no);
int gerarHash(char* titulo);
HashTable* criarHashTable();
void inserirLivroHashTable(HashTable* hashTable, Livro* livro);
Livro* buscarLivroHashTable(HashTable* hashTable, char* titulo);

#endif
