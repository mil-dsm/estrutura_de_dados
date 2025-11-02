// Função Partition é uma função auxiliar do algoritmo Quick Sort que promete
// posicionar o pivô em sua posição correta no vetor. Todos os elementos menores
// ou iguais ao pivô são colocados à esquerda, e os maiores, à direita.
// Entrada: vetor 'A[l...r]', índice inicial 'l' e índice final 'r'.
// Saída: índice 'j' que indica a posição final do pivô no vetor.
int partition(int A[], int l, int r){
    int pivo = A[r];
    int j = l;
	// Percorre o vetor e constrói dois subvetores dentro, de menores e maiores que o pivô
    for(int i=l; i<r; i++){
        if(A[i] <= pivo){
            int aux = A[i];
            A[i] = A[j];
            A[j++] = aux;
        }
    }
	// Atualiza-se a posição do vetor do pivô
    A[r] = A[j];
    A[j] = pivo;
    return j;
}

// Algoritmo Quick Sort é uma função que promete ordenar um vetor A[l...r] de
// forma crescente. O vetor é particionado com base em um pivô, que separa os 
// elementos menores e maiores. O processo é aplicado recursivamente às duas 
// partes até que o vetor esteja ordenado.
// Entrada: vetor 'A[l...r]', índice inicial 'l' e índice final 'r'.
// Saída: vetor 'A[l...r]' ordenado em ordem crescente.
void QuickSort(int A[], int l, int r){
    if(l<r){
		// Dividir: descobrir a posição do pivô
        int j = partition(A, l, r);
		// Conquistar: chamada recursiva dos dois lados do pivô
        QuickSort(A, l, j-1);
        QuickSort(A, j+1, r);
    }
}