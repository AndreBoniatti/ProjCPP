#include<iostream>
using namespace std;

struct lista {
    int num;
    lista *anterior;
    lista *proximo;
};

int main() {
    int op,numero,achou;

    lista *inicio = NULL; //Define o início da lista
    lista *fim = NULL; //Define o fim da lista
    lista *aux; //Lista auxiliar para consulta e remoção

    do {
        cout << "Menu de opcoes" <<endl;
        cout << "1- Inserir elemento na lista" << endl;
        cout << "2- Consultar lista do início ao fim" << endl;
        cout << "3- Consultar lista do fim ao início" << endl;
        cout << "4- Remover item da lista" << endl;
        cout << "5- Esvaziar a lista" << endl;
        cout << "Opcao: ";
        cin >> op;

        if (op == 1) {
            cout << "Número a ser inserido: ";
            lista *novo = new lista();
            cin >> novo->num;
            if (inicio == NULL) { //A lista está vazia. O número inserido será o início e o fim da lista
                novo->proximo = NULL;
                novo->anterior = NULL;
                inicio = novo;
                fim = novo;
            } else {
                //A lista já contém elementos. O novo elemento será inserido na lista respeitado a ordem crescente
                aux = inicio;
                while ((aux != NULL) && (novo->num > aux->num)) {
                    aux = aux->proximo;
                }
                if (aux == inicio) { //O novo número é menor que todos da lista. Insere o valor no início da lista 
                    novo->proximo = inicio;
                    novo->anterior = NULL;
                    inicio->anterior = novo;
                    inicio = novo;
                }
                else if (aux == NULL) { //O novo número é maior que todos da lista. Insere o valor no fim da lista
                    fim->proximo = novo;
                    novo->anterior = fim;
                    fim = novo;
                    fim->proximo = NULL;
                }
                else { //O novo número deverá ser inserido entre outros na lista
                    novo->proximo = aux;
                    aux->anterior->proximo = novo;
                    novo->anterior = aux->anterior;
                    aux->anterior = novo;
                }
            }
            cout << novo->num << " inserido na lista" << endl;
        }

        if (op == 2) {
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

        if (op == 3) {
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

        if (op == 4) {
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

    } while (op >= 1 && op <= 5);


    return(0);
}