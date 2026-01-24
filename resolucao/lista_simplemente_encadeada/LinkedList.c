/**
 * @file LinkedList.c
 * @author your name (you@domain.com)
 * @brief Implementação de uma lista simplesmente encadeada com nó sentinela e suas operações.
 * @version 0.1
 * @date 2025-12-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

struct node {
    int data;
    struct node *next;
};

// Função de criação de uma lista simplesmente encadeada com nó sentinela.
Node* list_create(void) {
    Node *head = malloc(sizeof(Node));
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL; // sentinela não guarda dado
    return head;
}

// Função que retorna um ponteiro para uma nova lista com os elementos que
// existem na lista 1 mas não existem na lista 2, passadas como parâmetro.
Node* list_diferenca(Node *m_head1, Node *m_head2) {
    Node *m_head3 = (Node*)malloc(sizeof(Node));
    if(m_head3 == NULL) {
        printf("fail: null pointer.\n");
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

// Função que retorna o comprimento da lista a partir dos seus nós.
int list_comprimento(Node *head) {
    if(head == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    int comp = 0;
    for(Node *atual = head->next; atual != NULL; atual = atual->next) {
        comp++;
    }
    return comp;
}

// Função que retorna quantos nós da lista tem valores maiores que o parâmetro n.
int list_maiores(Node *head, int n) {
    if(head == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    int qtd = 0;
    for(Node *atual = head->next; atual != NULL; atual = atual->next) {
        if(atual->data == n) {
            qtd++;
        }
    }
    return qtd;
}

// Função que retorna um ponteiro para o último nó de uma lista dada como parâmetro.
Node* list_ultimo(Node *head) {
    if(head == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    while(head->next != NULL) {
        head = head->next;
    }
    return head;
}

// Função que concatena duas listas passadas como parâmetro.
Node* list_concatena(Node *m_head1, Node *m_head2) {
    if(m_head1 == NULL || m_head2 == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    if(m_head1->next == NULL) {
        return m_head2;
    }
    Node *atual = m_head1->next;
    while(atual->next != NULL) {
        atual = atual->next;
    }
    atual->next = m_head2->next;
    m_head2->next = NULL;
    free(m_head2);
    return m_head1;
}

// Função que recebe uma lista e um valor k.
// A função removerá todos as ocorrências do valor k na lista.
Node* list_remove(Node *head, int k) {
    if(head == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Node *atual = head->next;
    while(atual != NULL) {
        if(atual->next->data == k) {
            Node *temp = atual->next; // Temp aponta para o nó removível.
            atual->next = temp->next; // O ponteiro next de atual aponto para o valor após o nó removível.
            free(temp);
        }
    }
    return head;
}

// Função que separa uma lista em duas, com a segunda sendo
// separada a partir do valor proposto pelo parametro n.
// Caso o valor não esteja na lista, a função retorna NULL.
Node* list_separa(Node *head, int n) {
    if(list == NULL) {
        printf("fail: null pointer.\n");
        exit(EXIT_FAILURE);
    }
    Node *atual = head->next;
    while(atual != NULL) {
        if(atual->data = n) {
            return atual;
        }
    }
    return NULL;
}

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
    if(head == NULL) {
        printf("fail: allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for(Node *j = head->next->next; j != NULL; j = j->next) {
        Nodekey = j->data;
        Node *i = head->next;
        while(i->next != j)
            i = i->next;
        while(i->data > key && i != head) {
            i->next->data = i->data;
            Node *temp = head;
            while(temp->next != i)
                temp = temp->next;
            i = temp;
        }
        i->next->data= key;
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