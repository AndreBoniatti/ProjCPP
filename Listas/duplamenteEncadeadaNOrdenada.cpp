#include<iostream>
using namespace std;

struct lista
{
    int num;
    lista *anterior;
    lista *proximo;    
};

int main() {
    int op, achou, numero;

    lista *inicio = NULL;
    lista *fim = NULL;
    lista *aux;

    do {
        cout << "Menu de opcoes" <<endl;
        cout << "1- Inserir no início da lista" << endl;
        cout << "2- Inserir no fim da lista" << endl;
        cout << "3- Consultar lista do início ao fim" << endl;
        cout << "4- Consultar lista do fim ao início" << endl;
        cout << "5- Remover item da lista" << endl;
        cout << "6- Esvaziar a lista" << endl;
        cout << "Opcao: ";
        cin >> op;

        if (op == 1) {
            cout << "Numero a ser inserido: ";
            lista *novo = new lista(); //Cria um objeto do tipo lista
            cin >> novo->num; //Armazena o valor na fila

            if (inicio == NULL) {
                //A lista está vazia
                //O número inserido será o início e o fim da lista
                inicio = novo;
                fim = novo;
                novo->proximo = NULL;
                novo->anterior = NULL;
            } else {
                //A lista já contém elementos
                //O novo elemento será inserido no início da lista
                novo->proximo = inicio;
                inicio->anterior = novo;
                novo->anterior = NULL;
                inicio = novo;
            }
            cout << novo->num << " inserido no inicio da lista" << endl;
        }

        if (op == 2) {
            cout << "Numero a ser inserido: ";
            lista *novo = new lista();
            cin >> novo->num;

            if (inicio == NULL) {
                inicio = novo;
                fim = novo;
                novo->proximo = NULL;
                novo->anterior = NULL;
            } else {
                fim->proximo = novo;
                novo->anterior = fim;
                novo->proximo = NULL;
                fim = novo;
            }
            cout << novo->num << " inserido no final da lista" << endl;
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
            if (inicio == NULL) cout << "Lista vazia." << endl;
            else {
                cout << "Elementos da lista: " << endl;
                aux = fim;
                while (aux != NULL){
                    cout << aux->num << endl;
                    aux = aux->anterior;
                }
            } 
        }

        if (op == 5) {
        if (inicio == NULL) cout << "Lista vazia." << endl;
        else {
                cout << "Numero a ser removido: ";
                cin >> numero;
                aux = inicio;
                achou = 0;
                while (aux != NULL) {
                    if (aux->num == numero) { //O numero informado foi encontrado e será removido da lista
                        achou++;
                        if (aux == inicio) { //O numero a ser removido está no inicio da lista 
                            inicio = aux->proximo;
                            if (inicio != NULL) inicio->anterior = NULL;
                            delete(aux);
                            aux = inicio;
                        }
                        else if (aux == fim) { //O número a ser removido é o último da lista 
                            fim = fim->anterior;
                            fim->proximo = NULL;
                            delete(aux);
                            aux = NULL;
                        }
                        else { //O número a ser removido está no meio da lista
                            aux->anterior->proximo = aux->proximo;
                            aux->proximo->anterior = aux->anterior;
                            lista *aux2;
                            aux2 = aux->proximo;
                            delete(aux);
                            aux = aux2;
                        }
                    }
                    else { //O número informado ainda não foi encontrado na lista
                        aux = aux->proximo;
                    }
                }
                if (achou == 0) cout << "O número " << numero << " não foi localizado na lista" << endl;
                else cout << "O número " << numero << " foi localizado na lista " << achou << " vez(es)" << endl;
        } 
        }

        if (op == 6) {
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
    } while (op >= 1 && op <= 6);

    return (0);
}