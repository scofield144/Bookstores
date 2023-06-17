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
char password[20],userName[20];
    int code;


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
    users->id = 12;
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

                        printf("Fazer Login\n");
                        printf("Insere code: ");
                        scanf("%d",&code);
                        printf("Insere Senha: ");
                        scanf("%s",password);
                                        if( checkAdm(adm) == 1){
                                                menuStart(bst,hashTable,users,livro);
                                        }else{
                                        printf("ERROR NO ADM");
                        }
                    break;
            case 2 :

                    printf("FAZENDO LOGIN\n");
                    printf("Nome do utilzador: ");
                    scanf("%s",userName);
                    printf("Senha do utilizador: ");
                    scanf("%s",password);

                    if(checkLogin(users,password,userName) == 1){
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
        int idUser;
            char userName[20];
    char password[20];
    Users*userList = users;

    printf("CONFIGURAÇÕES DA LIVRARIA\n");
    printf(" Escolha uma das opções:\n");
    printf("1 - Criar conta\n");
    printf("2 - Alterar senha\n");
    printf("3 - Carregar ficheiros\n");
    printf("4 - Sair\n:: ");

    scanf("%d",&option);

    if(option > 0 && option < 5) {
        switch(option) {
            case 1 :
                    printf("CRIANDO CONTA\n");

                       printf("Nome de usuario: ");
                        scanf("%s",userName);
                        printf("Senha: ");
                        scanf("%s",password);
                        idUser = getID(users);


                    users = criarAcount(users,userName,password,idUser);
                    if(users != NULL) {
                         printf("CONTA CRIADDA\n");

                }else{
                         printf("Dados inseridos já existem\n");
                }
                    break;
            case 2 :

    printf("\nALTERANDO A SENHA DO UTILIZADOR\n");


                    updatePassword(users);
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
    int option,disponibility;
    char title[20],autor[20];
    int index = 0;
    Livro books[MAX_LIVROS];

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
                     int quantityOfBooks;



    if(option > 0 && option < 8) {
        switch(option) {
            case 1 :
                                printf("Quantos livros deseja inserir: ");
                                scanf("%d",&quantityOfBooks);

                        for(; index < quantityOfBooks;index++) {

                                        printf("Inserindo o %dº numero\n",index + 1);
                                        printf("Insere titulo: ");
                                        scanf("%s",title);
                                        printf("Insere Autor: ");
                                        scanf("%s",autor);
                                        fflush(stdin);

                                        printf("Disponibilidade: ");
                                        scanf("%d",&disponibility);

                                        if(insertionBook(bst,hashTable,title,autor,disponibility) == 1) {
                                                printf("INSERÇÃO COMPLETA\n");

                                        }else{
                                                        printf("INSERÇÃO NÃO FEITA\n");
                                        }
                }

                    break;
            case 2 :
                    printf(" ACTUALIZAÇÃO DE DADOS DE LIVRO\n");

                    printf("Insere o titulo: ");
                    scanf("%s",title);
                    printf("Insere nome do autor: ");
                    scanf("%s",autor);

                    if(searchBook(hashTable,title,autor) == 1){
                                printf("        Insere novos dados\n");

                                printf("Insere titulo: ");
                                scanf("%s",title);
                                printf("Insere Autor: ");
                                scanf("%s",autor);
                        fflush(stdin);
                                printf("Disponibilidade: ");
                                scanf("%d",&disponibility);

                                if(update(hashTable,title,autor,disponibility)==1){
                                                    printf("\n ACTUALIZAÇÃO COMPLETA \n");

                                }else{
                                                    printf(" NÃO ACTUALIZADO\n");
                                }
                }else
                            printf("NÃO ENCONTRADO\n");
                    break;
            case 3 :
                    printf("PESQUISAR LIVRO\n");
                    printf("Insere o titulo: ");
                    scanf("%s",title);
                    printf("Insere nome do autor: ");
                    scanf("%s",autor);

                    if(searchBook(hashTable,title,autor) == -1){
                            printf("NÃO ENCONTRADO\n");
                }

                    break;
            case 4 :
                printf("        ELIMINAR LIVRO\n");

                    printf("Insere o titulo: ");
                    scanf("%s",title);
                    printf("Insere nome do autor: ");
                    scanf("%s",autor);

                    if(searchBook(hashTable,title,autor) == -1){
                           if(delete(hashTable,title) == 1) {
                           printf("REMOVIDO\n");
                        }else{
                                          printf("NÃO REMOVIDO\n");
                        }
                }else
                            printf("NÃO ENCONTRADO\n");
                    break;
            case 5 :
                      printf("MOSTRANDO TODOS OS LIVROS\n");

                        if(hashTable == NULL || hashTable->tamanho == 0){
                        printf("Livraria fazia!\n");
                        }else{
                                showAll(hashTable);
                        }
                    break;
            case 6 :
                printf("LIVROS INDISPONÍVEIS\n");

                 showIndisponibleBook(hashTable);
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
    char title[20];
    char autor[20];

    printf("Entrar\n");

    printf(" Escolha uma das opções:\n");
    printf("1 - Pesquisar\n");
    printf("2 - Solicitar livro\n");
    printf("3 - Devolver livro\n");
    printf("4 - Sair:: \n");
    scanf("%d",&option);

    if(option > 0 && option < 5) {
        switch(option) {
            case 1 :
                        printf("        PESQUISANDO LIVRO\n");
                        printf("Digite o titulo: ");
                        scanf("%s",title);

                        if(searchBook(hashTable,title,autor)  == -1){
                                printf("Livro não encontrado\n");
                        }


                    break;
            case 2 :
                        printf("        SOLICITAÇÃO DE LIVRO\n");

                        printf("Titule: ");
                        scanf("%s",title);
                        if(requestBook(hashTable,title) == 1){
                                printf("SOLICITAÇÃO FEITA\n");

                        }else
                                printf("SOLICITAÇÃO NÃO FEITA\n");

                    break;
            case 3 :
                    printf("        DEVOLUÇÃO DE LIVRO\n");

                        printf("Titule: ");
                        scanf("%s",title);
                        if(returnBook(hashTable,title) == 1){
                                printf("DEVOLUÇÃO FEITA\n");

                        }else
                                printf("DEVOLUÇÃO NÃO FEITA\n");

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



/* ***************************************************************
int insertionBook(BST* bst,HashTable* hashTable,Livro*book,int quantity) {
int sentinela=0;
  for(int index = 0; index < quantity; index++) {

        for(int i=0; i < index; i++ ){// checking each book to know  if book already exist

            Livro*auxBook = buscarLivroHashTable(hashTable,book[index].titulo);
                    printf("DEBUUUUU\n");
                if( auxBook == NULL && strstr(auxBook->autor,book->autor) == NULL){
                    sentinela = 1;
                    }

        if(sentinela == 0 ){// book doesn't exist in the store
                inserirLivro(bst, book[index]);
                inserirLivroHashTable(hashTable, buscarLivro(bst, book[index].titulo));
                return 1;
        }
                sentinela = 0;
}
}
return -1;

}*/
