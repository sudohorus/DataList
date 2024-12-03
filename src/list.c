#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

// função para inicializar a lista. Ela começa vazia, com o ponteiro 'head' apontando para NULL
void initList(List* list){
    list->head = NULL;  // a lista começa vazia, sem nenhum nó
}

// funcao para adicionar um valor a lista. Esse valor será inserido no início da lista
void addToList(List* list, int value){
    // aloca memória para um novo nó. Esse nó será inserido no início da lista
    Node* new_node = (Node*)malloc(sizeof(Node));

    // verifica se a alocação foi bem-sucecida
    if(new_node == NULL){
        printf("Memory allocation error.\n");
        return;         // se a alocação falhar, a função retorna sem fazer nada
    }

    // atribui o valor ao novo nó
    new_node->data = value;

    // faz o proximo nó apontar para o nó que estava no inicio da lista
    new_node->next = list->head;

    // agora, o primeiro nó da lista(head) deve apontar para o novo nó
    list->head = new_node;
}

// funcao para imprimir todos os valores da lista. Ele percorre a lista e imprime cada nó
void printList(List* list){
    Node* temp = list->head;    // comeca a partir do primeiro nó (head)

    // enquanto o nó atual nao for NULL, ou seja, enquanto houver elemento na lista
    while(temp != NULL){
        // imprime um valor do nó atual
        printf("%d -> ", temp->data);

        // avanca para o proximo nó
        temp = temp->next;
    }
    // quando a lista acabar, imprime 'NULL' para indicar o fim da lista
    printf("NULL\n");
}

// funcao para liberar a memória da lista
void freeList(List* list){
    Node* temp = list->head;    // comeca a partir do primeiro nó

    // enquanto houver nó na lista
    while(temp != NULL){
        Node* next = temp->next;// guarda o próximo nó

        free(temp);             // libera a memória do nó atual

        temp = next;            // avança para o próximo
    }

    list->head = NULL;          // apos liberar todos, a lista fica vazia
}

// funcao para remover um valor da lista
void removeFromList(List* list, int value){
    Node* temp = list->head;
    Node* prev = NULL;

    // caso a lista esteja vazia
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    }

    // percorre a lista ate encontrar o valor
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    // se o valor nao for encontrado
    if(temp == NULL){
        printf("Value not found in list.\n");
        return;
    }

    // se o valor for o primeiro nó da lista
    if(prev == NULL){
        list->head = temp->next;
    }else{
        prev->next = temp->next;
    }

    // libera a memória do nó removido
    free(temp);
}

// funcao para contar o numero de elementos na lista
int countList(List* list){
    int count = 0;
    Node* temp = list->head;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}

// funcao para verificar se a lista está vazia
int isListEmpty(List* list){
    return list->head == NULL;
}

// funcao para buscar um valor na lista
int searchList(List* list, int value){
    Node* temp = list->head;

    while(temp != NULL){
        if(temp->data == value){
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

// funcao para adicionar um valor ao final da lista
void addToEnd(List* list, int value){
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL){
        printf("Memory allocation error.\n");
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    // caso a lista esteja vazia, adiciona o primeiro nó
    if(list->head == NULL){
        list->head = new_node;
    }else{
        Node* temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// funcao para inverter a lista
void reverseList(List* list){
    Node* prev = NULL;
    Node* curr = list->head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;  // salva o próximo nó
        curr->next = prev;  // inverte o ponteiro
        prev = curr;        // avança para o próximo nó
        curr = next;        // avança para o próximo nó
    }

    list->head = prev;
}

// funcao para duplicar a lista
void duplicateList(List* list, List* new_list){
    Node* temp = list->head;

    // inicializa a nova lista
    initList(new_list);

    // percorre a lista original e adiciona os valores na nova lista
    while(temp != NULL){
        addToEnd(new_list, temp->data);
        temp = temp->next;
    }
}

// funcao pra encontrar o valor máximo na lista
int findMax(List* list){
    if(list->head == NULL){
        printf("List is empty.\n");
        return -1;
    }

    int max = list->head->data;
    Node* temp = list->head->next;

    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}

// funcao pra encontrar o valor minimo da lista
int findMin(List* list){
    if(list->head == NULL){
        printf("List is empty.\n");
        return -1;
    }

    int min = list->head->data;
    Node* temp = list->head->next;

    while(temp != NULL){
        if(temp->data < min){
            min = temp->data;
        }
        temp = temp->next;
    }

    return min;
}