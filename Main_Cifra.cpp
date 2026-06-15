#include <iostream>
#include <fstream>
#include <sstream>
#include "Cifra.hpp"

using namespace std;

int main() {
    Cifra maquinaEnigma;
    
    cout << "Preparando modulo de inteligencia (ordenando dicionario)..." << endl;
    maquinaEnigma.carregarEOrdenarDicionario("Base de dados/words.txt");

    // Lendo a mensagem que será interceptada
    ifstream arquivoOriginal("Base de dados/mensagem_secreta.txt");
    stringstream buffer;
    buffer << arquivoOriginal.rdbuf();
    string textoOriginal = buffer.str();
    
    if (textoOriginal.empty()) {
        textoOriginal = "projeto de estrutura de dados finalizado com sucesso"; // Fallback caso arquivo falhe
    }

    cout << "\n=== 1. INTERCEPTACAO ===" << endl;
    string textoCifrado = maquinaEnigma.cifrar(textoOriginal, 7); // Cifrando com chave 7 (que o algoritmo não sabe)
    cout << "Mensagem capturada: " << textoCifrado << endl;

    cout << "\n=== 2. QUEBRA DA CIFRA ===" << endl;
    // O algoritmo não recebe a chave 7, ele precisa descobrir sozinho cruzando dados
    maquinaEnigma.quebrarCifra(textoCifrado);

    return 0;
}