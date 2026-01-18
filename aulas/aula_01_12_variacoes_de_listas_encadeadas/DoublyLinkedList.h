/**
 * @file DoublyLinkedList.h
 * @author ED 2025.2
 * @brief lista duplamente encadeada circular com nó sentinela
 * @version 0.1
 * @date 2025-12-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node Node; // Renomeando tipo

// Cria lista vazia
Node* dList_create() {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->next = novo;
    novo->prev = novo;
    novo->data = -999;
    return novo;
}

// Libera TODOS os nos da lista
void dList_free(Node *head) {
    Node *atual = head->next;
    while(atual != head) {
        Node *aux = atual;
        atual = atual->next;
        printf("list_free: nodo liberado: %d\n", aux->data);
        free(aux);
    }
    free(head);
}

// Insere um elemento no final da lista
void dList_push_back(Node *head, int val) {
    Node *novo = (Node*)malloc(sizeof(Node)); // Aloca novo no
    novo->data = val;
    // Liga o no novo a lista
    novo->next = head;
    novo->prev = head->prev;
    // Inclui o no na lista
    head->prev->next = novo;
    head->prev = novo;
}

// Insere um elemento no inicio da lista
void dList_push_front(Node *head, int val) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->data = val;
    novo->next = head->next;
    novo->prev = head;
    head->next->prev = novo;
    head->next = novo;
}

// Remove o ultimo elemento da lista
Node* dList_pop_back(Node* head) {
    if(head->next == head)
        return; // Caso de lista vazia
    Node *aux = head->prev;
    head->prev = aux->prev;
    aux->prev->next = head;
    free(aux);
}

// Remove o primeiro elemento da lista
Node* dList_pop_front(Node* head) {
    Node *temp = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    free(temp);
}

int dList_size(Node *head) {
    Node *aux = head->next;
    int size = 0;
    while(aux != head) {
        aux = aux->next;
        size++;
    }
    return size;
}

// // Retorna o tamanho da lista
// size_t dList_size(Node *head) {
//     size_t size = 0;
//     Node *atual = head;
//     for(Node *atual = head->next; atual != head; atual = atual->next && size++);
//     return size;
// }

// Retorna true se e somente se a lista estiver vazia
bool dList_is_empty(Node *head) {
    return (head->nex == head); // Retorna o resultado da comparacao
}

// Imprimie a lista na tela
void dList_print(Node *head) {
    printf("[ ");
    for(Node *atual = head->next; atual != head; atual = atual->next) {
        printf("%d ", atual->data);
    }
    printf("]\n");
}

// Remover todos os elementos da lista e deixa apenas o no sentinela. Ou seja, deixara lista vazia
void dList_clear(Node *head) {
    while(!dList_is_empty(head)) {
        Node *temp = head->next;
        head->next = temp->next;
        free(temp);
    }
    head->prev = head;
    // Node *aux = head->next; // Aponta para o primeiro elemento da lista
    // while(aux != head) { // Enquanto o proximo elemento seja diferente da cabeca
    //     Node *temp = aux;
    //     aux = aux->next;
    //     free(temp);
    // }
}

// // Remover um elemento que esteja num indice especificado
// void dList_remove(Node *head, size_t index) {
//     Node *atual = head->next; // Aponta para o primeiro elemento da lista
//     size_t i = 0;
//     while(atual != head) {
//         if(i == index) {
//             Node *temp = atual;
//             Node *prev = atual->prev;
//             atual = atual->next;
//             printf("list_remove: nodo liberado: %d\n", temp->data);
//         }
//     }
// }

// Remove da lista todas as ocorrencias de elemento com valor k
void dList_remove_all(Node *head, int k) { 
    Node *aux = head->next;
    while(aux != head) {
        Node *temp = aux->next;
        if(aux->data == k) {
            aux->prev->next =  aux->next;
            aux->next->prev = aux->prev;
            free(aux);
        }
        aux = temp;
    }
    
    // Node *aux = head->next;
    // while(aux != head) {
    //     if(aux->data == x) {
    //         Node *temp = aux;
    //         aux = aux->next;
    //         temp->prev->next = aux;
    //         aux->prev = temp->prev;
}

// Realiza o algoritmo BubbleSort
void dList_bubblesort(Node *head) {
    for(Node *i = head->next; i != head; i = i->next) {
        for(Node *j = head->prev; j != i; j = j->prev) {
            if(j->data < j->prev->data) {
                int aux = j->data;
                j->data = j->prev->data;
                j->prev->data = aux;
            }
        }
    }
}