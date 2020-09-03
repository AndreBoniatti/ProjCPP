#include<iostream>
using namespace std;

//Define o registro que representa cada elemento da árvore binária
struct arvore {
    int num;
    arvore *esq;
    arvore *dir;
} a;

//Define o registro que representa cada elemento da árvore binária na pilha
struct pilha {
    arvore *num;
    pilha *prox;
} p;

int main() {

    //Árvore vazia: ponteiro tem valor null
    arvore *raiz = NULL;

    //Ponteiros auxiliares
    arvore *aux, *aux1;
    arvore *novo;
    arvore *anterior;

    pilha *topo;
    pilha *aux_pilha;

    int op, achou, numero;

    do {
        cout << "Menu de Opcoes" << endl;
        cout << "1- Inserir na árvore" << endl;
        cout << "2- Consultar um nó da árvore" << endl;
        cout << "3- Consultar toda árvore em ordem" << endl;
        cout << "4- Consultar toda árvore em pre-ordem" << endl;
        cout << "5- Consultar toda árvore em pos-ordem" << endl;
        cout << "6- Excluir um nó da árvore" << endl;
        cout << "7- Esvaziar a árvore" << endl;
        cout << "8- Sair" << endl;
        cout << "Opção: ";
        cin >> op;

        if (op == 1) { //Inserir na árvore
            novo = new arvore();
            cout << "Número a ser inserido na árvore: ";
            cin >> novo->num;
            novo->dir = NULL;
            novo->esq = NULL;
            if(raiz == NULL) {
                //Não existe elemento na árvore
                //O primeiro elemento passa a ser raiz
                raiz = novo;
            } else {
                //Existem elementos na árvore
                //Procura-se a posição para inserir o elemento
                aux = raiz;
                achou = 0;
                while(achou == 0) {
                    if(novo->num < aux->num) {
                        if(aux->esq == NULL) {
                            aux->esq = novo;
                            achou = 1;
                        } else aux = aux->esq;
                    }
                    else if(novo->num >= aux->num) {
                        if(aux->dir == NULL) {
                            aux->dir = novo;
                            achou = 1;
                        } else aux = aux->dir;
                    }
                }
            }
            cout << novo->num << " inserido na árvore" << endl;
        }

        if(op == 2) { //Consultar um nó na árvore
            if(raiz == NULL) {
                //Árvore está vazia
                cout << "Árvore vazia!" << endl;
            } else {
                //Árvorem contém elementos
                cout << "Informe o elemento: ";
                cin >> numero;

                achou = 0;
                aux = raiz;
                while((achou == 0) && (aux != NULL)) {
                    if(aux->num == numero) {
                        cout << numero << " encontrado na árvore!" << endl;
                        achou = 1;
                    }
                    else if(numero < aux->num) aux = aux->esq;
                    else aux = aux->dir;
                }
                if(achou == 0) cout << numero << " não localizado na árvore!" << endl;
            }
        }

        if(op == 3) { //Consultar toda árvore em ordem
            if(raiz == NULL) {
                //Árvore está vazia
                cout << "Árvore vazia!" << endl;
            } else {
                //Árvore contém elementos. Serão mostrados em ordem
                cout << "Elementos em ordem: " << endl;
                aux = raiz;
                topo = NULL; //Pilha = estrutura auxiliar

                do {
                    //Caminha pela árvore pelo ramo da esquerda até null
                    //Coloca cada elemento visitado em uma pilha
                    while(aux != NULL) {
                        aux_pilha = new pilha();
                        aux_pilha->num = aux;
                        aux_pilha->prox = topo;
                        topo = aux_pilha;
                        aux = aux->esq;
                    }
                    if(topo != NULL) {
                        aux_pilha = topo;
                        cout << aux_pilha->num->num << "  ";
                        aux = topo->num->dir;
                        topo = topo->prox;
                    }
                } while((topo != NULL) || (aux != NULL));
                cout << endl;
            }
        }

        if (op == 4) { //Consultar toda árvore em pre-ordem
            if(raiz == NULL) {
                //Árvore está vazia
                cout << "Árvore vazia!" << endl;
            } else {
                //Árvore contém elementos. Serão mostrados em pre-ordem
                cout << "Elementos em pre-ordem: " << endl;
                aux = raiz;
                topo = NULL; //Pilha = estrutura auxiliar

                do {
                    //Caminha pela árvore mostrando cada nó visitado
                    //Coloca cada elemento visitado em uma pilha
                    while(aux != NULL) {
                        aux_pilha = new pilha();
                        cout << aux->num << "  ";
                        aux_pilha->num = aux;
                        aux_pilha->prox = topo;
                        topo = aux_pilha;
                        aux = aux->esq;
                    }
                    if(topo != NULL) {
                        aux_pilha = topo;
                        topo = topo->prox;
                        aux = aux_pilha->num->dir;
                    }
                } while((topo != NULL) || (aux != NULL));
                cout << endl;
            }
        }

        if(op == 5) { //Consultar toda árvore em pos-ordem
            if(raiz == NULL) {
                //Árvore está vazia
                cout << "Árvore vazia!" << endl;
            } else {
                //Árvore contém elementos. Serão mostrados em pos-ordem
                cout << "Elementos em pos-ordem: " << endl;
                aux = raiz;
                topo = NULL; //Pilha = estrutura auxiliar

                do {
                    //Caminha pela árvore pelo ramo da esquerda até NULL
                    //Coloca cada elemento visitado em uma pilha
                    //Antes de colocar a raiz de cada sub-arvore na pilha, caminha também no ramo da direita
                    do {
                        while(aux != NULL) {
                            aux_pilha = new pilha();
                            aux_pilha->num = aux;
                            aux_pilha->prox = topo;
                            topo = aux_pilha;
                            aux = aux->esq;
                        }
                        if(topo->num->dir != NULL) {
                            aux = topo->num->dir;
                        }
                    }while(aux != NULL);
                    if(topo != NULL) {
                        cout << topo->num->num << "  ";
                        if(topo->prox != NULL) {
                            //Existe mais de um elemento empilhado
                            if((topo->prox->num->dir != NULL) && (topo->prox->num->dir != topo->num)) {
                                aux = topo->prox->num->dir;
                                topo = topo->prox;
                            } else {
                                while((topo->prox != NULL) && (topo->prox->num->dir == topo->num)) {
                                    topo = topo->prox;
                                    cout << topo->num->num << "  ";
                                }
                                topo = topo->prox;
                                if(topo != NULL) aux = topo->num->dir;
                                else aux = NULL;
                            }
                        } else {
                            topo = topo->prox;
                            aux = NULL;
                        }
                    }
                }while((topo != NULL) || (aux != NULL));
                cout << endl;
            }
        }

        if (op == 6) { //Excluir um nó da árvore
            if(raiz == NULL) {
                cout << "Árvore vazia!" << endl;
            } else {
                cout << "Número a ser excluido: ";
                cin >> numero;

                aux = raiz;
                achou = 0;
                while((achou == 0) && (aux != NULL)) {
                    if(aux->num == numero) achou = 1;
                    else if(aux->num > numero) {
                        //O número está a esquerda da árvore
                        aux = aux->esq;
                    } else {
                        //O número está a direita da árvore
                        aux = aux->dir;
                    }
                }
                if(achou == 0) cout << "Número não localizado!" << endl;
                else {
                    //O número foi localizado
                    if(aux != raiz) {
                        //O número não é a raiz
                        //É necessário encontrar o anterior para ajustar os ponteiros
                        anterior = raiz;
                        while((anterior->dir != aux) && (anterior->esq != aux)) {
                            if(anterior->num > numero) {
                                //O número está a esquerda da árvore
                                anterior = anterior->esq;
                            } else {
                                //O número está a direita da árvore
                                anterior = anterior->dir;
                            }
                        }
                        if((aux->dir == NULL) && (aux->esq == NULL)) {
                            //Um nó folha será excluido
                            if(anterior->dir == aux) anterior->dir = NULL;
                            else anterior->esq = NULL;
                            delete(aux);
                        } else {
                            //Um nó que não é folha será excluido
                            if((aux->dir != NULL) && (aux->esq == NULL)) {
                                //Nó que possui apenas filhos na direita
                                if(anterior->esq == aux) anterior->esq = aux->dir;
                                else anterior->dir = aux->dir;
                                delete(aux);
                            }
                            else if((aux->esq != NULL) && (aux->dir == NULL)) {
                                //Nó que possui apenas filhos na esquerda
                                if(anterior->esq == aux) anterior->esq = aux->esq;
                                else anterior->dir = anterior->esq;
                                delete(aux);
                            }
                            else if((aux->esq != NULL) && (aux->dir != NULL)) {
                                //Nó que possui filhos na esquerda e na direita
                                if(anterior->dir == aux) {
                                    anterior->dir = aux->dir;
                                    aux1 = aux->esq;
                                } else {
                                    anterior->esq = aux->dir;
                                    aux1 = aux->esq;
                                }
                                delete(aux);
                                //Reconectando a árvore
                                aux = anterior;
                                while(aux != NULL) {
                                    if(aux->num < aux1->num) {
                                        if(aux->dir == NULL) {
                                            aux->dir = aux1;
                                            aux = NULL;
                                        } else aux = aux->dir;
                                    }
                                    else if(aux->num > aux1->num) {
                                        if(aux->esq == NULL) {
                                            aux->esq = aux1;
                                            aux = NULL;
                                        } else aux = aux->esq;
                                    }
                                }
                            }
                        }
                    } else {
                        //O número a ser excluído é a raiz
                        if((aux->dir == NULL) && (aux->esq == NULL)) {
                            //A raiz não tem filhos e será excluida
                            delete(aux);
                            raiz = NULL;
                        } else {
                            if((aux->dir != NULL) && (aux->esq == NULL)) {
                                //A raiz possui apenas filhos a direita
                                raiz = aux->dir;
                                delete(aux);
                            }
                            if((aux->esq != NULL) && (aux->dir == NULL)) {
                                //A raiz possui apenas filhos a esquerda
                                raiz = aux->esq;
                                delete(aux);
                            }
                            if ((aux->esq != NULL) && (aux->dir != NULL)) {
                                //A raiz possui filhos a esquerda e a direita
                                raiz = aux->dir;
                                aux1 = aux->esq;
                                delete(aux);
                                aux = raiz;
                                //Reconectando o pedaço da árvore
                                while(aux != NULL) {
                                    if(aux->num < aux1->num) {
                                        if(aux->dir == NULL) {
                                            aux->dir = aux1;
                                            aux = NULL;
                                        } else aux = aux->dir;
                                    }
                                    else if(aux->num > aux1->num) {
                                        if(aux->esq == NULL) {
                                            aux->esq = aux1;
                                            aux = NULL;
                                        } else aux = aux->esq;
                                    }
                                }  
                            }
                        }
                    }
                    cout << numero << " excluído da árvore" << endl;
                }
            }
        }

        if (op == 7) { //Esvaziar a árvore
            if(raiz == NULL) {
                cout << "Árvore vazia!" << endl;
            } else {
                aux = raiz;
                topo = NULL;
                do {
                    //Passa por toda árvore imprimindo os nós
                    //Coloca cada nó da árvore em uma pilha
                    while(aux != NULL) {
                        aux_pilha = new pilha();
                        cout << aux->num << "  ";
                        aux_pilha->num = aux;
                        aux_pilha->prox = topo;
                        topo = aux_pilha;
                        aux = aux->esq;
                    }
                    if(topo != NULL) {
                        aux_pilha = topo;
                        topo = topo->prox;
                        aux = aux_pilha->num->dir;
                    }
                }while((topo != NULL) || (aux != NULL));
                //Passa por todos os elementos da pilha removendo-os
                aux_pilha = topo;
                while(aux_pilha != NULL) {
                    topo = topo->prox;
                    delete(topo->num);
                    delete(aux_pilha);
                    aux_pilha = topo;
                }
                raiz = NULL;
                cout << "Árvore esvaziada!" << endl;
            }
        }

    } while (op >= 1 && op <= 7);

    return (0);
}