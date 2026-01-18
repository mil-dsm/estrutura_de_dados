#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    Node *next;
    Node *prev;
};

// Cria uma lista vazia
Node* dlist_create() {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->next = novo;
    novo->prev = novo;
    // novo->data = lixo memoria
    return novo;
}

// Destroi uma lista, liberando a memória alocada previamente
void dList_free(Node *head) {
    Node *atual = head->next;
    while(atual != head) {
        Node *temp = atual;
        atual = atual->next;
        printf("list_free: nodo liberado: %d\n", temp->data);
        free(temp);
    }
    free(head);
}

// Insere um elemento ao final da lista
void dList_push_back(Node *head, int val) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->data = val;
    novo->next = head;
    novo->prev = head->prev;
    head->prev->next = novo;
    head->prev = novo;
}

// Insere um elemento ao inicio da lista
void dList_push_front(Node *head, int val) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->data = val;
    novo->prev = head;
    novo->next = head->next;
    head->next->prev = novo;
    head->next = novo;
}

// Inserir um elemento em um indice especificado. Lembre que numa lista de tamanhon os indice vao de 0 a n − 1.
Node* dList_insert(Node *head, int val, int idx) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->data = val;
    novo->next = novo;
    novo->prev = novo;
    Node *atual = head->next;
    int i = 0;
    while(atual != head) {
        if(i == idx) {
            atual->prev->next = novo;
            novo->prev = atual->prev;
            atual->prev = novo;
            novo->next = atual;
        }
        atual = atual->next;
        i++;
    }
    if(i == idx) { // Caso em que o tamanho eh igual  ao indice
        novo->prev = head->prev;
        novo->next = head;
        head->prev->next = novo;
    }
    return head; // Caso o indice nao seja valido, nao faz nada e retorna
}

// Remove um elemento do final da lista
void dList_pop_back(Node *head) {
    if(head->next == head) return head;
    Node *temp = head->prev;
    head->prev = temp->prev;
    temp->prev->next = head;
    printf("list_pop_back: nodo liberado: %d\n", temp->data);
    free(temp);
}

// Remove um elemento do inicio da lista
void dList_pop_front(Node *head) {
    if(head->next == head) return head;
    Node *temp = head->next;
    head->next = temp->next;
    temp->next->prev = head;
    printf("list_pop_front: nodo liberado: %d\n", temp->data);
    free(temp);
}

// Retorna o tamanho da lista
int dList_size(Node *head) {
    Node *atual = head->next;
    int size = 0;
    while(atual != head) {
        size++;
        atual = atual->next;
    }
    return size;
}

// Retorna se a lista esta vazia
bool dList_is_empty(Node *head) {
    return (head->next == head); // Se o resultado da comparacao for true, retorna true, caso contrario retorna false
}

// Imprime os elementos da lista
void dList_print(Node *head) {
    if(head->next == head) return;
    Node *atual = head->next;
    printf("[ ");
    while(atual != head) {
        printf("%d", atual->data);
        if(atual->next != head) printf(", ");
        atual = atual->next;
    }
    printf(" ]\n");
}

// Remove todos os elementos da lista e deixa apenas o no sentinela. Ou seja, deixar a lista vazia
void dList_clear(Node *head) {
    if(head->next == head) return;
    Node *atual = head->next;
    while(atual != head) {
        Node *temp = atual;
        atual = atual->next;
        printf("list_clear: nodo liberado: %d\n", temp->data);
        free(temp);
    }
    head->next = head;
    head->prev = head;
}

// Remove um elemento que esteja num indice especificado. Lembre que numa lista de tamanho n os indices vao de 0 a n −1
void dList_remove(Node *head, int idx) {
    if(head->next == head) return;
    Node *atual = head->next;
    int i = 0;
    while(atual != head) {
        if(i == idx) {
            Node *temp = atual;
            atual = atual->next;
            atual->prev = temp->prev;
            temp->prev->next = atual;
            printf("list_remove: nodo liberado: %d\n", temp->data);
            free(temp);
            return;
        }
        atual = atual->next;
        i++;
    }
}

// Removee da lista todas as ocorrencias de elemento com valor k; esse k eh passado para a funcao como argumento
void dList_remove_value(Node *head, int k) {
    if(head->next == head) return;
    Node *atual = head->next;
    while(atual != head) {
        if(atual->data == k) {
            Node *temp = atual;
            atual = atual->next;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            printf("list_remove_value: nodo liberado: %d\n", temp->data);
            free(temp);
        } else {
            atual = atual->next;
        }
        i++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////conferir
// Reverte a lista. Fazer em tempo O(n) e sem usar memoria adicional
Node* dList_reverse(Node *head);

// Concatena duas listas. Se a lista 1 for vazia, retorne a lista 2
Node* dList_concatena(Node *p1, Node *p2) {
    if(p1->next == p1) return p2;
    p1->prev->next = p2->next; // Liga o ultimo elemento da lista p1 ao primeiro da lista p2
    p2->next->prev = p1->prev;
    p2->next = p2; // O no sentinela de p2 eh liberado
    p2->prev = p2;
    free(p2);
    return p1;
}
// Clonar uma lista. Um clone de uma lista eh uma copia da lista
Node* dList_clone(Node *p1) {
    Node *clone = (Node*)malloc(sizeof(Node));
    clone->next = NULL;
    clone->prev = NULL;
    Node *atual_p = p->next;
    Node *atual_c = clone;
    while(atual_p != p) {
        Node *novo = (Node*)malloc(sizeof(Node));
        novo->data = atual_p->data;
        atual_c->next = novo;
        novo->prev = atual_c;
        atual_c = atual_c->next;
        atual_p = atual_p->next;
    }
    atual_c->next = clone;
    clone->prev = atual_c;
    return clone;
}

// Retornar se duas listas sao iguais
bool dList_are_equal(Node *p1, Node *p2) {
    Node *atual_p1 = p1->next;
    Node *atual_p2 = p2->next;
    while(atual_p1 != p1 && atual_p2 != p2) {
        if(atual_p1->data != atual_p2->data) return false;
        atual_p1 = atual_p1->next;
        atual_p2 = atual_p2->next;
    }
    if(atual_p1 == p1 && atual_p2 == p2)
        return true;
    return false;
}

// Retornar se duas listas sao diferentes
bool dList_are_dif(Node *p1, Node *p2) {
    Node *atual_p1 = p1->next;
    Node *atual_p2 = p2->next;
    while(atual_p1 != p1 && atual_p2 != p2) {
        if(atual_p1->data != atual_p2->data) return true;
        atual_p1 = atual_p1->next;
        atual_p2 = atual_p2->next;
    }
    if(atual_p1 == p1 && atual_p2 == p2)
        return false;
    return true;
}

// Dadas duas listas ordenadas ℓ1 e ℓ2, intercalar as duas listas gerando uma listaℓ3 ordenada. A lista ℓ3 eh formada
// pelos nos das listas ℓ1 e ℓ2. Nao aloque nos adicionais. Ao final desta operacao, as listas ℓ1 e ℓ2 ficam vazias
Node *dList_intercala(Node *p1, Node *p2) {
    Node *atual_p1 = p1->next;
    Node *atual_p2 = p2->next;
    Node *nova_lista = (Node*)malloc(sizeof(Node));
    Node *atual_nova_lista = nova_lista;
    while(atual_p1 != p1 && atual_p2 != p2) {
        Node *novo = (Node*)malloc(sizeof(Node));
        if(atual_p1->data =< atual_p2->data) {
            novo->data = atual_p1->data;
            atual_p1 = atual_p1->next;
        } else {
            novo->data = atual_p2->data;
            atual_p2 = atual_p2->next;
        }
        atual_nova_lista->next = novo;
        novo->prev = atual_nova_lista;
        atual_nova_lista = atual_nova_lista->next;
    }
    while(atual_p1 != p1) {
        Node *novo = (Node*)malloc(sizeof(Node));
        nova->data = atual_p1->data;
        atual_nova_lista->next = novo;
        novo->prev = atual_nova_lista;
    }
    while(atual_p2 != p2) {
        Node *novo = (Node*)malloc(sizeof(Node));
        nova->data = atual_p2->data;
        atual_nova_lista->next = novo;
        novo->prev = atual_nova_lista;
    }
    atual_nova_lista->next = nova_lista;
    nova_list_prev = atual_nova_lista;
}

// Esta função recebe como entrada uma lista simplesmente encadeada e 
// executa uma varredura na lista, comparando nós consecutivos dois-a-dois e movendo o maior 
// elemento que ela encontra para a direita na lista. 
// A função retorna como resultado a lista modificada.
// Por exemplo, se passarmos como entrada a lista [9,8,7,6,5] então a lista resultante deve ser [8,7,6,5,9].
// Veja que a função foi comparando os elementos dois-a-dois da esquerda para a direita, movendo o maior para a 
// direita, nesse caso o número 9 que é o maior de todos na varredura acabou sendo movido para o final da lista.
// Mais um exemplo: se passarmos a lista [6,5,4,3,8,9] como entrada, então a lista resultante deve ser [5,4,3,6,8,9].
Node* dList_varredura(Node *p) {
    for(Node *atual = p->next; atual != p; atual = atual->next) {
        if(atual->data > atual->next->data) {
            int aux = atual->data;
            atual->data = atual->next->data;
            atual->next->data = aux;
        }
    }
    return p;
}

// Esta função usa a função list_varredura descrita acima para implementar 
// o algoritmo de ordenação por bolha (bubblesort) numa lista encadeada.
// Complexidade: O(n^2).
// Não é preciso alocar memória nessa função.
Node* dList_bubblesort_varredura(Node *p) {
    for(Node *i = p->prev; i != p; i = i->prev) {
        dList_varredura(p);
    }
    return p;
}

// Implementa o algoritmo de ordenação por bolha (bubblesort) numa lista encadeada.
// Complexidade: O(n^2).
// Não é preciso alocar memória nessa função.
Node* dList_bubblesort(Node *p) {
    for(Node *i = p->prev; i != p; i = i->prev) {
        for(Node *j = p->next; j != i; j = j->next) {
            if(j->data > j->next->data) {
                int aux = j->data;
                j->data = j->next->data;
                j->next->data = aux;
            }
        }
    }
    return p;
}

// Implementar o algoritmo InsertionSort para listas
Node *dList_insertionsort(Node *p);

// Implementar o algoritmo SelectionSort para listas
Node *dList_selectionsort(Node *p);