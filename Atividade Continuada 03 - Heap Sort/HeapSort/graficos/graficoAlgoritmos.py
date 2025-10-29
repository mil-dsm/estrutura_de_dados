# Algoritmos de ordenação
# Disciplina: Estruturas de Dados
# Turma: 01A
# Nome: Milena de Sousa Mesquita
# Matrícula: 581180

import os
import matplotlib.pyplot as plt

# Caminho dos arquivos
diretorio_script = os.path.dirname(os.path.abspath(__file__))
arquivo_bubble = os.path.join(diretorio_script, "../resultados/resultadoBubble.txt")
arquivo_oddeven = os.path.join(diretorio_script, "../resultados/resultadoOddeven.txt")
arquivo_insertion = os.path.join(diretorio_script, "../resultados/resultadoInsertion.txt")
arquivo_selection = os.path.join(diretorio_script, "../resultados/resultadoSelection.txt")
arquivo_merge = os.path.join(diretorio_script, "../resultados/resultadoMerge.txt")
arquivo_quick = os.path.join(diretorio_script, "../resultados/resultadoQuick.txt")
arquivo_saida = os.path.join(diretorio_script, "comparativoAlgoritmos.png")

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
t_bubble, tempo_bubble = ler_dados(arquivo_bubble)
t_oddeven, tempo_oddeven = ler_dados(arquivo_oddeven)
t_insertion, tempo_insertion = ler_dados(arquivo_insertion)
t_selection, tempo_selection = ler_dados(arquivo_selection)
t_merge, tempo_merge = ler_dados(arquivo_merge)
t_quick, tempo_quick = ler_dados(arquivo_quick)

# Converter segundos para microssegundos (opcional)
tempo_bubble   = [t * 1e6 for t in tempo_bubble]
tempo_oddeven  = [t * 1e6 for t in tempo_oddeven]
tempo_insertion = [t * 1e6 for t in tempo_insertion]
tempo_selection = [t * 1e6 for t in tempo_selection]
tempo_merge    = [t * 1e6 for t in tempo_merge]
tempo_quick    = [t * 1e6 for t in tempo_quick]

# Criar o gráfico
plt.figure(figsize=(12,7))

plt.plot(
    t_bubble, tempo_bubble,
    color='#1f77b4',
    marker='o',
    markersize=6,
    linestyle='-',
    linewidth=2,
    label='Bubble Sort'
)

plt.plot(
    t_oddeven, tempo_oddeven,
    color='#ff7f0e',
    marker='s',
    markersize=6,
    linestyle='-',
    linewidth=2,
    label='Odd-even Sort'
)

plt.plot(
    t_insertion, tempo_insertion,
    color='#2ca02c',
    marker='^',
    markersize=6,
    linestyle='-',
    linewidth=2,
    label='Insertion Sort'
)

plt.plot(
    t_selection, tempo_selection,
    color='#d62728',
    marker='v',
    markersize=6,
    linestyle='-',
    linewidth=2,
    label='Selection Sort'
)

plt.plot(
    t_merge, tempo_merge,
    color='#9467bd',
    marker='>',
    markersize=6,
    linestyle='-',
    linewidth=2,
    label='Merge Sort'
)

plt.plot(
    t_quick, tempo_quick,
    color='#8c564b',
    marker='<',
    markersize=6,
    linestyle='-',
    linewidth=2,
    label='Quick Sort'
)

# Estilo do gráfico
plt.xlabel("Tamanho do Vetor", fontsize=14, fontweight='bold')
plt.ylabel("Microssegundos", fontsize=14, fontweight='bold')
plt.title("Comparativo de Desempenho dos Algoritmos de Ordenação", fontsize=16, fontweight='bold')
plt.grid(True, linestyle='--', alpha=0.6)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(fontsize=12, loc='upper left', bbox_to_anchor=(1,1))

# Formatação dos números
plt.ticklabel_format(style='plain', axis='y')
plt.tight_layout()
plt.savefig(arquivo_saida, dpi=300)
plt.show()