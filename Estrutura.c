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
struct adm {
    int code;
    char password[9];
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
    // printf("GERARHAS: %d\n",indice);
    return hashTable->livros[indice];
}


// Menu Configuration function
Admin admin(){

    int code;
    char password[20];
    Admin adm;
    // Admin*adm = (Admin*)malloc(sizeof(Admin));

    printf("CRIANDO CONTA DE ADMINISTRADOR\n");

    printf("Digite o codigo: ");
    scanf("%d",&code);
    printf("Digite a senha: ");
    scanf("%s",password);

    strcpy(adm.password,password);
    adm.code = code;
    return adm;
}
int checkAdm(Admin adm){
    int code;
    char password[9];
    printf("Fazer Login\n");

    printf("Insere code: ");
    scanf("%d",&code);
    printf("Insere Senha: ");
    scanf("%s",password);

    if(adm.code == code && strstr(adm.password,password) !=          NULL) {
        return 1;
    }else{
        return 0;
    }
};
Users* criarAcount(Users*users) {
    int code;
    char password[20];
    Users*userList = users;

    Users*newUser = (Users*)malloc(sizeof(Users));

    printf("CRIANDO CONTA\n");

    printf("Digite o codigo: ");
    scanf("%d",&code);
    printf("Digite a senha: ");
    scanf("%s",password);


    strcpy(newUser->password,password);
    newUser->userCode = code;
    newUser->next = NULL;

    if(userList == NULL) {
            userList->next = newUser;
    }else{

        while(userList != NULL){
            if(strstr(userList->password,newUser->password ) != NULL && userList->userCode == newUser->userCode) {
                break;
            }
            userList = userList->next;
        }
        if(userList == NULL) {
            userList = newUser;
        }else{
            printf("Dados inseridos já existem\n");
            criarAcount(users);
        }
    }
     users ->next = userList;
        puts(users->next->password);
        printf("\nCode: %d",users->next->userCode);
        userList->next = NULL;

    printf("\nCONTA CRIADA COM SUCESSO\n");
    return users;
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

             printf("Inserção - %d\n",index);
             printf("Insere titulo: ");
             scanf("%s",title);
             printf("Insere Autor: ");
             scanf("%s",aut);
        fflush(stdin);

             printf("Disponibilidade: ");
             scanf("%d",&disponibility);

            strcpy(livro[index].titulo ,title);
            strcpy(livro[index].autor ,aut);
             livro[index].disponivel = disponibility;

     }

int sentinela=0;
  for(int index = 0; index < quantityOfInsertionBook; index++) {

        for(int i=0; i < index; i++ ){
                if(buscarLivroHashTable(hashTable,livro[index].titulo) != NULL){
                    sentinela == 1;
                    }
        }
        if(sentinela == 0 ){
                inserirLivro(bst, livro[index]);
                inserirLivroHashTable(hashTable, buscarLivro(bst, livro[index].titulo));
                printf("\nINSERÇÃO COMPLETA");
        }
                sentinela = 0;
}

};
void update(HashTable*hashTable){
    int disponibility;
       char title[20],aut[20];
        printf("ACTUALIZAÇÃO DE DADOS DE LIVRO\n");
        printf("Insere titulo: ");
        scanf("%s",title);
        int index = gerarHash(title);
        // Livro*book = buscarLivroHashTable(hashTable,title);
        if(index != -1){
            printf("Titulo: %s\n", hashTable->livros[index]->titulo);
            printf("Autor: %s\n", hashTable->livros[index]->autor);
            printf("Disponibilidade: %d\n", hashTable->livros[index]->disponivel);
            printf("------------------\n");

            printf("Insere novos dados\n");
             printf("Insere titulo: ");
            scanf("%s",title);
            printf("Insere Autor: ");
             scanf("%s",aut);
        fflush(stdin);
             printf("Disponibilidade: ");
             scanf("%d",&disponibility);

            strcpy(hashTable->livros[index]->titulo,title);
            strcpy(hashTable->livros[index]->autor,aut);
            hashTable->livros[index]->disponivel = disponibility;

            printf("\nACTUALIZAÇÃO COMPLETA\n");

        }else{
            printf("Livro não encontrado");
        }




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
        printf("Livro não encontrado\n");
    }
};
void delete(BST* bst,HashTable* hashTable){
system("clear");

    HashTable*hash = hashTable;
    HashTable*newhash = (HashTable*)malloc(sizeof(HashTable));
    Livro*livro ;
    char title[20];

    printf("ELIMINAR LIVRO\n");

    printf("Nome do livro: ");
    scanf("%s",title);
    int index = gerarHash(title);

    livro = buscarLivroHashTable(hash,title);
    if(index > -1){

            printf("viss: %s\nindex:  %d\nleng: %d",hash->livros[index]->titulo,index,hash->tamanho);

            hashTable->livros[index] = NULL;

            printf("viss: %s\nindex:  %d\nleng: %d",hash->livros[index]->titulo,index,hash->tamanho);

            printf("Livro removido com sucesso.\n");

    }else{
               printf("Livro não removido com sucesso.\n");
    }
}
void showAll(HashTable* hashTable){

  printf("MOSTRANDO TODOS OS LIVROS\n");

      if(hashTable == NULL || hashTable->tamanho == 0){
        printf("The Hash Table is empty!\n");
        return;
    }

    printf("List of all books:\n");

    // Iterate through the array in hashTable
    for(int i = 0; i < MAX_LIVROS; i++) {
        Livro* book = hashTable->livros[i];

        // Ensure that the current book is not NULL
        if(book != NULL) {
            printf("Titulo: %s\n", book->titulo);
            printf("Autor: %s\n", book->autor);
            printf("Disponibilidade: %d\n", book->disponivel);
            printf("------------------\n");
        }
    }
}
//******************************************************
void showIndisponibleBook(HashTable*hashTable) {

    printf("LIVROS INDISPONÍVEIS\n");


    for (int i = 0; i < MAX_LIVROS; i++) {
            Livro*book = hashTable->livros[i];
            if(book != NULL){
                if(book->disponivel < 1){
                     printf("Titulo: %s\n", book->titulo);
                     printf("Autor: %s\n", book->autor);
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

void requestBook(HashTable*hash){
    char title[20];
    printf("SOLICITAÇÃO DE LIVRO\n");

    printf("Titule: ");
    scanf("%s",title);

    int index = gerarHash(title);

    if( index > -1){
        if(hash->livros[index]->disponivel > 0){
            hash->livros[index]->disponivel -= 1;
        printf("SOLICITAÇÃO FEITA\n");
            return;
        }
    }else{
        printf("NÃO SOLICITADO\n");
    }

};
void returnBook(HashTable*hash){
 char title[20];
    printf("SOLICITAÇÃO DE LIVRO\n");

    printf("Titule: ");
    scanf("%s",title);

    int index = gerarHash(title);

    if( index > -1){
            hash->livros[index]->disponivel += 1;
            printf("DEVOLUÇÃO FEITA\n");
            return;

    }else{
        printf(" DEVOLUÇÃO NÃO ACEITE\n");
    }
};

int checkLogin(Users*users) {
    Users* userList = users;
    char password[9];
    int code;

    printf("Fazer Login\n");
    printf("Insere code: ");
    scanf("%d",&code);
    printf("Insere Senha: ");
    scanf("%s",password);

        while(userList != NULL){
            if(strstr(userList->password,password ) != NULL
                && userList->userCode == code) {
                return 1;
            }
            userList = userList->next;
    }
            return 0;
}












