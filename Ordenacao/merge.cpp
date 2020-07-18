#include <iostream>
using namespace std;

void Intercala(int Vet[], int inicio, int fim, int meio) {
    int poslivre, inicio_vetor1, inicio_vetor2, i;
    int aux[fim + 1];

    inicio_vetor1 = inicio;
    inicio_vetor2 = meio + 1;
    poslivre = inicio;

    while (inicio_vetor1 <= meio && inicio_vetor2 <= fim) {
        if (Vet[inicio_vetor1] <= Vet[inicio_vetor2]) {
            aux[poslivre] = Vet[inicio_vetor1];
            inicio_vetor1++;
        } else {
            aux[poslivre] = Vet[inicio_vetor2];
            inicio_vetor2++;
        }
        poslivre++;
    }

    //Se ainda não existem numeros do primeiro vetor que não foram intercalados
    for (i = inicio_vetor1; i <= meio; i++) {
        aux[poslivre] = Vet[i];
        poslivre++;
    }

    //Se ainda não existem numeros do segundo vetor que nao foram intercalados
    for (i = inicio_vetor2; i <= fim; i++) {
        aux[poslivre] = Vet[i];
        poslivre++;
    }

    //Atribui os valores do vetor aux para o vetor Vet
    for (i = inicio; i <= fim; i++) {
        Vet[i] = aux[i];
    }
}

void OrdenaPorMerge(int Vet[], int inicio, int fim) {
    int meio = 0;
     if (inicio < fim) {
         meio = (inicio + fim) / 2;
         OrdenaPorMerge(Vet, inicio, meio);
         OrdenaPorMerge(Vet, meio + 1, fim);

         Intercala(Vet, inicio, fim, meio);
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
    OrdenaPorMerge(V, inicio, fim);


    //Escreve os valores
    cout << "Valores ordenados: " << endl;
    for(i = 0; i < n; i++) {
        cout << "V[" << i + 1 << "]: " << V[i] << endl;
    }

    return(0);
}