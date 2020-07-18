#include <iostream>
using namespace std;

void OrdenaPorSelecao(int Vet[], int n) {
    int eleito, menor, pos, i, j;
    for(i = 0; i < n - 1; i++) {
        //Encontra o menor numero e a sua posicao a direita do eleito
        eleito = Vet[i];
        //Primeiro numero a direita é o menor
        menor = Vet[i + 1];
        //A posicao é sempre a proxima
        pos = i + 1; 
        for(j = i + 1; j < n; j++) {
            if (Vet[j] < menor) {
                menor = Vet[j];
                pos = j;
            }
        }
        //Troca o numero eleito com o numero da posicao pos 
        //O numero da posicao pos é o menor numero a direita do numero eleito
        if (menor < eleito) {
            Vet[i] = Vet[pos];
            Vet[pos] = eleito;
        }
    }
}

int main() {
    int n = 10, i, V[n];

    for(i = 0; i < n; i++) {
        cout << i + 1 << "° Valor: ";
        cin >> V[i];
    }

    //Ordena os valores - crescente
    OrdenaPorSelecao(V, n);

    cout << "Valores ordenados: " << endl;
    for(i = 0; i < n; i++) {
        cout << "V[" << i + 1 << "]: " << V[i] << endl;
    }

    return(0);
}