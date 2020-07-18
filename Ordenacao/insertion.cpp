#include <iostream>
using namespace std;

void OrdenaPorInsercao(int Vet[], int n) {
    int eleito, i, j;

    //Repeticao para as posicoes 1 (segundo valor) ate n
    for(i = 1; i < n; i++) {
        //Valor eleito inicia a partir do segundo elemento do vetor
        eleito = Vet[i];
        j = i - 1;
        
        //Laço que percorre os elementos à esquerda dos numeros eleitos
        //Ou ate encontrar a posicao para recolocacao do numero eleito
        while (j >= 0 && Vet[j] > eleito) {
            Vet[j+1] = Vet[j];
            j = j - 1;
        }
        Vet[j + 1] = eleito;
    }
}

int main() {
    int n = 10, i, V[n];

    for(i = 0; i < n; i++) {
        cout << i + 1 << "° Valor: ";
        cin >> V[i];
    }

    //Ordena os valores - crescente
    OrdenaPorInsercao(V, n);

    cout << "Valores ordenados: " << endl;
    for(i = 0; i < n; i++) {
        cout << "V[" << i + 1 << "]: " << V[i] << endl;
    }

    return(0);
}