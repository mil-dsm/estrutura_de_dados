// Algoritmo Insertion Sort é uma função que promete ordenar um vetor A[0...n-1]
// de forma crescente, inserindo cada elemento em sua posição correta dentro
// do subvetor já ordenado à esquerda. O processo é feito por comparações com
// os elementos anteriores e deslocamentos até encontrar o local apropriado.
// Entrada: tamanho 'n' do vetor, vetor 'A[0...n-1]'.
// Saída: vetor ordenado em ordem crescente.
void InsertionSort(int n, int A[]){
    for(int j=1; j<n; j++){
        int key = A[j]; // Decidi-se a chave para comparações
        int i = j - 1;
        while(i >= 0 && A[i] > key){ // Se A[i] for maior que a chave e i for maior ou igual a 0, A[i] muda de lugar
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void InsertionSort_bicondicional(int A[], int n){
    int B[n];
    int meio = n/2;
    int ini = meio;
    int fim = meio;
    B[meio] = A[0];
    for(int i=1; i<n; i++){
        if(A[i] < B[ini]){
            B[--ini] = A[i];
        }
        else if(A[i] >= B[fim]){
            B[++fim] = A[i];
        }
        else{
            int k = fim;
            while(B[k] > A[i]){
                B[k+1] = B[k--];
            }
            k++;
            B[k] = A[i];
            fim++;
        }
    }
    int j = 0;
    for(int i = ini; i <= fim; i++){
        A[j++] = B[i];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &n);
    }
    InsertionSort(n, A);
    InsertionSort_bicondicional(A, n);
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