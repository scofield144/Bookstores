#include <stdio.h>
#include <stdlib.h>

#ifndef Arvore_Tad
#define Arvore_Tad

typedef struct livro Livro;
typedef struct bstNode BSTNode;
typedef struct bst BST;
typedef struct hashTable HashTable;

typedef struct users Users;

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
void insertion(BST* bst,HashTable* hashTable );










// Show menu of option

void menuStart();
void menuConfiguration(Users*users) ;
int search(HashTable*hashTable);
void menuManagement(BST* bst,HashTable* hashTable );
void login(HashTable* hashTable) ;

// Menu Start function
void configuration();
void management();
void login(HashTable* hashTable);

// Menu Configuration function
void criarAcount(Users*users);
void updatePassword(Users*userList);
void loadFiles();


// Menu management function
void insertionBook(BST* bst,HashTable* hashTable);
void update();
void searchBook(HashTable* hashTable);
void delete(BST* bst,HashTable* hashTable);
void showAll(HashTable* hashTable);
void showIndisponibleBook();

 int searchAutor(HashTable*hashTable,char*autor);

// Menu login
void requestBook();
void returnBook();



BSTNode* deleteNode(BSTNode* root, char* title);
BSTNode* findMinimumNode(BSTNode* root) ;
#endif
