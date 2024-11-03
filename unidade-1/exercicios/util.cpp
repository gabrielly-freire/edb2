#include "util.hpp"

/**
 * @brief Gera um vetor de numeros aleatórias.
 *
 * Esta função gera um vetor contendo numeros aleatórias entre 0 e 100.
 *
 * @param n O número de numeros a serem geradas.
 * @return Um vetor contendo as numeros geradas.
 */
vector<int> Util::gerarNumeros(int n) {
    vector<int> numeros(n);
    for (int i = 0; i < n; i++) {
        numeros[i] = rand() % 101;
    }
    return numeros;
}

