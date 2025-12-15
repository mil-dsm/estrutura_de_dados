#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

struct node {
    int data;
    struct node *next;
};

Node* list_create(void) {
    Node *head = malloc(sizeof(Node));
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL; // sentinela não guarda dado
    return head;
}

Node* diferenca(Node *m_head1, Node *m_head2) {
    Node *m_head3 = (Node*)malloc(sizeof(Node));
    if(m_head3 == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    m_head3->next = NULL; // Cria nó senitinela para a lista resultante.

    Node *aux1 = m_head1->next;
    Node *aux3 = m_head3;
    
    while(aux1 != NULL) {
        Node *aux2 = m_head2->next;
        while(aux2 != NULL) {
            if(aux1->data == aux2->data) {
                break;
            }
            aux2 = aux2->next;
        }
        if(aux2 == NULL) {
            Node *novo = malloc(sizeof(Node));
            if(novo == NULL) {
                printf("fail: allocation error.\n");
                exit(EXIT_FAILURE);
            }
            novo->data = aux1->data;
            novo->next = NULL;
            aux3->next = novo;
            aux3 = novo;
        }
        aux1 = aux1->next;
    }

    return m_head3;
}