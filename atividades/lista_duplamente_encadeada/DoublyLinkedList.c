#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DoublyLinkedList.h"

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Criar uma lista vazia.
Node* dList_create(void) {
    Node novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    novo->next = novo;
    novo->prev = novo;
    novo->data = -999;
    return novo;
}

// Destruir a lista, liberando a memória previamente alocada.
void dList_free(Node *head) {
    if(head != NULL) {
        Node *aux = head->next;
        while(aux != head) {
            Node *temp = aux;
            aux = aux->next;
            free(temp);
        }
        free(head);
    }
}

// Inserir um elemento ao final da lista.
void dList_push_back(Node *head, int val) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    novo->data = val;
    novo->next = NULL;
    head->prev->next = novo;
    novo->prev = head->prev;
    head->prev = novo;
    novo->next = head;
}

// Inserir um elemento no início da lista.
void dList_push_front(Node *head, int val) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    novo->data = val;
    novo->next = head->next;
    novo->prev = head;
    head->next->prev = novo;
    head->next = novo;
}

// Remover um elemento do final da lista.
void dList_pop_back(Node *head) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    if(head->next != head) { // Se a lista não for vazia.
        Node *temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        free(temp);
    }
}

// Remover um elemento do início da lista.
void dList_pop_front(Node *head) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    if(head->next != head) { // Se a lista não for vazia.
        Node *temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        free(temp);
    }
}

// Retornar o tamanho da lista.
size_t dList_size(Node *head) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    size_t size = 0;
    for(Node *atual = head->next; atual != head; atual = atual->next)
        size++;
    return size;
}

// Retornar se a lista está vazia.
boolean dList_empty(Node *head) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    return head == head->next; // Retorna true se a comparação for verdadeira.
}

// Imprimir os elementos da lista.
void dList_print(Node* head) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    printf("[ ");
    for(Node *atual = head->next; atual != head; atual = atual->next) {
        printf("%d ", atual->data);
    }
    printf("]\n");
}

// Remover todos os elementos da lista e deixar apenas o nó sentinela, ou seja, deixar a lista vazia.
void dlist_clear(Node *head) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    Node *atual = head->next;
    while(atual != head) {
        Node *temp = atual;
        atual = atual->next;
        free(temp);    
    }
    head->next = head;
    head->prev = head;
}

// Remover um elemento que esteja em um índice especificado. Lembre que, em uma lista de tamanho n, os índices vão de 0 a n − 1.
void dList_remove(Node *head, size_t index) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    if(head == head->next) return;
    // Se a lista não for vazia.
    size_t i = 0;
    Node *atual = head->next;
    while(atual != head) {
        if(i == index) {
            Node *temp = atual;
            atual = atual->next;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
            return;
        } else {
            i++;
            atual = atual->next;
        }
    }
}

// Inserir um elemento em um índice especificado. Lembre que, em uma lista de tamanho n, os índices vão de 0 a n − 1.

// Remover da lista todas as ocorrências de um elemento com valor k; esse k é passado para a função como argumento.

// Reverter a lista, fazendo isso em tempo O(n) e sem usar memória adicional.

// Concatenar duas listas.

// Clonar uma lista. Um clone de uma lista é uma cópia da lista.

// Retornar se duas listas são iguais.

// Dadas duas listas ordenadas ℓ1 e ℓ2, intercalar as duas listas gerando uma lista ℓ3 ordenada. A lista ℓ3 é formada pelos nós das listas ℓ1 e ℓ2. Não alocar nós adicionais. Ao final desta operação, as listas ℓ1 e ℓ2 ficam vazias.

// Implementar o algoritmo BubbleSort para listas.
void dList_bubblesort(Node *head) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for(Node *atual = head->next; atual != head; atual = atual->next)
        size++;
    for(size_t i = 0; i < size; i++) {
        Node *p = head->next;
        for(size_t j = 0; j < size - 1 - i; j++) {
            if(p->data > p->next->data) {
                int aux = p->data;
                p->data = p->next->data;
                p->next->data = aux;
            }
            p = p->next;
        }
    }
}

// Implementar o algoritmo InsertionSort para listas.
void dList_insertionsort(Node *head) {
    if (head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Lista vazia ou com um elemento
    if (head->next == head || head->next->next == head)
        return;

    Node *sorted_end = head->next;   // fim da parte ordenada
    Node *curr = sorted_end->next;   // elemento a inserir

    while (curr != head) {
        int key = curr->data;

        // Se já está na posição correta, só avança
        if (key >= sorted_end->data) {
            sorted_end = curr;
            curr = curr->next;
            continue;
        }

        // Remove curr da posição atual
        sorted_end->next = curr->next;

        // Procura posição de inserção
        Node *prev = head;
        while (prev->next != head && prev->next->data < key) {
            prev = prev->next;
        }

        // Insere curr após prev
        curr->next = prev->next;
        prev->next = curr;

        // Avança para o próximo elemento
        curr = sorted_end->next;
    }
}

// Implementar o algoritmo SelectionSort para listas.
void dList_selectionsort(Node *head) {
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for(Node i = head->next; i != head; i = i->next) {
        Node *min = i;
        for(Node j = i->next; j != head; j = j->next) {
            if(j->data < min->data) {
                min = j;
            }
        }
        int aux = min->data;
        min->data = i->data;
        i->data = aux;
    }
}