# Algoritmos de ordenação
# Disciplina: Estruturas de Dados
# Turma: 01A
# Nome: Milena de Sousa Mesquita
# Matrícula: 581180

import os
import matplotlib.pyplot as plt

# Caminho dos arquivos
diretorio_script = os.path.dirname(os.path.abspath(__file__))
arquivo_heap = os.path.join(diretorio_script, "../resultados/resultadoHeap.txt")
arquivo_merge = os.path.join(diretorio_script, "../resultados/resultadoMerge.txt")
arquivo_quick = os.path.join(diretorio_script, "../resultados/resultadoQuick.txt")
arquivo_saida = os.path.join(diretorio_script, "comparativoAlgoritmos_nlogn.png")

# Função para ler arquivo com duas colunas
def ler_dados(caminho):
    tamanhos = []
    tempos = []
    with open(caminho, 'r') as f:
        for linha in f:
            if linha.strip() == "":
                continue
            partes = linha.split()
            tamanhos.append(int(partes[0]))
            tempos.append(float(partes[1]))
    return tamanhos, tempos

# Ler os dados
t_heap, tempo_heap = ler_dados(arquivo_heap)
t_merge, tempo_merge = ler_dados(arquivo_merge)
t_quick, tempo_quick = ler_dados(arquivo_quick)

# Criar o gráfico
plt.figure(figsize=(12,7))

# 🔹 Merge Sort
plt.plot(
    t_merge, tempo_merge,
    color='#ff7f0e',   # laranja
    linestyle='-',
    linewidth=2,
    label='MergeSort (O(n log n))'
)

# 🔹 Quick Sort
plt.plot(
    t_quick, tempo_quick,
    color='#2ca02c',   # verde
    linestyle='-',
    linewidth=2,
    label='QuickSort (O(n log n))'
)

# 🔹 Heap Sort
plt.plot(
    t_heap, tempo_heap,
    color='#9467bd',   # roxo
    linestyle='-',
    linewidth=2,
    label='HeapSort (O(n log n))'
)

# Estilo do gráfico
plt.xlabel("Tamanho do Vetor", fontsize=14, fontweight='bold')
plt.ylabel("Microssegundos", fontsize=14, fontweight='bold')
plt.title("Algoritmos O(n log n)", fontsize=16, fontweight='bold')
plt.grid(True, linestyle='--', alpha=0.6)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(fontsize=12)

# 🔸 Escala logarítmica no eixo Y
plt.yscale("log")

# 🔸 Formatação científica leve no eixo Y (10², 10³, 10⁴)
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))

# Salvar e mostrar
plt.tight_layout()
plt.savefig(arquivo_saida, dpi=300)
plt.show()