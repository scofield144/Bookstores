#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Referencia.h"

#define MAX_LIVROS 100
#define MAX_AUTORES 50

struct livro {
    char titulo[50];
    char autor[MAX_AUTORES];
    int disponivel;
};

struct bstNode {
    Livro livro;
    struct bstNode* esq;
    struct bstNode* dir;
};

struct bst{
    int count;
    BSTNode* root;
};

struct hashTable{
    int tamanho;
    Livro* livros[MAX_LIVROS];
}; 

BSTNode* criarNo(Livro livro) {
    BSTNode* novoNo = (BSTNode*)malloc(sizeof(BSTNode));
    novoNo->livro = livro;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

BST* criarBST() {
    BST* novaBST = (BST*)malloc(sizeof(BST));
    novaBST->count = 0;
    novaBST->root = NULL;
    return novaBST;
}

BSTNode* inserirNo(BSTNode* raiz, Livro livro) {
    if (raiz == NULL)
        return criarNo(livro);

    if (strcmp(livro.titulo, raiz->livro.titulo) < 0)
        raiz->esq = inserirNo(raiz->esq, livro);
    else
        raiz->dir = inserirNo(raiz->dir, livro);

    return raiz;
}

void inserirLivro(BST* bst, Livro livro) {
    bst->root = inserirNo(bst->root, livro);
    bst->count++;
}

BSTNode* buscarNo(BSTNode* raiz, char* titulo) {
    if (raiz == NULL || strcmp(raiz->livro.titulo, titulo) == 0)
        return raiz;

    if (strcmp(titulo, raiz->livro.titulo) < 0)
        return buscarNo(raiz->esq, titulo);
    else
        return buscarNo(raiz->dir, titulo);
}

Livro* buscarLivro(BST* bst, char* titulo) {
    BSTNode* no = buscarNo(bst->root, titulo);
    if (no == NULL)
        return NULL;
    else
        return &(no->livro);
}

void imprimirLivro(Livro* livro) {
    printf("Título: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Disponível: %s\n\n", (livro->disponivel) ? "Sim" : "Não");
}

void inorder(BSTNode* no) {
    if (no != NULL) {
        inorder(no->esq);
        imprimirLivro(&(no->livro));
        inorder(no->dir);
    }
}

int gerarHash(char* titulo) {
    int soma = 0, i = 0;
    for (i; i < strlen(titulo); i++) {
        soma += titulo[i];
    }
    return soma % MAX_LIVROS;
}

HashTable* criarHashTable() {
    int i = 0;
	HashTable* novaHashTable = (HashTable*)malloc(sizeof(HashTable));
    novaHashTable->tamanho = 0;
    for (i; i < MAX_LIVROS; i++) {
        novaHashTable->livros[i] = NULL;
    }
    return novaHashTable;
}

void inserirLivroHashTable(HashTable* hashTable, Livro* livro) {
    int indice = gerarHash(livro->titulo);
    hashTable->livros[indice] = livro;
    hashTable->tamanho++;
}

Livro* buscarLivroHashTable(HashTable* hashTable, char* titulo) {
    int indice = gerarHash(titulo);
    return hashTable->livros[indice];
}

