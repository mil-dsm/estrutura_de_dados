// Algoritmo Bubble Sort é uma função que promete ordenar um vetor A[0...n-1]
// de forma crescente, comparando pares adjacentes e trocando-os sempre que
// estiverem fora de ordem. A cada passagem pelo vetor, o maior elemento é
// "empurrado" para o final, como bolhas subindo à superfície.
// Entrada: tamanho 'n' do vetor, vetor 'A[0...n-1]'.
// Saída: vetor ordenado em ordem crescente;
void BubbleSort(int n, int A[]){   
    for(int i = 0; i < n-1; ++i){
		for(int j = n-1; j > i; --j){ // j percorre o vetor decrescendo até i
			if(A[j] < A[j-1]){ // Se A[j] for maior que o anterior, trocam de posição
				int aux = A[j];
				A[j] = A[j-1];
				A[j-1] = aux;  
			}
		}
	}
}

