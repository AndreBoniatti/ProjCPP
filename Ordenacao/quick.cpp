#include <iostream>
using namespace std;

void troca(int Vet[], int i, int j) {
    int aux;
    aux = Vet[i];
    Vet[i] = Vet[j];
    Vet[j] = aux;
}

int particao (int Vet[], int inicio, int fim) {
    int pivo, esquerda, direita;
    pivo = Vet[(inicio + fim) / 2];
    esquerda = inicio - 1;
    direita =  fim + 1;

    while (esquerda < direita) {
        do {
            direita--;
        } while (Vet[direita] > pivo);

        do {
            esquerda++;
        } while (Vet[esquerda] < pivo);

        if (esquerda < direita) troca(Vet, esquerda, direita);
    }
    return direita;
}

void OrdenaPorQuick(int Vet[], int inicio, int fim) {
    int meio;
     if (inicio < fim) {
         meio = particao(Vet, inicio, fim);
         OrdenaPorQuick(Vet, inicio, meio);
         OrdenaPorQuick(Vet, meio + 1, fim);
    }
}

int main() {
    int n = 5, V[n], i, inicio = 0, fim = n - 1;

    //Le os valores
    for(i = 0; i < n; i++) {
        cout << i + 1 << "° Valor: ";
        cin >> V[i];
    }

    //Ordena os valores - crescente
    OrdenaPorQuick(V, inicio, fim);


    //Escreve os valores
    cout << "Valores ordenados: " << endl;
    for(i = 0; i < n; i++) {
        cout << "V[" << i + 1 << "]: " << V[i] << endl;
    }

    return(0);
}