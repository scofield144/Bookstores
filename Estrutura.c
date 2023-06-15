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
    int userCode;
    char password[20];
    Users* next;
  //  char name[20];
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

       printf("\nhashTable->livros[indice]: %s\n",hashTable->livros[indice]->titulo);

    hashTable->tamanho++;
}

Livro* buscarLivroHashTable(HashTable* hashTable, char* titulo) {
    // printf("buscarLivroHashTable - Titule: %s \n", titulo);
    int indice = gerarHash(titulo);
   // printf("\nhashTable->livros[indice]: %s\n",hashTable->livros[indice]->titulo);
    return hashTable->livros[indice];

}

// Menu Configuration function
void criarAcount(Users*users) {
    int code;
    char password[20];
    Users*userList = users;

    Users*newUser = (Users*)malloc(sizeof(Users));

    printf("CRIANDO CONTA DE USUARIO\n");

    printf("Digite o codigo: ");
    scanf("%d",&code);
    printf("Digite a senha: ");
    scanf("%s",password);


    strcpy(newUser->password,password);
    newUser->userCode = code;
    newUser->next = NULL;

    printf("DEBUG222");

    if(userList == NULL) {
            userList->next = newUser;
            userList->next = NULL;
    }else{
     printf("user code\n");

        while(userList != NULL){
            if(strstr(userList->password,newUser->password ) != NULL && userList->userCode == newUser->userCode) {
                break;
            }
             puts(userList->password);
            userList = userList->next;
        }
        if(userList == NULL) {
            userList = newUser;
            newUser->next = NULL;
        }else{
            printf("Dados inseridos já existem\n");
            criarAcount(users);
        }
    printf("CONTA CRIADA COM SUCESSO");
    }
};
void updatePassword(Users*user) {


    int code;
    char password[20];
    Users*userList = user;

    printf("\nALTERANDO A SENHA DO UTILIZADOR\n");

        printf("DEBUGANDO: %s ",userList->password);
    printf("Digite o codigo: ");
    scanf("%d",&code);
    printf("Digite a senha: ");
    scanf("%s",password);

/*
    if(userList == NULL) {
           printf("Não existe usuario!\n");
    }else{
        while(userList->next != NULL){
            if(strstr(userList->password,password ) != NULL && userList->userCode == code) {
                break;
            }
            userList = userList->next;
        }
        if(userList->next == NULL) {
            printf("Não existe este usuario!");
        }else{
            printf("Insere a nova senha");
            scanf("%s",password);
            strcpy(userList->password,password);
            printf("Senha actualizada");
        }
    printf("CONTA CRIADA COM SUCESSO");
    }*/
while(userList != NULL){

            if(strstr(userList->password,password ) != NULL && userList->userCode == code) {
                        printf("\nbefore: %s ",userList->password);
                 printf("Insere a nova senha");
            scanf("%s",password);
            strcpy(userList->password,password);
            printf("Senha actualizada");
            printf("\nbefore: %s ",userList->password);
                break;
            }
            userList = userList->next;
        }
        // if(userList->next == NULL) {
        //     printf("Não existe este usuario!\n");
        // }else{
        //     printf("Insere a nova senha");
        //     scanf("%s",password);
        //     strcpy(userList->password,password);
        //     printf("Senha actualizada");
        // }

    }
void loadFiles(){

};



// Menu management function
void insertionBook(BST* bst,HashTable* hashTable) {


    BST*bookList = bst;

     int quantityOfInsertionBook;
     char title[20],aut[20];
     int disponibility = 0;


     printf("Quantos livros deseja inserir: ");
     scanf("%d",&quantityOfInsertionBook);

     Livro livro[quantityOfInsertionBook];


     for(int index = 0; index < quantityOfInsertionBook;index++) {
        fflush(stdin);

             printf("Disponibilidade: ");
             scanf("%d",&disponibility);
        fflush(stdin);

             printf("Insere titulo: ");
             scanf("%s",title);
             printf("Insere Autor: ");
             scanf("%s",aut);
             printf("Finalizando o insertion");


            strcpy(livro[index].titulo ,title);
            strcpy(livro[index].autor ,aut);
             livro[index].disponivel = disponibility;



     }
;
int sentinela=0;
  for(int index = 0; index < quantityOfInsertionBook; index++) {

        for(int i=0; i < index; i++ ){
                if(buscarLivroHashTable(hashTable,livro[index].titulo) != NULL){
                    sentinela == 1;
                    printf("Não encontrado: %s\n", livro[index].titulo);
                }
        }

        if(sentinela == 0 ){
                inserirLivro(bst, livro[index]);
                inserirLivroHashTable(hashTable, buscarLivro(bst, livro[index].titulo));
                printf("\nInserido");
        }
                sentinela = 0;
}

};
void update(){

};
void searchBook(HashTable* hashTable){
    char title[20];

    printf("PESQUISANDO LIVRO\n");
    printf("Digite o titulo: ");
    scanf("%s",title);

    Livro*book = buscarLivroHashTable(hashTable,title);
    if(book != NULL){
        imprimirLivro(book);
    }else{
        printf("NOT FOUND");
    }
};
void delete(BST* bst,HashTable* hashTable){

    HashTable*hash = hashTable;
    HashTable*newhash = (HashTable*)malloc(sizeof(HashTable));
    Livro*livro ;
    char title[20];

    printf("ELIMINANDO LIVRO\n ");

    printf("Insere o nome do livro: ");
    scanf("%s",title);

    livro = buscarLivroHashTable(hash,title);
    if(livro != NULL){
        int index = gerarHash(title);

        if(index != -1){
            printf("viss: %s\nindex:  %d\nleng: %d",hash->livros[index]->titulo,index,hash->tamanho);
                if(index == hash->livros[index] ){
                            hash->livros[index] =  NULL;
                }else{
                    if(index < hash->tamanho){
                        livro = hash->livros[index];
                        hash->livros[index]  =  hash->livros[index+1];
                    }else{
                    printf("Não deletado\n");
                    return;
                    }
                }
            bst->root = deleteNode(bst->root, title);

                    printf("Livro removido com sucesso.\n");
            }
    }else{
               printf("Livro não removido com sucesso.\n");
    }
}
void showAll(HashTable* hashTable){
  printf("MOSTRANDO TODOS OS LIVROS\n");
for(int i = 0; i < hashTable->tamanho; i++) {
        if(hashTable->livros[i] != NULL) {
            imprimirLivro(hashTable->livros[i]);
        }
    }
    // HashTable* hash = hashTable;
    // printf("MOSTRANDO TODOS OS LIVROS\n");
    //
    //  Livro*book = buscarLivroHashTable(hashTable,hashTable->livros[1]->titulo);
    // // Livro*book = hashTable->livros[1]->titulo;
    // if(book != NULL){
    //     imprimirLivro(book);
    // }else{
    //     printf("NOT FOUND");
    // }
    // // imprimirLivro(hash->livros[2]->titulo);
    // for(int i=0; i< 3; i++) {
    //    // imprimirLivro(hash->livros[i]);
    //     printf("\n");
    //
    // }
}
void showIndisponibleBook() {

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
void requestBook(){

};
void returnBook(){

};

BSTNode* deleteNode(BSTNode* root, char* title) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(title, root->livro.titulo) < 0) {
        root->esq = deleteNode(root->esq, title);
    } else if (strcmp(title, root->livro.titulo) > 0) {
        root->dir = deleteNode(root->dir, title);
    } else {

        // Case 1: Node has no children or only one child
        if (root->esq == NULL) {
            BSTNode* temp = root->dir;
            free(root);
            return temp;
        } else if (root->dir == NULL) {
            BSTNode* temp = root->esq;
            free(root);
            return temp;
        }

        // Case 2: Node has two children
        BSTNode* temp = findMinimumNode(root->dir);
        root->livro = temp->livro;
        root->dir = deleteNode(root->dir, temp->livro.titulo);
    }

    return root;
}

BSTNode* findMinimumNode(BSTNode* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->esq != NULL) {
        root = root->esq;
    }

    return root;
}










