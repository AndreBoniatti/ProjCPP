#include <iostream>
using namespace std;

struct lista {
    int num;
    lista *proximo;
};

int main() {
    int op, achou, numero;

    lista *inicio = NULL; //Define o início da lista
    lista *fim = NULL; //Define o fim da lista
    lista *aux; //Lista auxiliar para consulta e remoção
    lista *anterior; //Lista auxiliar que define o elemento anterior

    do {

        cout << "Menu de opções" << endl;
        cout << "1. Inserir elemento no início da lista" << endl;
        cout << "2. Inserir elemento no final da lista" << endl;
        cout << "3. Consultar toda a lista" << endl;
        cout << "4. Remover elemento da lista" << endl;
        cout << "5. Esvaziar lista lista" << endl;
        cout << "6. Sair" << endl;
        cout << "Opcao: ";
        cin >> op;

        if (op == 1) {
            cout << "Numero a ser inserido: ";
            lista *novo = new lista(); //Cria um objeto do tipo lista
            cin >> novo->num; //Armazena o valor na lista

            if (inicio == NULL) {
                //A lista está vazia
                //O número inserido será o início e o fim da lista
                inicio = novo;
                fim = novo;
                fim->proximo = NULL;
            } else {
                //A lista já contém elementos
                //O novo elemento será inserido no início da lista
                novo->proximo = inicio;
                inicio = novo;
            }

            cout << novo->num << " inserdo no início da lista." << endl;
        }

        if (op == 2) {
            cout << "Numero a ser inserido: ";
            lista *novo = new lista(); //Cria um objeto do tipo lista
            cin >> novo->num; //Armazena o valor na lista

            if (inicio == NULL) {
                //A lista está vazia
                //O número inserido será o início e o fim da lista
                inicio = novo;
                fim = novo;
                fim->proximo = NULL;
            } else {
                //A lista já contém elementos
                //O novo elemento será inserido no início da lista
                fim->proximo = novo;
                fim = novo;
                fim->proximo = NULL;
            }

            cout << novo->num << " inserdo no fim da lista." << endl;
        }

        if (op == 3) {
            if (inicio == NULL) cout << "Lista vazia." << endl;
            else {
                cout << "Elementos da lista: " << endl;
                aux = inicio;
                while (aux != NULL) {
                    cout << aux->num << endl;
                    aux = aux->proximo;
                }
            }
        }

        if (op == 4) {
            cout << "Numero a ser removido: ";
            cin >> numero;
            //Todas as ocorrências da lista iguais ao número digitado serão removidas
            aux = inicio;
            anterior = NULL;
            achou = 0;
            while (aux != NULL) {
                if (aux->num == numero) { //O número informado foi encontrado na lista e será removido
                    achou++;
                    if (aux == inicio) { //O número a ser removido está no início da lista
                        inicio = aux->proximo;
                        delete(aux);
                        aux = inicio;
                    }
                    else if (aux == fim) { //O número a ser removido é o último da lista
                        anterior->proximo = NULL;
                        fim = anterior;
                        delete(aux);
                        aux = NULL;
                    }
                    else { //O número a ser removido está no meio da lista
                        anterior->proximo = aux->proximo;
                        delete(aux);
                        aux = anterior->proximo;
                    }
                }
                else { //O número informado ainda não foi encontrado na lista
                    anterior = aux;
                    aux = aux->proximo;
                }
            }

            if (achou == 0) cout << "O número " << numero << " não foi localizado na lista." << endl;
            else cout << "O número " << numero << " foi localizado na lista " << achou << " vez(es)" << endl;
        }

        if (op == 5) {
            if (inicio == NULL) cout << "Lista vazia." << endl;
            else {
                aux = inicio;
                while (aux != NULL) {
                    inicio = inicio->proximo;
                    delete(aux);
                    aux = inicio;
                }

                cout << "Lista esvaziada." << endl; 
            }
        }

    }while (op >= 1 && op <= 5);

    return (0);
}