#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Gera um vetor de números aleatórios.
 *
 * Esta função gera um vetor contendo números aleatórios entre 0 e 1000.
 *
 * @param n O número de números a serem gerados.
 * @return Um vetor contendo os números gerados.
 */
vector<int> geradorNumeros(int n) {
    vector<int> numeros(n);
    for (int i = 0; i < n; i++) {
        numeros[i] = rand() % 1001;
    }
    return numeros;
}

/**
 * @brief Salva um vetor de inteiros em um arquivo de texto.
 *
 * Esta função salva os números inteiros contidos no vetor em um arquivo .txt.
 *
 * @param numeros O vetor de inteiros a ser salvo.
 * @param nomeArquivo O nome do arquivo onde os números serão salvos.
 */
void salvarEmArquivo(const vector<int>& numeros, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (int numero : numeros) {
            arquivo << numero << endl;
        }
        arquivo.close();
        cout << "Arquivo " << nomeArquivo << " salvo com sucesso!" << endl;
    } else {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int tamanhos[] = {1000, 10000, 100000};
    string nomesArquivos[] = {"lista_1000.txt", "lista_10000.txt", "lista_100000.txt"};

    for (int i = 0; i < 3; i++) {
        vector<int> numeros = geradorNumeros(tamanhos[i]);
        salvarEmArquivo(numeros, nomesArquivos[i]);
    }

    return 0;
}
