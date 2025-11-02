// Algoritmo Odd-Even Sort é uma variação do Bubble Sort que promete ordenar
// um vetor A[0...n-1] de forma crescente. Em cada iteração, são realizadas 
// duas passagens: uma comparando os pares (0 e 1, 2 e 3, ...), e outra compa-
// rando os ímpares (1 e 2, 3 e 4, ...). O processo se repete até que nenhuma
// troca ocorra, indicando que o vetor está ordenado.
// Entrada: tamanho 'n' do vetor e vetor 'A[0...n-1]'.
// Saída: vetor ordenado em ordem crescente.
void OddEvenSort(int n, int A[]){
    int trocou = 1;
    while(trocou){
        trocou = 0;
        for(int i=0; i<=n-2; i+=2){
            if(A[i] > A[i+1]){
                int aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
                trocou = 1;
            }
        }
        for(int i=1; i<=n-2; i+=2){
            if(A[i] > A[i+1]){
                int aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
                trocou = 1;
            }
        }
    }
}
