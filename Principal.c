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
/*
    BST* bst = criarBST();
    HashTable* hashTable = criarHashTable();
        Users*users;*/



/*
    if(option > 0 && option < 5) {

        switch(option) {
            case 1 : insertion(bst,hashTable);
                    break;
            case 2 : search(hashTable);
                    break;
            case 3 : break;
            case 4:  break;
            case 5 : break;
            default:break;
        }
    }else {
        printf("error");
    }*/
    menuStart();


    // BST* bst = criarBST();
    // HashTable* hashTable = criarHashTable();
    // Users*users = (Users*)malloc(sizeof(Users));
    //
    // Livro livro1 = {"Livro1", "Autor 1", 1};
    // Livro livro2 = {"Livro2", "Autor 2", 1};
    // Livro livro3 = {"Livro3", "Autor 3", 0};
    //
    // strcpy(users->password,"abc1");
    // users->userCode = 12;
    // users->next = NULL;

/*
    inserirLivro(bst, livro1);
    inserirLivro(bst, livro2);
    inserirLivro(bst, livro3);

    inserirLivroHashTable(hashTable, buscarLivro(bst, livro1.titulo));
    inserirLivroHashTable(hashTable, buscarLivro(bst, livro2.titulo));
    // inserirLivroHashTable(hashTable, buscarLivro(bst, livro3.titulo));*/

    //  int option = 0;
    // printf("BEM VINDO A NOSSA LIVRARIA\n");
    // printf("Escolha uma das opções:\n");
    // printf("1 - Configurações\n");
    // printf("2 - Gestão\n");
    // printf("3 - Entrar\n");
    // scanf("%d",&option);
/*
    if(option > 0 && option < 4) {
        switch(option) {
            case 1 : menuConfiguration(users);
                    break;
            case 2 : menuManagement(bst,hashTable);
                    break;
            case 3 : login(hashTable);
                    break;
            default: main();
                break;
        }
    }else {
        main();
        printf("error");
    }*/
 // free(bst);
 //    free(hashTable);
 //  //  search(hashTable);


    return 0;
}

void menuStart() {
    BST* bst = criarBST();
    HashTable* hashTable = criarHashTable();
    Users*users = (Users*)malloc(sizeof(Users));

    Livro livro1 = {"Livro1", "Autor 1", 1};
    Livro livro2 = {"Livro2", "Autor 2", 1};
    Livro livro3 = {"Livro3", "Autor 3", 0};

    strcpy(users->password,"abc1");
    users->userCode = 12;
     users->next = NULL;


    inserirLivro(bst, livro1);
    inserirLivro(bst, livro2);
    inserirLivro(bst, livro3);


    inserirLivroHashTable(hashTable, buscarLivro(bst, livro1.titulo));
    inserirLivroHashTable(hashTable, buscarLivro(bst, livro2.titulo));
    inserirLivroHashTable(hashTable, buscarLivro(bst, livro3.titulo));

     int option = 0;
    printf("BEM VINDO A NOSSA LIVRARIA\n");
    printf("Escolha uma das opções:\n");
    printf("1 - Configurações\n");
    printf("2 - Gestão\n");
    printf("3 - Entrar\n:: ");
    scanf("%d",&option);/*

  printf("Tamanho: %d\n",hashTable->tamanho);
    imprimirLivro(hashTable->livros[1]);*/
    // printf("title: %s\n",hashTable->livros[1]->titulo);
    if(option > 0 && option < 4) {
        switch(option) {
            case 1 : menuConfiguration(users);
                    break;
            case 2 : menuManagement(bst,hashTable);
                    break;
            case 3 : login(hashTable);
                    break;
            default: menuStart();
                break;
        }
    }else {
        menuStart();
        printf("error");
    }
    menuStart();
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
            case 1 : criarAcount(users);
                    break;
            case 2 : updatePassword(users);
                    break;
            case 3 : loadFiles();
                    break;
            default: menuConfiguration(users);
                break;
        }
    }
        menuConfiguration(users);
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
            case 6 : showIndisponibleBook();
                    break;
            default: menuManagement(bst,hashTable);
                break;
        }
    }else {
        menuManagement(bst,hashTable);
        printf("error");
    }
        menuManagement(bst,hashTable);

}

void login(HashTable* hashTable) {
    int option;

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
            case 2 : requestBook();
                    break;
            case 3 : returnBook();
                    break;
            default: login(hashTable);
                break;
        }
    }else {
        login(hashTable);
        printf("error");
    }


}
void insertion(BST* bst,HashTable* hashTable )
{

    int quantityOfInsertionBook;
    char title[20],autor[20];
    int disponibility = 0;

    printf("Quantos livros deseja inserir: ");
    scanf("%d",&quantityOfInsertionBook);

    Livro livro[quantityOfInsertionBook];

    for(int index = 0; index < quantityOfInsertionBook;index++) {

            printf("Insere titulo: ");
            scanf("%s",title);
            printf("Insere Autor: ");
            scanf("%s",autor);
            printf("Disponibilidade: ");
            scanf("%d",&disponibility);

            strcpy(livro[index].titulo ,title);
            strcpy(livro[index].autor ,autor);
            livro[index].disponivel = disponibility;

            inserirLivro(bst, livro[index]);

             inserirLivroHashTable(hashTable, buscarLivro(bst, livro[index].titulo));

    }


    Livro livro1 = {"Livro 1", "Autor 1", 1};
    Livro livro2 = {"Livro 2", "Autor 2", 1};
    Livro livro3 = {"Livro 3", "Autor 3", 0};

    inserirLivro(bst, livro1);
    inserirLivro(bst, livro2);
    inserirLivro(bst, livro3);

    inserirLivroHashTable(hashTable, buscarLivro(bst, livro1.titulo));
    inserirLivroHashTable(hashTable, buscarLivro(bst, livro2.titulo));
    inserirLivroHashTable(hashTable, buscarLivro(bst, livro3.titulo));


}


int search( HashTable* hashTable) {
    char title[20], autor[15];

    printf("Insere o titule do livro: ");
    scanf("%s",title);


    Livro* livroEncontrado = buscarLivroHashTable(hashTable, title);
    if (livroEncontrado != NULL) {
        printf("Livro encontrado!\n");

        imprimirLivro(livroEncontrado);

    } else {
        printf("Livro não encontrado!\n");
    }

    return 0;

}
