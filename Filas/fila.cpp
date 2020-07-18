#include <iostream>
using namespace std;

struct fila {
    int num;
    fila *proximo;
} f;

int main() {
    int op;

    fila *inicio = NULL;
    fila *fim = NULL;
    fila *aux = NULL;

    do {
        cout << "Menu de opcoes" << endl;
        cout<< "1- Inserir" << endl;;
        cout<< "2- Consultar" << endl;
        cout<< "3- Remover" <<  endl;
        cout<< "4- Esvaziar" << endl;
        cout << "Opcao: ";
        cin >> op;

        if (op == 1) {
            cout << "Numero a ser inserido: ";
            fila *novo = new fila(); //Cria um objeto do tipo fila
            cin >> novo->num; //Armazena o valor na fila
            novo->proximo = NULL; //Atualiza o ponteiro próximo para nulo
            if (inicio == NULL) {
                //A fila está vazia. O número inserido será o início e o fim da fila
                inicio = novo;
                fim = novo;
            } else {
                fim->proximo = novo;
                fim = novo;
            }
        }

        if (op == 2){
            if (inicio == NULL) cout << "Fila vazia" << endl;
            else {
                cout << "Elementos da fila:" << endl;
                aux = inicio;
                while (aux != NULL) {
                    cout << aux->num << endl;
                    aux = aux->proximo;
                }
            }
        }

        if (op == 3) {
            if (inicio == NULL) cout << "Fila vazia" << endl;
            else {
                //O primeiro elemento inserido será o removido
                aux = inicio;
                cout << inicio->num << " removido" << endl;
                //Atualiza o início da fila para o próximo elemento
                inicio = inicio->proximo;
                delete(aux); //Deleta o inicio
            }
        }

        if (op == 4) {
            if (inicio == NULL) cout << "Fila vazia" << endl;
            else {
                aux = inicio;
                while (aux != NULL) {
                    inicio = inicio->proximo;
                    delete(aux);
                    aux = inicio;
                }
                cout << "Fila esvaziada" << endl;
            }
        }

    } while (op > 0 && op <= 4);

    return (0);
}