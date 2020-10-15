#include<iostream>
using namespace std;

struct lista
{
    int num;
    lista *proximo;
};

int main() {
    int op, numero, achou;

    lista *inicio = NULL;
    lista *fim = NULL;
    lista *aux;
    lista *anterior; //Lista auxiliar que define o elementoo anterior

    do {
        cout << "Menu de opcoes" <<endl;
        cout << "1- Inserir elemento no início da lista" << endl;
        cout << "2- Inserir elemento no fim da lista" << endl;
        cout << "3- Consultar lista" << endl;
        cout << "4- Remover item da lista" << endl;
        cout << "5- Esvaziar a lista" << endl;
        cout << "Opcao: ";
        cin >> op;

        if (op == 1) {
            cout << "Número a ser inserido: " << endl;
            lista *novo = new lista();
            cin >> novo->num;

            if (inicio == NULL) {
                //A lista está vazia
                //O número inserido será o início e o fim da lista
                inicio = novo;
                fim = novo;
                fim->proximo = inicio;
            } else {
                //A lista já contém elementos
                //O novo elemento será inserido no início da lista
                novo->proximo = inicio;
                inicio = novo;
                fim->proximo = inicio;
            }
            cout << novo->num << " inserido no início da lista" << endl;
        }

        if (op == 2) {
            cout << "Número a ser inserido: " << endl;
            lista *novo = new lista();
            cin >> novo->num;

            if (inicio == NULL) {
                //A lista está vazia
                //O número inserido será o início e o fim da lista
                inicio = novo;
                fim = novo;
                fim->proximo = inicio;
            } else {
                //A lista já contém elementos
                //O novo elemento será inserido no fim da lista
                fim->proximo = novo;
                fim = novo;
                fim->proximo = inicio;
            }
            cout << novo->num << " inserido no fim da lista" << endl;
        }

        if (op == 3) {
            if (inicio == NULL) cout << "Lista vazia." << endl;
            else {
                cout << "Elementos da lista: " << endl;
                aux = inicio;
                do {
                    cout << aux->num << "  ";
                    aux = aux->proximo;
                } while (aux != inicio);
                cout << endl;
            }
        }

        if (op == 4) {
            if (inicio == NULL) cout << "Lista vazia." << endl;
            else {
                cout << "Numero a ser removido: ";
                cin >> numero;
                aux = inicio;
                anterior = NULL;
                achou = 0;
                int quantidade = 0;
                do {
                    quantidade++;
                    aux = aux->proximo;
                } while (aux != inicio);
                int elemento = 1;
                do {
                    if (inicio == fim && inicio->num == numero) { //A lista possui apenas um elemento
                        delete(inicio);
                        inicio = NULL;
                        achou++;
                    } else {
                        if (aux->num == numero) {
                            achou++;
                            if (aux == inicio) { //O número a ser removido é o primeiro da lista
                                inicio = aux->proximo;
                                fim->proximo = inicio;
                                delete(aux);
                                aux = inicio;
                            }
                            else if (aux == fim) { //O número a ser removido é o ultimo da lista
                                fim = anterior;
                                fim->proximo = inicio;
                                delete(aux);
                                aux = NULL;
                            }
                            else { //O número a ser removido está no meio da lista
                                anterior->proximo = aux->proximo;
                                delete(aux);
                                aux = anterior->proximo;
                            }
                        }
                        else {
                            anterior = aux;
                            aux = aux->proximo;
                        }
                    }
                    elemento++;
                } while (elemento <= quantidade);
                if (achou == 0) cout << "O número " << numero << " não foi localizado na lista." << endl;
                else cout << "O número " << numero << " foi localizado na lista " << achou << " vez(es)" << endl;
            }
        }

        if (op == 5) {
            if (inicio == NULL) cout << "Lista vazia." << endl;
            else {
                aux = inicio;
                do {
                    inicio = inicio->proximo;
                    delete(aux);
                    aux = inicio;
                } while (aux != fim);
                
                delete(fim);
                inicio = NULL;
                cout << "Lista esvaziada." << endl;
            }
        }

    } while (op >= 1 && op <= 5);

    return(0);
}

