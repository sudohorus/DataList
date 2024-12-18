#ifndef LIST_H
#define LIST_H

// definindo a estrutura de um nó. Cada nó armazena um valor inteiro e um ponteiro para o próximo nó.
typedef struct Node{
    void* data;           // valor armazenado no nó
    struct Node* next;  // ponteiro para o próximo nó na lista
} Node;

// definindo a estrutura da lista. A lista tem apenas um ponteiro para o primeiro nó (head)
typedef struct{
    Node* head;         // ponteiro para o primeiro nó da lista
} List;

// funcao para iniciar uma lista vazia
void initList(List* list);
// funcao para adicionar um valor à lista
void addToList(List* list, int value);
// funcao para imprimir todos os valores da lista
void printList(List* list);
// funcao para liberar a memoria da lista
void freeList(List* list);
// adiciona ao final da lista
void addToEnd(List* list, int value);
// remover da lista
void removeFromList(List* list, int value);
// conta o numero de elementos na lista
int countList(List* list);
// fucao para verificar se a lista esta vazia
int isListEmpty(List* list);
// procura valor na lista
int searchList(List* list, int value);
// funcao para inverter a lista
void reverseList(List* list);
// funcao para duplicar a lsita
void duplicateList(List* list, List* new_list);
// funcao para encontrar o valor maximo
int findMax(List* list);
// funcao para encontrar o valor minimo
int findMin(List* list);
// remove elementos duplicados da lista
void removeDuplicates(List* list);
// ordena a lista em ordem crescente
void sortList(List* list);
// combina duas listas em uma única lista
void mergeLists(List* list1, List* list2, List* mergedList);
// retorna o valor N do elemento na lista
int findNthElement(List* list, int n);
// encontra o elemento do meio da lista
int findMiddle(List* list);
// remove o último elemento da lista
void removeLast(List* list);
// funcao pra duplicar os elementos da lista
void duplicateElements(List* list);
// função para remover todos os elementos maiores que um valor específico
void removeGreaterThan(List* list, int value);
#endif