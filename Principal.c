#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Referencia.h"
#include "Estrutura.c"
#include <locale.h>

#define MAX_LIVROS 100
#define MAX_AUTORES 50

int main(){
	setlocale(LC_ALL, "Portuguese");
BST* bst = criarBST();
    HashTable* hashTable = criarHashTable();
    Users*users = (Users*)malloc(sizeof(Users));
    Livro livro [MAX_LIVROS];

    strcpy(livro[0].titulo ,"Livro1");
            strcpy(livro[0].autor ,"Autor 1");
             livro[0].disponivel = 2;

    strcpy(livro[1].titulo ,"Livro2");
            strcpy(livro[1].autor ,"Autor 2");
             livro[1].disponivel = 4;

    strcpy(livro[2].titulo ,"Livro3");
            strcpy(livro[2].autor ,"Autor 3");
             livro[2].disponivel = 4;

    strcpy(users->password,"abc1");
    users->userCode = 12;
     users->next = NULL;


    inserirLivro(bst, livro[0]);
    inserirLivro(bst, livro[1]);
    inserirLivro(bst, livro[2]);


    inserirLivroHashTable(hashTable, buscarLivro(bst, livro[0].titulo));
    inserirLivroHashTable(hashTable, buscarLivro(bst, livro[1].titulo));
    inserirLivroHashTable(hashTable, buscarLivro(bst, livro[2].titulo));

    menuStart(bst,hashTable,users,livro);

    return 0;
}

void menuStart(BST*bst,HashTable*hashTable,Users*users,Livro*book){


     int option = 0;
    printf("BEM VINDO A NOSSA LIVRARIA\n");
    printf("Escolha uma das opções:\n");
    printf("1 - Configurações\n");
    printf("2 - Gestão\n");
    printf("3 - Entrar\n:: ");
    scanf("%d",&option);

    if(option > 0 && option < 4) {
        switch(option) {
            case 0:
            case 1 : menuConfiguration(users);
                    break;
            case 2 : menuManagement(bst,hashTable);
                    break;
            case 3 : login(users,hashTable);
                    break;
            default: menuStart(bst,hashTable,users,book);
                break;
        }
    }else {
        menuStart(bst,hashTable,users,book);
        printf("error");
    }
   menuStart(bst,hashTable,users,book);
 free(bst);
    free(hashTable);
}
void menuConfiguration(Users*users) {
    int option;
    printf("CONFIGURAÇÕES DA LIVRARIA\n");
    printf(" Escolha uma das opções:\n ");
    printf("1 - Criar conta\n");
    printf("2 - Alterar senha\n");
    printf("3 - Carregar ficheiros\n:: ");
    scanf("%d",&option);

    if(option > 0 && option < 4) {
        switch(option) {
            case 1 : users = criarAcount(users);
                    break;
            case 2 : updatePassword(users);
                    break;
            case 3 : loadFiles();
                    break;
            default: menuConfiguration(users);
                break;
        }
    }else {
        menuConfiguration(users);
    }
}
void menuManagement(BST* bst,HashTable* hashTable ) {
    int option;
    printf("GESTÃO DA LIVRARIA\n");
    printf(" Escolha uma das opções:\n ");
    printf("1 - Inserir novo livro\n");
    printf("2 - Actualizar\n");
    printf("3 - Pesquisar\n");
    printf("4 - Eliminar\n");
    printf("5 - Listar todos\n");
    printf("6 - Livros indisponiveis\n");
    scanf("%d",&option);



    if(option > 0 && option < 7) {
        switch(option) {
            case 1 : insertionBook(bst,hashTable);
                    break;
            case 2 : update();
                    break;
            case 3 : searchBook(hashTable);
                    break;
            case 4 : delete(bst,hashTable);
                    break;
            case 5 : showAll(hashTable);
                    break;
            case 6 : showIndisponibleBook(hashTable);
                    break;
            default: menuManagement(bst,hashTable);
                break;
        }
    }else {
        menuManagement(bst,hashTable);
        printf("error");
    }

}

void login(Users*user,HashTable* hashTable) {
    int option;

 checkLogin(user);
    printf("Entrar\n");


    printf(" Escolha uma das opções:\n ");
    printf("1 - Pesquisar\n");
    printf("2 - Solicitar livro\n");
    printf("3 - Devolver livro\n");
    scanf("%d",&option);

    if(option > 0 && option < 4) {
        switch(option) {
            case 1 : searchBook(hashTable);
                    break;
            case 2 : requestBook(hashTable);
                    break;
            case 3 : returnBook(hashTable);
                    break;
            default: login(user,hashTable);
                break;
        }
    }else {
        login(user,hashTable);
        printf("error");
    }


}
