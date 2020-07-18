#include <iostream>
using namespace std;

void OrdenaPorShell(int Vet[], int n) {
    int i, j, value, h = 1;
     
    while (h < n) {
         h = 3 * h + 1;
    }

    while (h > 1) {
        h /= 3;
        for (i = h; i < n; i++) {
            value = Vet[i];
            j = i - h;

            while (j >= 0 && value < Vet[j]) {
                Vet[j + h] = Vet[j];
                j -= h;
            }
            Vet[j + h] = value;
        }
    }
}

int main() {
    int n = 5, i, V[n];

    //Le os valores
    for(i = 0; i < n; i++) {
        cout << i + 1 << "° Valor: ";
        cin >> V[i];
    }

    //Ordena os valores - crescente
    OrdenaPorShell(V, n);


    //Escreve os valores
    cout << "Valores ordenados: " << endl;
    for(i = 0; i < n; i++) {
        cout << "V[" << i + 1 << "]: " << V[i] << endl;
    }

    return(0);
}