#include <iostream>
using namespace std;

//Ordena os valores - crescente
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

    int n = 5, V[n], num_procurado, inicio, fim, meio;
    bool achou;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " Valor:";
        cin >> V[i];
    }

    //Ordena o vetor com algum método de ordenação
    OrdenaPorBolha(V, n);

    cout << "Informe o número procurado:";
    cin >> num_procurado;

    //Procura o valor
    achou = false;
    inicio = 0;
    fim = n - 1;
    meio = (inicio + fim) / 2;

    while (inicio <= fim && achou == false)
    {
        if (V[meio] == num_procurado) {
            achou = true;
        } else {
            if (num_procurado < V[meio]) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
            meio = (inicio + fim) / 2;
        }
    }
    
    if (achou == false) {
        cout << "O número " << num_procurado << " não encontra-se no vetor." << endl;
    } else {
        cout << "O número " << num_procurado << " foi encontrado na posição " << meio + 1 << endl;
    }

    return(0);
}