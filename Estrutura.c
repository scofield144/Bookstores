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

struct users {
    int id;
    char userName[20];
    char password[20];
    Users* next;
  //  char name[20];
};
struct adm {
    char userName[20];
    char password[20];
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
    BSTNode* novoNo =(BSTNode*)malloc(sizeof(BSTNode));
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
    printf("Disponível: %d\n\n", (livro->disponivel) );
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

// Menu Configuration function

int checkAdm(Admin adm,char*pass,char*name){

    if(strstr(adm.userName,name) != NULL && strstr(adm.password,pass) != NULL) {
        return 1;
    }else{
        return 0;
    }
};
Users*criarAcount(Users*userList,char*userName,char*password){

    Users*newUser = (Users*)malloc(sizeof(Users));

    strcpy(newUser->password,password);
    strcpy(newUser->userName,userName);

    newUser->id = 1;
    newUser->next = NULL;

    if(userList == NULL) {
            userList = newUser;
    }else{
        while(userList->next != NULL){
            if(strstr(userList->password,newUser->password ) != NULL && strstr(userList->userName,newUser->userName) !=NULL) {
                break;
            }
            userList = userList->next;
            userList->id +=1;
        }
        if(userList->next == NULL) {
            userList->next = newUser;
        }else{
            return NULL;
        }
    }
    return userList;
};
int updatePassword(Users*user,char*newPassworld,char*pass,char*name) {

    Users*userList = user;

        while(userList != NULL){
            if(strstr(userList->password,pass) != NULL
                && strstr(userList->userName,name)) {
                strcpy(userList->password,newPassworld);
                return 1;
            }
            userList = userList->next;
    }
    return 0;
}
void loadFiles(){

};
int getID(Users* user) {
    Users*aux = user;
    if(aux == NULL) return 1;
    while(aux->next != NULL) {
        aux = aux->next;
    }
    return aux->id+1;   // return the next id
}

// Menu management function
int insertionBook(BST* bst,HashTable* hashTable, char*title,char*autor,int disponibility) {

     Livro books;

            strcpy(books.titulo ,title);
            strcpy(books.autor ,autor);
             books.disponivel = disponibility;

int sentinela=0;

        for(int i=0; i < MAX_LIVROS; i++ ){
                if(buscarLivroHashTable(hashTable,books.titulo) != NULL &&  strstr(hashTable->livros[i]->autor,books.autor)){
                    sentinela  =  1;
                    }
        }
        if(sentinela == 0 ){
                inserirLivro(bst, books);
                inserirLivroHashTable(hashTable, buscarLivro(bst, books.titulo));
                return 1;
        }
                sentinela = 0;

return -1;
};

int update(HashTable*hashTable,char*title,char*autor,int disponibility){
;
        int index = gerarHash(title);
        if(index != -1){
            strcpy(hashTable->livros[index]->titulo,title);
            strcpy(hashTable->livros[index]->autor,autor);
            hashTable->livros[index]->disponivel = disponibility;

            return 1;

        }else{
            return -1;
        }




};

int searchBook(HashTable* hashTable,char*title,char*autor){


    Livro*book = buscarLivroHashTable(hashTable,title);
    if(book != NULL && strstr(book->autor,autor) != NULL){
        imprimirLivro(book);
        return 1;
    }else{
            return -1;

    }
};

int delete(HashTable* hashTable,char*title){
system("clear");


    int index = gerarHash(title);

    if(index > -1){
            hashTable->livros[index] = NULL;
            return 1;
    }else{
        return -1;
    }
}

void showAll(HashTable* hashTable){

    // Iterate through the array in hashTable
    for(int i = 0; i < MAX_LIVROS; i++) {
        Livro* book = hashTable->livros[i];

        // Ensure that the current book is not NULL
        if(book != NULL) {
            printf("Titulo: %s\n", book->titulo);
            printf("Autor: %s\n", book->autor);
            printf("Quantidade: %d\n", book->disponivel);
            printf("------------------\n");
        }
    }
}

//******************************************************
void showIndisponibleBook(HashTable*hashTable) {

    for (int i = 0; i < MAX_LIVROS; i++) {
            Livro*book = hashTable->livros[i];
            if(book != NULL){
                if(book->disponivel < 1){
                    printf("Titulo: %s\n", book->titulo);
                     printf("Autor: %s\n", book->autor);
                     printf("Quantidade: %d\n", book->disponivel);
                    printf("------------------\n");
                }
            }
    }
}

int searchAutor(HashTable*hashTable,char*autor){
        int i = 0;
        HashTable*hash = hashTable;

        while(i < hash->tamanho){

                        if(strstr(hash->livros[i]->autor,autor) != NULL) {
                            return 1;
                        }
            i++;
        }
        return 0;
    }

// Menu login

int requestBook(HashTable*hash,char*title){

    int index = gerarHash(title);

    if( index > -1){
        if(hash->livros[index]->disponivel > 0){
            hash->livros[index]->disponivel -= 1;
            return 1;
        }
    }
        return -1;

};

int returnBook(HashTable*hash,char*title){

    int index = gerarHash(title);

    if( index > -1){
            hash->livros[index]->disponivel += 1;
            return 1;

    }else{
        return -1;
    }
};

int checkUser(Users*users,char*password,char*name) {
    Users* userList = users;

        while(userList != NULL){
            if(strstr(userList->password,password ) != NULL
                && strstr(userList->userName,name )) {
                return 1;
            }
            userList = userList->next;
    }
            return 0;
}

void showEntirative() {

}












