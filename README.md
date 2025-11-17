QUICK SORT - ANALISE DE DESEMPENHO (RGM)
1. DESCRICAO DO PROJETO
Este e um projeto em C que implementa o algoritmo de ordenacao Quick Sort utilizando o esquema de Particao de Lomuto.
O objetivo e ordenar os digitos de um RGM (Registro Geral de Matricula) e analisar o desempenho do algoritmo para este conjunto de dados.
O codigo rastreia e exibe as metricas de desempenho:
Numero de comparacoes.
Numero de trocas (swaps).
Tempo de execucao em milissegundos (ms).
2. RGM UTILIZADO
O programa esta configurado para ordenar os digitos do seguinte RGM:
code
C
const char *rgm = "44947615";
3. PRE-REQUISITOS
E necessario ter um compilador C instalado no sistema (ex: GCC, Clang).
4. COMPILACAO E EXECUCAO
Siga os passos no terminal:
Salve o codigo fonte em um arquivo (ex: quick_sort_rgm.c).
Compile usando o GCC (ou seu compilador preferido):
code
Bash
gcc quick_sort_rgm.c -o quick_sort_rgm
Execute o programa compilado:
code
Bash
./quick_sort_rgm
5. EXEMPLO DE SAIDA
Ao executar, o programa ira mostrar o vetor original, o vetor ordenado e, por fim, as metricas em dois formatos: detalhado e CSV.
Saida de Metricas (Estrutura):
code
Code
metodo,N,caso,comparacoes,trocas,tempo_ms
quick_sort,8,rgm,XX,YY,Z.ZZZZZZ

========================================
  METRICAS DETALHADAS
========================================
...
Comparações:  XX
Trocas:       YY
Tempo:        Z.ZZZZZZ ms
...
Nota: XX, YY e Z.ZZZZZZ serao substituidos pelos valores reais de metricas e tempo.
