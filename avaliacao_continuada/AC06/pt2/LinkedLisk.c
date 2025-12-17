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

// Esta função reverte a ordem dos elementos na lista.
// Por exemplo, se você tiver a lista [10,30,40,50], então após
// chamar essa função a sua lista torna-se [50,40,30,10].
// A complexidade dessa função deve ser O(n). Além disso, faça essa
// função SEM ALOCAR NOVOS NODES. É possível fazer essa função sem
// alocar novos nós. Você precisará apenas de três ponteiros adicionais
// para te ajudar a reverter a sua lista.
// Retorna um ponteiro para a lista revertida.
Node* list_reverter(Node *p) {
    Node *atual = p;
    Node *next = NULL;
    Node *prev = NULL;
    while(atual != NULL) {
        next = atual->next;
        atual->next = prev;
        prev = atual;
        atual = next;
    }
    return prev;
}

// Essa função recebe como parâmetro uma lista, um índice e um valor inteiro
// e insere esse inteiro na posição indicada pelo índice.
// Note que os índices estarão no intervalo [0..n-1].
// Ao final, retorna a lista modificada.
// Por exemplo, dada a lista [1,2,3,4,5,6] se voce chamar a função list_inserir_apos
// com o índice 2 e com o valor 999, essa função vai
// inserir o 999 logo após o elemento 3, resultando na lista: [1,2,3,999,4,5,6].
// Se o índice for inválido a lista não é modificada. Um índice é inválido se ele for
// maior ou igual a n, ou se ele for igual a 0 e a lista estiver vazia.
Node* list_inserir_apos(Node *p, size_t index, int val) {
    if (p == NULL) return p;
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->data = val;
    novo->next = NULL;
    Node *atual = p;
    size_t i = 0;
    while(atual != NULL) {
        if(i == index) {
            novo->next = atual->next;
            atual->next = novo;
            break;
        }
        atual = atual->next;
        i++;
    }
    return p;
}

// Remove o elemento que está após o índice indicado.
// Note que os índices estarão no intervalo [0..n-2].
// Ao final, retorna a lista modificada.
// Por exemplo, dada a lista [1,2,3,4,5,6] se voce chamar a função list_remover_apos
// com o índice 4, essa função vai remover o número 6, resultando na lista: [1,2,3,4,5].
// Se o índice for inválido a lista não é modificada. Um índice é inválido se ele for
// maior ou igual a n, ou se ele for igual a 0 e a lista estiver vazia.
Node* list_remover_apos(Node *p, size_t index) {
    if (p == NULL) return p;
    Node *atual = p;
    size_t i = 0;
    while(atual != NULL) {
        if(i == index) {
            if(atual->next == NULL)
                break;
            Node *temp = atual->next;
            atual->next = temp->next;
            free(temp);
            break;
        }
        atual = atual->next;
        i++;
    }
    return p;
}