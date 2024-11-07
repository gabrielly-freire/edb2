#include "question3.hpp"

/**
 * @brief Troca dois elementos de um vetor.
 * 
 * Função auxiliar para trocar dois elementos de um vetor.
 * 
 * @param v O vetor onde a troca será realizada.
 * @param i O índice do primeiro elemento.
 * @param j O índice do segundo elemento.
 */
void Ordenacao::trocar(int *v, int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

/**
 * @brief Junta dois sub-vetores em um único vetor ordenado.
 * 
 * Função auxiliar para o Merge Sort.
 * 
 * @param v O vetor que contém os sub-vetores a serem juntados.
 * @param n O tamanho total do vetor.
 * @param m O ponto de divisão entre os dois sub-vetores.
 */
void Ordenacao::juntar(int *v, int n, int m) {
    int i = 0, pp = 0, qq = m;

    int *tmp = (int *) malloc(n*sizeof(int));

    while(pp < m && qq < n){
        if(v[pp] < v[qq]){
            tmp[i++] = v[pp++];
        } else {
            tmp[i++] = v[qq++];
        }
    }

    while(pp < m){
        tmp[i++] = v[pp++];
    }
    while(qq < n){
        tmp[i++] = v[qq++];
    }

    for(i = 0; i < n; i++){
        v[i] = tmp[i];
    }
    free(tmp);
}

/**
 * @brief Separa um vetor em duas partes.
 * 
 * Função auxiliar para o Quick Sort.
 * 
 * @param v O vetor a ser separado.
 * @param n O tamanho do vetor.
 */
int Ordenacao::separar(int *v, int n) {
    if (n <= 0) return -1;

    int pivo = v[0];
    int pp = 1;
    int qq = n - 1;

    while (pp <= qq) {
    while (pp < n && v[pp] < pivo) {
        pp++;
    }
    while (qq >= 0 && v[qq] > pivo) {
        qq--;
    }
    
    if (pp <= qq) {
        trocar(v, pp, qq);
        pp++;
        qq--;
    }
}

    trocar(v, 0, qq);
    return qq;
}

int Ordenacao::min(int a, int b){
    return a < b ? a : b;
}

/**
 * @brief Ordena um vetor usando o algoritmo Bubble Sort de forma iterativa.
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void Ordenacao::bubblesort_iterativo(int *v, int n){
     bool trocou = true;
    int i = 0;

    while (i < n - 1) {
        if (trocou) {
            trocou = false;
            int j = 0;

            while (j < (n - i - 1)) {
                if (v[j] > v[j + 1]) {
                    trocar(v, j, j + 1);

                    trocou = true;
                }
                j++;
            }
        }
        i++;
    }
}

/**
 * @brief Ordena um vetor usando o algoritmo Bubble Sort de forma recursiva.
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void Ordenacao::bubblesort_recursivo(int *v, int n) {
    if (n == 1) return; 

    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) {
            trocar(v, i - 1, i);
        }
    }
    
    bubblesort_recursivo(v, n - 1);
}

/**
 * @brief Ordena um vetor usando o algoritmo Merge Sorte de forma iterativa
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void Ordenacao::mergesort_iterativo(int *v, int n){
    int *temp = (int*) malloc(n * sizeof(int));
    for (int tamanho = 1; tamanho < n; tamanho *= 2) {
        for (int inicio = 0; inicio < n; inicio += 2 * tamanho) {
            int meio = min(inicio + tamanho, n);
            int fim = min(inicio + 2 * tamanho, n);
            int i = inicio, j = meio, k = 0;

            while (i < meio && j < fim) {
                temp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
            }
            while (i < meio) {
                temp[k++] = v[i++];
            }
            while (j < fim) {
                temp[k++] = v[j++];
            }
            for (i = inicio, k = 0; i < fim; i++, k++) {
                v[i] = temp[k];
            }
        }
    }
    free(temp);
}

/**
 * @brief Ordena um vetor usando o algoritmo Merge Sort de forma recursiva.
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void Ordenacao::mergesort_recursivo(int *v, int n){
    if(n <= 1)
        return;
    int meio = n/2;
    mergesort_recursivo(v, meio);
    mergesort_recursivo(v+meio, n-meio);
    juntar(v, n, meio);
}

/**
 * @brief Ordena um vetor usando o algoritmo Quick Sort de forma iterativa
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void Ordenacao::quicksort_iterativo(int *v, int n) {
    std::stack<int> pilha;

    pilha.push(0);
    pilha.push(n - 1);

    while (!pilha.empty()) {
        int fim = pilha.top(); 
        pilha.pop();
        int inicio = pilha.top();
        pilha.pop();

        if (inicio >= fim)
            continue;

        int pivoIndex = separar(v + inicio, fim - inicio + 1) + inicio; 

        pilha.push(inicio); 
        pilha.push(pivoIndex - 1);
        pilha.push(pivoIndex + 1);
        pilha.push(fim);
    } 
}

/**
 * @brief Ordena um vetor usando o algoritmo Quick Sort de forma recursiva
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void Ordenacao::quicksort_recursivo(int *v, int n){
    if (n <= 1){
        return;
    }

    int meio = separar(v, n);
    quicksort_recursivo(v, meio);
    quicksort_recursivo(v + meio + 1, n - meio - 1);
}
