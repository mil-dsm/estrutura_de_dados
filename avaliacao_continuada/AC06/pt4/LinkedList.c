#include "LinkedList.h"

struct node {
    int data;
    struct node *next;
};


// Função que cria uma lista vazia
// sem nó sentinela
Node *list_create(void) {
    return NULL;
}

// Insere um valor no início da lista
// e retorna a lista modificada.
Node *list_push_front(Node *list, int value) {
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->data = value;
    novo->next = list;
    return novo;
}

// Insere um valor ao final da lista
// e retorna a lista modificada.
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

// Função que recebe um ponteiro para a cabeça da lista e
// imprime o conteúdo dos elementos na tela.
// Formato: [ a1 a2 a3 ... an ]
void list_print(Node *list) {
    printf("[ ");
    while(list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("]\n");
}

// Função que libera todos os nós 
// alocados dinamicamente
void list_free(Node *list) {
    while(list != NULL) {
        Node *aux = list->next;
        printf("list_free: nodo liberado: %d\n", list->data);
        free(list);
        list = aux;
    }
}

// Função que imprime o tamanho da lista (número de nós)
size_t list_size(Node *list) {
    size_t contador = 0;
    for(Node *atual = list; atual != NULL; atual = atual->next) {
        contador++;
    }
    return contador;
}

// Esta função recebe como entrada uma lista simplesmente encadeada e 
// executa uma varredura na lista, comparando nós consecutivos dois-a-dois e movendo o maior 
// elemento que ela encontra para a direita na lista. 
// A função retorna como resultado a lista modificada.
// Por exemplo, se passarmos como entrada a lista [9,8,7,6,5] então a lista resultante deve ser [8,7,6,5,9].
// Veja que a função foi comparando os elementos dois-a-dois da esquerda para a direita, movendo o maior para a 
// direita, nesse caso o número 9 que é o maior de todos na varredura acabou sendo movido para o final da lista.
// Mais um exemplo: se passarmos a lista [6,5,4,3,8,9] como entrada, então a lista resultante deve ser [5,4,3,6,8,9].
Node* list_varredura(Node *p) {
    if (p == NULL) return NULL;
    for(Node *atual = p; atual->next != NULL; atual = atual->next) {
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
Node* list_bubblesort(Node *p) {
    if(p == NULL) return NULL;
    int size = 0;
    Node *atual = p;
    while(atual != NULL) {
        size++;
        atual = atual->next;
    }
    for(int i = 0; i < size - 1; i++) {
        list_varredura(p);
    }
    return p;
}