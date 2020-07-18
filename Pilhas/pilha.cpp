#include<iostream>
using namespace std;

struct pilha {
    int num;
    pilha *proximo;
}p;

int main() {
    int op;

    pilha *topo  = NULL; // Define o topo da pilha
    pilha *aux; // Pilha auxiliar para cosultar a remoção

    do {
        cout << "Menu de Opcoes" << endl;
        cout << "1. Inserir" << endl;
        cout << "2. Consultar" << endl;
        cout << "3. Remover" << endl;
        cout << "4. Esvaziar" << endl;
        cout << "5. Sair: " << endl;
        cout << "Opcao: ";
        cin >> op;

        if (op == 1) {
            pilha *novo = new pilha(); // Cria um objeto do tipo pilha

            cout << "Numero a ser inserido: ";
            cin >> novo->num; // Armazena o valor na pilha

            // Atualiza o ponteiro proximo para o elemento antecessor  na pilha
            novo->proximo = topo;
            topo = novo; // Atualiza o topo da pilha para o novo elemento
        }

        if (op == 2) {
            if (topo == NULL) cout << "Pilha vazia" << endl;
            else {
                cout << "Elementos da pilha: " << endl;
                aux = topo;
                while (aux != NULL){
                    cout << aux->num << endl;
                    aux = aux->proximo;
                }
            }
        }

        if (op ==3) {
            if (topo == NULL) cout << "Pilha vazia" << endl;
            else {
                aux = topo; // O ultimo elemento inserido será o removido
                cout << aux->num << " removido" << endl;

                // Atualiza o topo para o proximo elemento
                topo = topo->proximo;
                delete(aux); // Deleta o topo
            }
        }

        if (op == 4) {
            if (topo == NULL) cout << "Pilha vazia" << endl;
            else {
                aux = topo;
                while (aux != NULL) {
                    topo = topo->proximo;
                    delete(aux);
                    aux = topo;
                }
                cout << "Pilha esvaziada" << endl;
            }
        }

    } while (op >= 1 && op <= 4);

    return (0);
}