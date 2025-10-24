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
// Ordena um vetor A[0..n-1] usando sequência de intervalos H[]
void ShellSort(int n, int A[], int m, int H[]) {
    for(int k=0; k<m; k++){  // percorre cada intervalo H[k]
        int h = H[k];
        for (int i=h; i<n; i++){
            int atual = A[i];
            int j = i - h;
            while(j>=0 && A[j]>atual){
                A[j+h] = A[j];
                j -= h;
            }
            A[j+h] = atual;
        }
    }
}

// Algoritmo Heap Sort
// Ordena um vetor A[0..n-1]
void Heapify(int A[], int n, int i){
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    if(esq < n && A[esq] > A[maior]){
        maior = esq;
    }
    if(dir < n && A[dir] > A[maior]){
        maior = dir;
    }
    if(maior != i){
        int aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        Heapify(A, n, maior);
    }
}

void ConstroiHeap(int A[], int n){
    for (int i=n/2-1; i>=0; i--){
        Heapify(A, n, i);
    }
}

void HeapSort(int A[], int n){
    ConstroiHeap(A, n);
    for (int i=n-1; i>0; i--){
        int aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        Heapify(A, i, 0);
    }
}

// Algoritmo Comb Sort
// Ordena um vetor A[0..n-1]
void CombSort(int n, int A[]){
    int gap = n;
    const float shrink = 1.3;
    int trocou = 1;
    while (gap > 1 || trocou){
        gap = (int)(gap / shrink);
        if (gap < 1){
            gap = 1;
        }
        trocou = 0;
        for(int i=0; i+gap<n; i++){
            if(A[i] > A[i+gap]){
                int temp = A[i];
                A[i] = A[i+gap];
                A[i+gap] = temp;
                trocou = 1;
            }
        }
    }
}

// Algoritmo Gnome Sort
// Ordena um vetor A[0..n-1]
void GnomeSort(int n, int A[]){
    int i = 0;
    while(i < n){
        if(i == 0 || A[i] >= A[i-1]){
            i++;
        }
        else{
            int aux = A[i];
            A[i] = A[i-1];
            A[i-1] = aux;
            i--;
        }
    }
}

// Algoritmo Odd-Even Sort (Brick Sort)
// Ordena um vetor A[0..n-1]
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