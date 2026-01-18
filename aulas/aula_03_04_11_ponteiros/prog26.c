/*Vazamento de memoria*/

// Quando a função termina, a variável ptr é destruída, 
// mas a memória alocada por malloc continua existindo
// na heap — e não há mais ponteiro apontando para ela.
void funcao() {
    int *ptr = (int*) malloc(10 * sizeof(int));
}

// Um ponteiro que contem um endereco da memoria alocada
// dinamicamente recebe outro valor
int main(){
    int v = 5;
    int *ptr = (int *) malloc(10 * sizeof(int)); // Aloca memoria
    ptr = &v; // O endereco antigo eh perdido: vazamento de memoria
}

// Perda de memoria por alocacao dupla
int main(){
    int *ptr = (int *) malloc (10 * sizeof(int));
    ptr = (int *) malloc (7 * sizeof(int));
}

// Forma de evitar vazemento de memoria:
// Liberar o ponteiro antes de alocar nom=va memoria
int main(){
    int *ptr = (int *) malloc(5 * sizeof(int));
    free(ptr);
    ptr = (int*) malloc(6 * sizeof(int));
}