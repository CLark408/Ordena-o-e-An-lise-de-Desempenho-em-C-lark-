#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ============================================================================
// ESTRUTURA DE MÉTRICAS
// ============================================================================

typedef struct {
    long long comparacoes;
    long long trocas;
} Metricas;

// Macros para facilitar a contagem
#define CONTAR_COMPARACAO(m) ((m)->comparacoes++)
#define CONTAR_TROCA(m) ((m)->trocas++)

// ============================================================================
// FUNÇÕES AUXILIARES
// ============================================================================

void resetar_metricas(Metricas *m) {
    m->comparacoes = 0;
    m->trocas = 0;
}

void trocar(int *a, int *b, Metricas *m) {
    CONTAR_TROCA(m);
    int temp = *a;
    *a = *b;
    *b = temp;
}

void imprimir_vetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
    }
}

void copiar_vetor(int *destino, int *origem, int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

// ============================================================================
// QUICK SORT - PARTIÇÃO LOMUTO
// ============================================================================

int particionar(int *v, int inicio, int fim, Metricas *m) {
    int pivo = v[fim];
    int i = inicio - 1;
    
    for (int j = inicio; j < fim; j++) {
        CONTAR_COMPARACAO(m);
        if (v[j] <= pivo) {
            i++;
            if (i != j) {
                trocar(&v[i], &v[j], m);
            }
        }
    }
    
    if (i + 1 != fim) {
        trocar(&v[i + 1], &v[fim], m);
    }
    
    return i + 1;
}

void quick_sort_recursivo(int *v, int inicio, int fim, Metricas *m) {
    if (inicio < fim) {
        int pi = particionar(v, inicio, fim, m);
        quick_sort_recursivo(v, inicio, pi - 1, m);
        quick_sort_recursivo(v, pi + 1, fim, m);
    }
}

void quick_sort(int *v, int n, Metricas *m) {
    resetar_metricas(m);
    if (n > 1) {
        quick_sort_recursivo(v, 0, n - 1, m);
    }
}

// ============================================================================
// FUNÇÃO DE BENCHMARK
// ============================================================================

double executar_ordenacao(int *v, int n, Metricas *m, int *v_ordenado) {
    copiar_vetor(v_ordenado, v, n);
    
    clock_t inicio = clock();
    quick_sort(v_ordenado, n, m);
    clock_t fim = clock();
    
    double tempo_ms = 1000.0 * (fim - inicio) / CLOCKS_PER_SEC;
    
    return tempo_ms;
}

// ============================================================================
// CONVERSÃO DO RGM
// ============================================================================

int* converter_rgm_para_vetor(const char *rgm, int *tamanho) {
    *tamanho = strlen(rgm);
    int *vetor = (int *)malloc(*tamanho * sizeof(int));
    
    for (int i = 0; i < *tamanho; i++) {
        vetor[i] = rgm[i] - '0';
    }
    
    return vetor;
}

// ============================================================================
// FUNÇÃO PRINCIPAL
// ============================================================================

int main() {
    const char *rgm = "44947615";
    
    int tamanho;
    int *digitos = converter_rgm_para_vetor(rgm, &tamanho);
    int *digitos_ordenados = (int *)malloc(tamanho * sizeof(int));
    
    // Exibe RGM original
    printf("RGM original: ");
    imprimir_vetor(digitos, tamanho);
    printf("\n");
    
    // Executa ordenação
    Metricas metricas;
    double tempo_ms = executar_ordenacao(digitos, tamanho, &metricas, digitos_ordenados);
    
    // Exibe RGM ordenado
    printf("RGM ordenado: ");
    imprimir_vetor(digitos_ordenados, tamanho);
    printf("\n\n");
    
    // Calcula total de passos (comparações + trocas)
    long long passos_totais = metricas.comparacoes + metricas.trocas;
    
    // Saída em formato CSV
    printf("=== RESUMO EM FORMATO CSV ===\n");
    printf("metodo,N,caso,passos,tempo_ms\n");
    printf("quick_sort,%d,rgm,%lld,%.6f\n", 
           tamanho, 
           passos_totais,
           tempo_ms);
    
    // Libera memória
    free(digitos);
    free(digitos_ordenados);
    
    return 0;
}
