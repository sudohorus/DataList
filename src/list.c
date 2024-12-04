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

// remove elementos duplicados da lista
void removeDuplicates(List* list){
    Node* current = list->head;
    // percorre a lista principal
    while (current != NULL){        
        Node* runner = current;
        // percorre os nós após o atual para buscar duplicados
        while(runner->next != NULL){
            //se o próximo nó tem o mesmo valor do nó atual
            if(runner->next->data == current->data){
                // guarda o nó duplicado pra liberar a memoria
                Node* duplicate = runner->next;
                // remove o nó duplicado
                runner->next = runner->next->next;
                // libera a memoria do nó duplicado
                free(duplicate);
            }else{
                // caso nao seja duplicado, vai pro próximo
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// ordena a lista em ordem crescente
void sortList(List* list){
    // se a lista esta vazia, não faz anda
    if(list->head == NULL) return;
    
    Node* i = list->head;
    while(i != NULL){
        Node* j = i->next;
        // compara o nó atual com todos os nós seguintes
        while(j != NULL){
            // se o valor do nó atual for maior que o do nó seguinte
            if(i->data > j->data){
                // troca os valores dos nós
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            // avanca para o próximo nó
            j = j->next;
        }
        // avança para o proximo nó da lista principal
        i = i->next;
    }
}

// combina duas listas em uma única lista
void mergeLists(List* list1, List* list2, List* mergedList){
    // inicializa a lista de destino mergedList como vazia
    initList(mergedList);

    // itera pelos nós da primeira lista (list1)
    Node* temp = list1->head;
    while(temp != NULL){
        // adiciona o dado do nó atual de list1 no final de mergedList
        addToEnd(mergedList, temp->data);
        temp = temp->next;
    }

    // itera pelos nós da segunda lista (list2)
    temp = list2->head;
    while(temp != NULL){
        // adiciona o dado do nó atual de list2 no final de mergedList
        addToEnd(mergedList, temp->data);
        temp = temp->next;
    }
}
// retorna o valor N do elemento na lista
int findNthElement(List* list, int n){
    Node* temp = list->head;
    int index = 0;

    while(temp!=NULL){
        if(index == n){
            return temp->data;
        }
        index++;
        temp = temp->next;
    }

    printf("Index out of bounds.\n");
    return -1;
}

// encontra o elemento do meio da lista
int findMiddle(List* list){
    Node* slow = list->head;
    Node* fast = list->head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow ? slow->data : -1;
}
