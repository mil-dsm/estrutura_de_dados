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

# Criar o gráfico
plt.figure(figsize=(12,7))

plt.plot(
    t_bubble, tempo_bubble,
    color='#1f77b4',     # azul
    marker='o',          # marcador circular
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Bubble Sort'
)

plt.plot(
    t_oddeven, tempo_oddeven,
    color='#ff7f0e',     # laranja
    marker='s',          # marcador quadrado
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Odd-even Sort'
)

plt.plot(
    t_insertion, tempo_insertion,
    color='#2ca02c',     # verde
    marker='^',          # marcador triangular
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Insertion Sort'
)

plt.plot(
    t_selection, tempo_selection,
    color='#d62728',     # vermelho
    marker='v',          # marcador triangular invertido
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Selection Sort'
)

plt.plot(
    t_merge, tempo_merge,
    color='#9467bd',     # roxo
    marker='>',          # marcador de seta para a direita
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Merge Sort'
)

plt.plot(
    t_quick, tempo_quick,
    color='#8c564b',     # marrom
    marker='<',          # marcador de seta para a esquerda
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Quick Sort'
)

# Estilo do gráfico
plt.xlabel("Tamanho do Vetor", fontsize=14, fontweight='bold')
plt.ylabel("Microssegundos", fontsize=14, fontweight='bold')
plt.title("Comparativo dos Algoritmos de Ordenação", fontsize=16, fontweight='bold')
plt.grid(True, linestyle='--', alpha=0.6)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(fontsize=12)

import matplotlib.ticker as mticker

ax = plt.gca()
ax.ticklabel_format(style='plain', axis='y', useOffset=False)
ax.yaxis.set_major_formatter(mticker.StrMethodFormatter('{x:.0f}'))
ax.get_yaxis().get_offset_text().set_visible(False)

# Salvar e mostrar
plt.tight_layout()
plt.savefig(arquivo_saida, dpi=300)
plt.show()