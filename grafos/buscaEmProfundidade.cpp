#include <iostream>
using namespace std;

struct vertice {
    int num;
    vertice *prox;
};

struct listaadj {
    vertice *listav;
};

struct queue {
    int numv;
    queue *prox;
};

void empilhar(queue* &pilha, int n) {
    queue *novo = new queue();
    novo->numv = n;
    novo->prox = pilha;
    pilha = novo;
}

void desempilhar(queue* &pilha, int v) {
    if (pilha->numv == v) {
        queue *aux;
        aux = pilha;
        pilha = pilha->prox;
        delete(aux);
    }
}

void buscaprof(listaadj Adj[], int tam, int v, int marcado[], queue* &pilha) {
    vertice *vert;
    int w;

    marcado[v] = 1;

    //Inserindo "v" na pilha
    empilhar(pilha, v);

    for (int i = 1; i <= tam; i++) {
        //Primeiro vizinho de "v"
        vert = Adj[v].listav;
        while (vert != NULL) {
            w = vert->num;
            if (marcado[w] != 1) {
                cout << "  " << w;
                buscaprof(Adj, tam, w, marcado, pilha);
            }
            //Próximo vizinho de "v"
            vert = vert->prox;
        }
    }
    desempilhar(pilha, v);
}

void mostraAdj(listaadj Adj[], int tam) {
    vertice *v;
    for (int i = 1; i <= tam; i++) {
        v = Adj[i].listav;
        cout << endl << "Entrada " << i << "  ";
        while (v != NULL) {
            cout << "(" << i << ", " << v->num << ")" << "  ";
            v = v->prox;
        }
    }
}

int main() {
    //Pilha para armazenar os vértices visitados
    queue *pilha = NULL;

    //Vetor que armazena se o vértice foi marcado
    int *marcado = NULL;

    //Lista de adjacências entre os vértices
    listaadj *Adj = NULL;

    vertice *novo, *aux;

    int tam, org, dest, op, num, tipo;

    cout << endl << "Tipo de grafo (1- Não orientado, 2- Orientado): ";
    cin >> tipo;

    cout << endl << "Número de Vértices: ";
    cin >> tam;

    Adj = new listaadj[tam + 1];
    marcado = new int[tam + 1];

    //Inicialização das variáveis
    for (int i = 0; i <= tam; i++) {
        marcado[i] = 0;
        Adj[i].listav = NULL;
    }

    cout << endl << "Arestas do grafo: Vértice de Origem (-1 para parar): ";
    cin >> org;
    
    cout << endl << "Arestas do grafo: Vértice de Destino (-1 para parar): ";
    cin >> dest;

    while ((org != -1) && (dest != -1)) {
        /*
        Alocando um nó com o valor do vértice destino para colocar
        na entrada do vértice de origem da lista de adjacências
        */
        novo = new vertice();
        novo->num = dest;

        //Inserindo vértice adjacente ao vértice "org" na lista de adjacências
        novo->prox = Adj[org].listav;
        Adj[org].listav = novo;

        if (tipo == 1) {
            //Inserindo (v, u)
            novo = new vertice();
            novo->num = org;

            //Inserindo vértice adjacente ao vértice "dest" na lista de adjacências
            novo->prox = Adj[dest].listav;
            Adj[dest].listav = novo;
        }

        //Próximas entradas
        cout << endl << "Arestas do grafo: Vértice de Origem (-1 para parar): ";
        cin >> org;
        
        cout << endl << "Arestas do grafo: Vértice de Destino (-1 para parar): ";
        cin >> dest;
    }

    do {
        cout << endl << "1- Busca em profundidade";
        cout << endl << "2- Mostrar lista de adjacências";
        cout << endl << "3- Sair";
        cout << endl << "Opção: ";
        cin >> op;

        if (op == 1) {
            cout << "Informe um vértice de partida da busca: ";
            cin >> num;

            cout << "  " << num;
            buscaprof(Adj, tam, num, marcado, pilha);

            for (int i = 1; i <= tam; i++) {
                marcado[i] = 0;
            }
        }
        else if (op == 2) {
            mostraAdj(Adj, tam);
        }
    } while (op != 3);

    //Desalocando memória
    delete(marcado);
    for (int i = 1; i <= tam; i++) {
        while (Adj[i].listav != NULL) {
            aux = Adj[i].listav;
            Adj[i].listav = Adj[i].listav->prox;
            delete(aux);
        }
    }

    delete(Adj);

    return 0;
}