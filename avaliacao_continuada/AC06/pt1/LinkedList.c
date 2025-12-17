#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

struct node {
    int data;
    struct node *next;
};


Node *list_create(void) {
    return NULL;
}

Node *list_push_front(Node *list, int value) {
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->data = value;
    novo->next = list;
    return novo;
}

Node *list_push_back(Node *list, int value) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->data = value;
    novo->next = NULL;

    if(list == NULL) {
        return novo;
    } else {
        Node *q = list;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = novo;
        return list;
    }
}

void list_print(Node *list) {
    printf("[ ");
    while(list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("]\n");
}

void list_free(Node *list) {
    while(list != NULL) {
        Node *aux = list->next;
        printf("list_free: nodo liberado: %d\n", list->data);
        free(list);
        list = aux;
    }
}

size_t list_size(Node *list) {
    size_t contador = 0;
    for(Node *atual = list; atual != NULL; atual = atual->next) {
        contador++;
    }
    return contador;
}

// Esta função concatena duas listas simplemente encadeadas passadas como parâmetro e
// retorna a lista resultante já concatenada.
// Exemplo se p1 = [1,2,3,4] e p2 = [44,66,77], então a lista resultante deve ser [1,2,3,4,44,66,77].
// Se a lista p1 for vazia, deve retornar p2.
Node* list_concatenar(Node *p1, Node *p2) {
    if(p1 == NULL) {
        return p2;
    }
    Node *aux = p1;
    while(aux->next != NULL) aux = aux->next;
    aux->next = p2;
    return p1;
}

// Esta função recebe como entrada uma lista e faz uma
// cópia profunda (deep copy) da lista, i.e., a lista
// resultante contém os mesmos elementos que a original só que
// elas não compartilham nós. As duas listas são independentes.
// Ou seja, essa função cria um clone da lista original e retorna o clone.
Node* list_clone(Node *p) {
    if(p == NULL) {
        return NULL;
    }

    Node *clone = (Node *)malloc(sizeof(Node));
    clone->data = p->data; // Copia o primeiro elemento 
    clone->next = NULL;
    Node *aux_p = p->next; // Inicializa variavel auxiliar que percorre a lista original no segundo elemento, pois ja copiou o primeiro
    Node *aux_clone = clone; // Inicializa variavel auxiliar que percorre a lista clone

    while(aux_p != NULL) { // Continua ate nao ter mais o que clonar
        Node *novo = (Node *)malloc(sizeof(Node));
        novo->data = aux_p->data;
        novo->next = NULL;

        aux_clone->next = novo; // Liga o clone
        aux_clone = novo; // Avanca no clone
        aux_p = aux_p->next; // Avanca no original
    }

    return clone;
}

// Esta função remove todas as ocorrencias do valor 'val' da sua lista.
// Por exemplo, se você tiver a lista [4,1,2,4,4,3,4,4] e chamar
// essa função com o valor 4, a lista resultante sera [1,2,3].
// Não esqueça de liberar os nós que forem removidos.
// Antes de liberar o nó você deve imprimir "liberado: %d" e coloca o valor do nó liberado.
// Retorna a lista modificada.
Node* list_remove_todos(Node *p, int val) {
    while(p != NULL && p->data == val) {
        Node *temp = p;
        p = p->next;
        printf("liberado: %d\n", temp->data);
        free(temp);
    }
    if(p == NULL) return NULL;
    Node *atual = p;
    while(atual->next != NULL) {
        if(atual->next->data == val) {
            Node *temp = atual->next;
            atual->next = temp->next;
            printf("liberado: %d\n", temp->data);
            free(temp);
        } else {
            atual = atual->next;
        }
    }
    return p;
}

// Esta função retorna true se as duas listas são idênticas; ou
// retorna false caso contrário.
// Duas listas são idênticas se elas têm os mesmos elementos na mesma ordem.
bool list_sao_iguais(Node* p1, Node *p2) {
    Node *aux_1 = p1, *aux_2 = p2;
    while(aux_1 != NULL && aux_2 != NULL) {
        if(aux_1->data != aux_2->data) {
            return false;
        }
        aux_1 = aux_1->next;
        aux_2 = aux_2->next;
    }
    if(aux_1 == NULL && aux_2 == NULL) {
        return true;
    }
    return false;
}

// Esta função retorna true se as duas listas são diferentes; ou
// retorna false caso contrário.
// Duas listas são diferentes se elas não são idênticas.
bool list_sao_diferentes(Node* p1, Node *p2) {
    return !list_sao_iguais(p1, p2);
}