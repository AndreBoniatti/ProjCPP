#include <iostream>
using namespace std;

void OrdenaPorBolha(int Vet[], int n) {
    int aux, i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = i +1; j < n; j++) {
            if (Vet[i] > Vet[j]) {
                aux = Vet[i];
                Vet[i] = Vet[j];
                Vet[j] = aux;
            }
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
    OrdenaPorBolha(V, n);

    cout << "Valores ordenados: " << endl;
    for(i = 0; i < n; i++) {
        cout << "V[" << i + 1 << "]: " << V[i] << endl;
    }

    return(0);
}