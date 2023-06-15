#include <stdio.h>
#include <stdlib.h>

#ifndef Arvore_Tad
#define Arvore_Tad

typedef struct livro Livro;
typedef struct bstNode BSTNode;
typedef struct bst BST;
typedef struct hashTable HashTable;

typedef struct users Users;
typedef struct adm Admin;

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










// Show menu of option
Admin  admin();
int checkAdm(Admin adm);
void menuStart(BST*bst,HashTable*hash,Users*users,Livro*livro);
void menuConfiguration(Users*users) ;
int search(HashTable*hashTable);
void menuManagement(BST* bst,HashTable* hashTable );
void menuUser(Users*users,HashTable* hashTable) ;

// Menu Start function
void configuration();
void management();
// void login(HashTable* hashTable);

// Menu Configuration function
Users*criarAcount(Users*users);
void updatePassword(Users*userList);
void loadFiles();


// Menu management function
void insertionBook(BST* bst,HashTable* hashTable);
void update(HashTable*hashTable);
void searchBook(HashTable* hashTable);
void delete(BST* bst,HashTable* hashTable);
void showAll(HashTable* hashTable);
void showIndisponibleBook(HashTable*hashTable);

 int searchAutor(HashTable*hashTable,char*autor);

// Menu login
 int checkLogin(Users*users);
void requestBook(HashTable*hash);
void returnBook(HashTable*hash);


Livro* hardSearchBook(HashTable* hashTable,int i);
BSTNode* deleteNode(BSTNode* root, char* title);
BSTNode* findMinimumNode(BSTNode* root) ;
#endif
