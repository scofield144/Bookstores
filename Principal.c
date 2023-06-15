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

    Admin adm = admin();
    int index = 0;

    do{

    int option = 0;
    printf("TIPO DE UTILIZADOR\n");

    printf("Escolha uma das opções:\n");
    printf("1 - Administrador\n");
    printf("2 - Socio\n");
    printf("3 - Encerrar\n:: ");

    scanf("%d",&option);

    if(option > 0 && option < 4) {
        switch(option) {
            case 1 :
                   if( checkAdm(adm) == 1){
                        menuStart(bst,hashTable,users,livro);
                }else{
                    printf("ERROR NO ADM");
                }
                    break;
            case 2 :
                    if(checkLogin(users) == 1){
                            menuUser(users,hashTable);
                    }else {
                    printf("ERROR NO SOCIO");
                    }
                    break;
            case 3: index=1;
                break;
            default:
                break;
        }
    }else {
        printf("Opção invalida\n");
    }

    }while(index != 1);
    free(bst);
    free(hashTable);
    return 0;
}
void menuStart(BST*bst,HashTable*hashTable,Users*users,Livro*book){

    int option = 0;

    printf("BEM VINDO A NOSSA LIVRARIA\n");

    printf("Escolha uma das opções:\n");
    printf("1 - Configurações\n");
    printf("2 - Gestão\n");
    printf("3- Sair\n:: ");
    scanf("%d",&option);

    if(option > 0 && option < 4) {
        switch(option) {
            case 0:
            case 1 : menuConfiguration(users);
                    break;
            case 2 : menuManagement(bst,hashTable);
                    break;
            case 3 :
                break;
            default: menuStart(bst,hashTable,users,book);
                break;
        }
    }else {
        menuStart(bst,hashTable,users,book);
        printf("Inserção invalida\n");
    }
}
void menuConfiguration(Users*users) {
    int option;
    printf("CONFIGURAÇÕES DA LIVRARIA\n");
    printf(" Escolha uma das opções:\n");
    printf("1 - Criar conta\n");
    printf("2 - Alterar senha\n");
    printf("3 - Carregar ficheiros\n");
    printf("4 - Sair\n:: ");

    scanf("%d",&option);

    if(option > 0 && option < 5) {
        switch(option) {
            case 1 : users = criarAcount(users);
                    break;
            case 2 : updatePassword(users);
                    break;
            case 3 : loadFiles();
                    break;
            case 4 :
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
    printf(" Escolha uma das opções:\n");
    printf("1 - Inserir novo livro\n");
    printf("2 - Actualizar\n");
    printf("3 - Pesquisar\n");
    printf("4 - Eliminar\n");
    printf("5 - Listar todos\n");
    printf("6 - Livros indisponiveis\n");

    printf("7 - Sair\n:: ");
    scanf("%d",&option);



    if(option > 0 && option < 8) {
        switch(option) {
            case 1 : insertionBook(bst,hashTable);
                    break;
            case 2 : update(hashTable);
                    break;
            case 3 : searchBook(hashTable);
                    break;
            case 4 : delete(bst,hashTable);
                    break;
            case 5 : showAll(hashTable);
                    break;
            case 6 : showIndisponibleBook(hashTable);
                    break;
            case 7 :
                    break;
            default: menuManagement(bst,hashTable);
                break;
        }
    }else {
        menuManagement(bst,hashTable);
        printf("Inserção invalida\n");
    }

}

void menuUser(Users*user,HashTable* hashTable) {
    int option;
    printf("Entrar\n");

    printf(" Escolha uma das opções:\n");
    printf("1 - Pesquisar\n");
    printf("2 - Solicitar livro\n");
    printf("3 - Devolver livro\n");
    printf("4 - Sair:: \n");
    scanf("%d",&option);

    if(option > 0 && option < 5) {
        switch(option) {
            case 1 : searchBook(hashTable);
                    break;
            case 2 : requestBook(hashTable);
                    break;
            case 3 : returnBook(hashTable);
                    break;
            case 4:
                    break;
            default: menuUser(user,hashTable);
                break;
        }
    }else {
        menuUser(user,hashTable);
        printf("Inserção invalida\n");
    }
}
