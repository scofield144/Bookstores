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

    Livro livro1 = {"Livro 1", "Autor 1", 1};
    Livro livro2 = {"Livro 2", "Autor 2", 1};
    Livro livro3 = {"Livro 3", "Autor 3", 0};

    inserirLivro(bst, livro1);
    inserirLivro(bst, livro2);
    inserirLivro(bst, livro3);

    inserirLivroHashTable(hashTable, buscarLivro(bst, livro1.titulo));
    inserirLivroHashTable(hashTable, buscarLivro(bst, livro2.titulo));
    inserirLivroHashTable(hashTable, buscarLivro(bst, livro3.titulo));

    char tituloBusca[50];
    printf("Digite o título de um livro para buscar: ");
    scanf("%s", tituloBusca);

    Livro* livroEncontrado = buscarLivroHashTable(hashTable, tituloBusca);
    if (livroEncontrado != NULL) {
        printf("Livro encontrado!\n");
        imprimirLivro(livroEncontrado);
    } else {
        printf("Livro não encontrado!\n");
    }

    free(bst);
    free(hashTable);
    return 0;
}