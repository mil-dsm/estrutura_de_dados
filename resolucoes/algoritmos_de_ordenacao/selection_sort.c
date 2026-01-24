// Algoritmo Selection Sort é uma função que promete ordenar um vetor A[0...n-1]
// de forma crescente, encontrando o menor elemento em cada passagem e trocando-o
// de posição com o primeiro elemento do subvetor desordenado. A cada iteração,
// o menor valor é colocado em sua posição correta, expandindo a parte ordenada
// do vetor da esquerda para a direita.
// Entrada: tamanho 'n' do vetor, vetor 'A[0...n-1]'.
// Saída: vetor ordenado em ordem crescente.
void SelectionSort(int n, int A[]){
    for(int i=0; i<n-1; i++){
        int indexMin = i;
		// Descobre-se o menor elemento
        for(int j=i+1; j<n; j++){
            if(A[j]<A[indexMin]){
                indexMin = j;
            }
        }
		// O menor elemento é colocado em seu lugar
        int aux = A[i];
        A[i] = A[indexMin];
        A[indexMin] = aux;
    }
}

void SelectionSort_recursivo(int A[], int n, int i){
    if(i == n-1){
        return;
    }
    int indexMin = i;
    for(int j=i+1; j<n; j++){
        if(A[j]<A[indexMin]){
            indexMin = j;
        }
    }
    int aux = A[i];
    A[i] = A[indexMin];
    A[indexMin] = aux;
    SelectionSort_recursivo(A, n, i+1);
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &n);
    }
    SelectionSort(A, n);
    SelectionSort_recursivo(A, n, 0);
    for(int i=0; i<n; i++){
        printf("%d", A[i]);
        if(i == n-1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
}