#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

/**
 * @brief Gera um vetor de idades aleatórias.
 *
 * Esta função gera um vetor contendo idades aleatórias entre 0 e 100.
 *
 * @param n O número de idades a serem geradas.
 * @return Um vetor contendo as idades geradas.
 */
vector<int> geraIdades(int n) {
    vector<int> idades(n);
    for (int i = 0; i < n; i++) {
        idades[i] = rand() % 101;
    }
    return idades;
}

/**
 * @brief Verifica se a menor idade é repetida.
 *
 * Esta função verifica se a menor idade no vetor é repetida.
 *
 * @param idades Um vetor de inteiros representando as idades.
 * @return true Se a menor idade for repetida, false caso contrário.
 */
bool idadeRep(vector<int> idades) {
    int tam = idades.size();
    int menor = 200;
    int pos = 0;

    for (int i = 0; i < tam; i++) {
        if (idades[i] < menor) {
            menor = idades[i];
            pos = i;
        }
    }

    for (int i = 0; i < tam; i++) {
        if (idades[i] == menor && i != pos) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Verifica se a menor idade é repetida.
 *
 * Esta função ordena o vetor e verifica se o menor elemento se repete.
 *
 * @param idades Um vetor de inteiros representando as idades.
 * @return true Se houver idades repetidas, false caso contrário.
 */
bool idadeRep2(vector<int> idades) {
   sort(idades.begin(), idades.end());
    return idades[0]==idades[1];
}

/**
 * @brief Mede o tempo de execução de uma função.
 *
 * Esta função mede quanto tempo uma função leva para ser executada
 * e imprime o resultado em milissegundos.
 *
 * @param func Um ponteiro para a função a ser medida.
 * @param idades Um vetor de inteiros que será passado para a função.
 */
void medeTempo(bool (*func)(vector<int>), vector<int>& idades) {
    auto start = chrono::high_resolution_clock::now();
    func(idades);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;
    cout << "Tempo de execução: " << duration.count() << " ms" << endl;
}

/**
 * @brief Função principal.
 * 
 * A função principal realiza testes com diferentes tamanhos de vetores
 * 
 * @return a função principal retorna 0.
 */
int main() {
    srand(time(0));

    cout << "Teste com n = 100:" << endl;
    vector<int> idades100 = geraIdades(100);
    medeTempo(idadeRep, idades100);
    medeTempo(idadeRep2, idades100);

    cout << "\nTeste com n = 1000:" << endl;
    vector<int> idades1000 = geraIdades(1000);
    medeTempo(idadeRep, idades1000);
    medeTempo(idadeRep2, idades1000);

    cout << "\nTeste com n = 1.000.000:" << endl;
    vector<int> idades10000 = geraIdades(10000);
    medeTempo(idadeRep, idades10000);
    medeTempo(idadeRep2, idades10000);

    return 0;
}
