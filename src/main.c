#include <stdio.h>
#include "../include/list.h"
#include <stdlib.h>

int main(){
    List lista;

    initList(&lista);

    printf("hello");
    addToList(&lista, 20);
    addToList(&lista, 2);
    addToList(&lista, 30);

    printf("Lista apos insercoes: ");
    printList(&lista);

    printf("Numero de elementos na lista: %d\n", countList(&lista));

    if(isListEmpty(&lista)) {
        printf("A lista esta vazia.\n");
    } else {
        printf("A lista nao esta vazia.\n");
    }

    printf("Procurando o valor 20: %s\n", searchList(&lista, 20) ? "Encontrado" : "Nao encontrado");

    removeFromList(&lista, 2);
    printf("Lista apos remover o valor 2: ");
    printList(&lista);

    addToEnd(&lista, 40);
    printf("Lista apos adicionar 40 no final: ");
    printList(&lista);

    reverseList(&lista);
    printf("Lista invertida: ");
    printList(&lista);


    List lista_duplicada;
    duplicateList(&lista, &lista_duplicada);
    printf("Lista duplicada: ");
    printList(&lista_duplicada);

    printf("valor maximo: %d\n", findMax(&lista));
    printf("valor minimo: %d\n", findMin(&lista));
    freeList(&lista);

    system("pause");
}