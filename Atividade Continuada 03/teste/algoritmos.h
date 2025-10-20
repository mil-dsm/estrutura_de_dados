/*Algoritmos de ordenação
Disciplina: Estruturas de Dados
Turma: 01A
Nome: Milena de Sousa Mesquita
Matrícula: 581180*/

// Algoritmo CockTailSort
// Esta funcao ordena um vetor A[0..n-1]  
void CocktailSort(int n, int A[]) { 
    bool trocou = true; 
    int inicio = 0; 
    int fim = n-1; 
  
    while (trocou) {  
        trocou = false; 
  
        // varre o vetor da esquerda para a direita, 
        // assim como o bubblesort 
        for (int i = inicio; i < fim; i++) 
            if (A[i] > A[i+1]) { 
				int aux = A[i];
				A[i] = A[i+1];
				A[i+1] = aux;
                trocou = true; 
            } 
  
        // se nenhuma troca ocorreu, entao o vetor
        // ja esta ordenado 
        if (!trocou) 
			break;
		else
			// caso contrario, a variavel 'trocou' 
			// volta a ser 'false' para que a 
			// proxima iteração do loop while ocorra  
			trocou = false; 
  
        // como o elemento na posicao 'fim' e todos os 
        // elementos apos ele (se existirem) ja estao
        // ordenados, decrementamos 'fim'  
        fim--; 
  
        // varremos o vetor agora da direita para a esquerda, 
        // fazendo a mesma comparacao que no estagio anterior 
        for (int i = fim-1; i >= inicio; i--) 
            if (A[i] > A[i+1]) { 
                int aux = A[i];
				A[i] = A[i+1];
				A[i+1] = aux; 
                trocou = true; 
            } 
  
        // incrementamos a variavel inicio', pois no 
        // ultimo loop 'for' o proximo menor elemento 
        // foi colocado no seu devido lugar 
        inicio++; 
    } 
}

// Algoritmo BubbleSort
// Ordena um vetor A[0..n-1]
void BubbleSort(int n, int A[]) {   
    for (int i = 0; i < n-1; ++i) {   
		for (int j = n-1; j > i; --j) {
			if (A[j] < A[j-1]) { 
				int aux = A[j];
				A[j] = A[j-1];
				A[j-1] = aux;  
			}
		}
	}
}

// Algorítmo: Insertion Sort
// Ordena um vetor A[0..n-1]
void InsertionSort(int n, int A[]){
    for(int j=1; j<n; j++){
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

// Algorítmo: Selection Sort
// Ordena um vetor A[0..n-1]
void SelectionSort(int n, int A[]){
    for(int i=0; i<n-1; i++){
        int indexMin = i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[indexMin]){
                indexMin = j;
            }
        }
        int aux = A[i];
        A[i] = A[indexMin];
        A[indexMin] = aux;
    }
}

// Algorítmo auxiliar ao Merge Sort
// Entrada: vetores crescentes A[p...q] e A[q+1...r]
// Rearranja A[p...r] em ordem crescente
void Intercala(int A[], int p, int q, int r){
	int n = r-p+1;
	int B[n];
	int i = p;
	int j = q + 1;
	int k = 0;
	// Intercala A[p...q] e A[q+1...r]
	while(i <= q && j <= r){
		if(A[i] <= A[j]){
			B[k++] = A[i++];
		}
		else{
			B[k++] = A[j++];
		}
	}
	while(i <= q){
		B[k++] = A[i++];
	}
	while(j <= r){
		B[k++] = A[j++];
	}
	// Copia vetor ordenado B para o vetor A
	for(int i = p; i <= r; i++){
		A[i] = B[i-p];
	}
}

// Algoritmo Merge Sort
// Ordena um vetor A[0..n-1]
void MergeSort(int A[], int p, int r){
	if(p < r){
		int q = (p + r) / 2; // Dividir
		// Conquistar
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		// Combinar
		Intercala(A, p, q, r);
	}
}

// Algorítmo auxiliar ao Quick Sort
// Entrada: vetores crescentes A[l...j-1] e A[j+1...r]
int partition(int A[], int l, int r){
    int pivo = A[r];
    int j = l;
    for(int i=l; i<r; i++){
        if(A[i] <= pivo){
            int aux = A[i];
            A[i] = A[j];
            A[j++] = aux;
        }
    }
    A[r] = A[j];
    A[j] = pivo;
    return j;
}

// Algoritmo QuickSort
// Ordena um vetor A[0..n-1]
void QuickSort(int A[], int l, int r){
    if(l<r){
        int j = partition(A, l, r);
        QuickSort(A, l, j-1);
        QuickSort(A, j+1, r);
    }
}

// Algoritmo Shell Sort
// Ordena um vetor A[0..n-1]
void ShellSort(int n, int A[]){

}

// Algoritmo Heap Sort
// Ordena um vetor A[0..n-1]
void HeapSort(int n, int A[]){

}

// Algoritmo Comb Sort
// Ordena um vetor A[0..n-1]
void CombSort(int n, int A[]){

}

// Algoritmo Gnome Sort
// Ordena um vetor A[0..n-1]
void GnomeSort(int n, int A[]){

}

// Algoritmo Odd-even Sort
// Ordena um vetor A[0..n-1]
void OddEvenSort(int n, int A[]){

}