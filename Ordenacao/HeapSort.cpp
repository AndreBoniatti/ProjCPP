#include<iostream>
using namespace std;

void HeapFica(int Vet[], int i, int n) {
    int filho_esquerda, filho_direita, maior, aux;
    maior = 1;

    //O nó que esta sendo analisado tem filhos na esquerda e na direita
    if (2*i+1 <= n) {
        filho_esquerda = 2*i;
        filho_direita = 2*i+1;
        if ((Vet[filho_esquerda] >= Vet[filho_direita]) && (Vet[filho_esquerda] > Vet[i]))
            maior = 2*i;
        else if ((Vet[filho_direita] > Vet[filho_esquerda]) && (Vet[filho_direita] > Vet[i]))
            maior = 2*i+1;
    }

    // O nó que esta sendo analisado tem filhos apenas na esquerda
    else if (2*i <= n) {
        filho_esquerda = 2*i;
        if (Vet[filho_esquerda] > Vet[i])
            maior = 2*i;
    }

    if (maior != 1) {
        aux = Vet[i];
        Vet[i] = Vet[maior];
        Vet[maior] = aux;

        HeapFica(Vet, maior, n);
    }
}

void TransformaHeap(int Vet[], int n) {
    int i, pai, aux;
    for (i=n/2; i >= 1; i--)
        HeapFica(Vet, i , n);
}

void OrdenaPorHeap(int Vet[], int n) {
    int i, aux, ultima_posicao;
    for (i=n; i >= 2; i--) {
        aux = Vet[1];
        Vet[1] = Vet[i];
        Vet[i] = aux;
        ultima_posicao = i - 1;

        HeapFica(Vet, 1, ultima_posicao);
    }
}

int main(){
    int n = 5, V[n+1];
    for (int i = 1; i <= n; i++) {
        cout << i << "° valor: ";
        cin >> V[i];
    }

    TransformaHeap(V, n);
    OrdenaPorHeap(V, n);

    cout << "Valores ordenados:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "V[" << i << "]: " << V[i] << endl;
    }

    return (0);
}