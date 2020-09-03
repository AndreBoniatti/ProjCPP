#include<iostream>
using namespace std;

//Define o registro que representa cada elemento da árvore binária
struct arvore {
       int num;
       arvore *esq;
       arvore *dir;              
} a;

arvore *inserir (arvore *aux, int num) {
       if (aux == NULL) {
          aux = new arvore();
          aux->num = num;
          aux->esq = NULL;
          aux->dir = NULL;        
       }
       else if (num < aux->num)
            aux->esq = inserir(aux->esq, num);     
       else
            aux->dir = inserir(aux->dir, num);
       return aux;
}

int consultar (arvore *aux, int num, int achou) {
    if ( (aux != NULL) && (achou == 0) ) {
       if (aux->num == num) {
          achou = 1;         
       }    
       else if (num < aux->num) {
          achou = consultar(aux->esq, num, achou);     
       }
       else {
          achou = consultar(aux->dir, num, achou);
       }
    }
    return achou;
}

void mostraremordem(arvore *aux) {
     if (aux != NULL) {
        mostraremordem(aux->esq);
        cout << aux->num << "   ";
        mostraremordem(aux->dir);
     }
}

void mostrarpreordem(arvore *aux) {
     if (aux != NULL) {
        cout << aux->num << "   ";
        mostrarpreordem(aux->esq);        
        mostrarpreordem(aux->dir);
     }
}

void mostrarposordem(arvore *aux) {
     if (aux != NULL) {
        mostrarposordem(aux->esq);        
        mostrarposordem(aux->dir);
        cout << aux->num << "   ";        
     }
}

arvore *remover(arvore *aux, int num) {
     arvore *p, *p2;
     if (aux->num == num) {
        if (aux->esq == aux->dir) {
           //O elemento a ser removido não tem filhos
           delete (aux);
           return NULL;             
        }
        else if (aux->esq == NULL) {
           //O elemento a ser removido não tem filho a esquerda
           p = aux->dir;
           delete(aux);
           return p;     
        }
        else if (aux->dir == NULL) {
           //O elemento a ser removido não tem filho a direita
           p = aux->esq;
           delete(aux);
           return p;     
        }
        else {
           //O elemento a ser removido tem filhos na esquerda e na direita
           p2 = aux->dir;
           p = aux->dir;
           while (p->esq != NULL) {
               p = p->esq;         
           }
           p->esq = aux->esq;
           delete (aux);
           return p2;    
        }
     }
     else if (aux->num < num)
          aux->dir = remover(aux->dir, num);
     else
          aux->esq = remover(aux->esq, num);
        
     return aux;
}

arvore *desalocar(arvore *aux) {
    if (aux != NULL) {
       aux->esq = desalocar(aux->esq);
       aux->dir = desalocar(aux->dir);
       delete(aux);        
    }
    return NULL;
}

int main () {
    
    //Árvore varia: ponteiro tem valor null
    arvore *raiz = NULL;
    arvore *aux;    
    int op, achou, numero;    
    do {
       cout << "MENU DE OPÇÕES:" << endl;
       cout << "1 - Inserir na árvore" << endl;
       cout << "2 - Consultar um nó da árvore" << endl;
       cout << "3 - Consultar toda árvore em ordem" << endl;
       cout << "4 - Consultar toda árvore em pre-ordem" << endl;
       cout << "5 - Consultar toda árvore em pos-ordem" << endl;
       cout << "6 - Excluir um nó da árvore" << endl;
       cout << "7 - Esvaziar a árvore" << endl;
       cout << "8 - Sair" << endl;
       cout << "Opção: " << endl;
       cin >> op;

       //1 - Inserir na árvore
       if (op == 1) {
          cout << "Número a ser inserido na árvore: ";
          cin>>numero;
          raiz = inserir(raiz, numero);
          cout << numero << " inserido na árvore" << endl;
       }
       
       //2 - Consultar um nó da árvore
       if (op == 2) {
          if (raiz == NULL) {
             //Árvore está vazia
             cout << "Árvore vazia!" << endl;         
          } else {
            //Árvore contém elementos
            cout << "Informe o elemento: ";
            cin >> numero;
            
            achou = 0;
            achou = consultar(raiz, numero, achou);            
            if (achou == 0) cout << numero << " não localizado na árvore!" << endl;
            else cout << numero << " localizado na árvore!" << endl;
          }
       }

       //3 - Consultar toda árvore em ordem
       if (op == 3) {
          if (raiz == NULL) {
             //Árvore está vazia
             cout << "Árvore vazia!" << endl;         
          } else {
            //Árvore contém elementos. Serão mostrados em ordem
            cout << "Elementos em ordem: " << endl; 
            mostraremordem(raiz);
            cout << endl;
          }
       }
              
       //4 - Consultar toda árvore em pre-ordem
       if (op == 4) {
          if (raiz == NULL) {
             //Árvore está vazia
             cout << "Árvore vazia!" << endl;         
          } else {
            //Árvore contém elementos. Serão mostrados em pre-ordem
            cout << "Elementos em pre-ordem: " << endl;
            mostrarpreordem(raiz);
            cout << endl;
          }              
       }
              
       //5 - Consultar toda árvore em pos-ordem
       if (op == 5) {
          if (raiz == NULL) {
             //Árvore está vazia
             cout << "Árvore vazia!" << endl;         
          } else {
            //Árvore contém elementos. Serão mostrados em pos-ordem
            cout << "Elementos em pos-ordem: " << endl;
            aux = raiz;
            mostrarposordem(aux);
            cout << endl;
          }              
       }

       //6 - Excluir um nó da árvore
       if (op == 6) {
          if (raiz == NULL) {
             cout << "Árvore vazia" << endl;         
          }
          else {
               cout << "Número a ser excluído: ";
               cin >> numero;
               
               achou = 0;
               achou = consultar(raiz, numero, achou);               
               if (achou == 0) cout << numero << " não localizado" << endl;
               else {
                    raiz = remover(raiz, numero);
                    cout << numero << " removido!" << endl;
               }

          }
       }
              
       //7 - Esvaziar a árvore
       if (op == 7) {
          if (raiz == NULL) {
             cout << "Árvore vazia!" << endl;         
          } else {
             raiz = desalocar(raiz);
             cout << "Árvore esvaziada!" << endl;
          }
       }       
        
    } while (op != 8);
        
    system("pause");
    return(0);    
}
