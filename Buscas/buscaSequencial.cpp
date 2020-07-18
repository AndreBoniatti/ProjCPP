#include <iostream>
using namespace std;

int main() {

    int n = 5;
    int num_procurado, pos_procurado;
    int V[n];

    //Le os valores
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "° valor:";
        cin >> V[i];
    }

    cout << "Informe o número procurado:";
    cin >> num_procurado;
    //Procura o valor
    pos_procurado = 0;
    for (int i = 0; i < n; i++) {
        if (V[i] == num_procurado) {
            pos_procurado = i + 1;
            break;
        }
    }

    if (pos_procurado <= 0) {
        cout << "O número " << num_procurado << " não encontra-se no vetor." << endl;
    } else {
        cout << "O número " << num_procurado << " foi encontrado na posição " << pos_procurado << endl;
    }

    return(0);
}