#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Troca dois elementos de um vetor.
 * 
 * Função auxiliar para trocar dois elementos de um vetor.
 * 
 * @param v O vetor onde a troca será realizada.
 * @param i O índice do primeiro elemento.
 * @param j O índice do segundo elemento.
 */
void troca(int *v, int i, int j){
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
void juntar(int *v, int n, int m) {
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
int separacao(int *v, int n){
    int pivo = v[0], pp= 1, qq = n - 1;

    while (qq > pp){
        while (v[pp] < pivo){
            pp++;
        }
        while (v[qq] > pivo){
            qq--;
        }
        if(pp < qq){
            troca(v, pp, qq);
        }
    }
    troca(v, 0, qq);
    return qq;
}

/**
 * @brief Ordena um vetor usando o algoritmo Bubble Sort de forma iterativa.
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void bubblesort(int *v, int n){
    bool conflito;
    do{
        conflito = false;
        for(int i = 1; i < n; i++){
            if (v[i-1] > v[i]){
                troca(v, i-1, i);
                conflito = true;
            }
        }
    }while (conflito);
}

/**
 * @brief Ordena um vetor usando o algoritmo Bubble Sort de forma recursiva.
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void bubblesort_recursivo(int *v, int n) {
    if (n == 1) return; 

    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) {
            troca(v, i - 1, i);
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
void mergesort(int *v, int n){

}

/**
 * @brief Ordena um vetor usando o algoritmo Merge Sort de forma recursiva.
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void mergesort_recursivo(int *v, int n){
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
void quicksort(int *v, int n){

}

/**
 * @brief Ordena um vetor usando o algoritmo Quick Sort de forma recursiva
 * 
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
void quicksort_recursivo(int *v, int n){
    if (n <= 1){
        return;
    }

    int meio = separacao(v, n);
    quicksort_recursivo(v, meio);
    quicksort_recursivo(v + meio + 1, n - meio - 1);
}

int main(){

    return 0;
}