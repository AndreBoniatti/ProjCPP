#include <iostream>
using namespace std;

struct vertice {
    int num;
    vertice *prox;
};

struct listaadj {
    vertice *listav;
};

struct fila {
    int numv;
    fila *prox;
};

void inserir(fila* &inicio, fila* &fim, int n) {
    fila *novo = new fila();
    novo->numv = n;
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
}

int remover(fila* &inicio, fila* &fim) {
    if (inicio != NULL) {
        int vert;
        if (inicio == fim) fim = NULL;
        vert = inicio->numv;
        inicio = inicio->prox;
        return vert;
    }

    cout << endl << "Lista vazia!";
    return 0;
}

void buscaLargura(listaadj Adj[], fila* &inicio, fila* &fim, int tam, int v, int marcado[], int dist[]) {
    vertice *listavert;
    int w;
    int vertice;

    //Alcançou vértice "v"
    marcado[v] = 1;
    
    //Distância de "v" a origem (ele mesmo) é zero
    dist[v] = 0;

    //Inserir "v" em uma fila
    inserir(inicio, fim, v);

    while (inicio != NULL) {
        //Removendo um vértice da fila
        vertice = remover(inicio, fim);
        for (int i = 1; i <= tam; i++) {
            //Varre a lista de vizinhos do vértice
            listavert = Adj[vertice].listav;
            while (listavert != NULL) {
                w = listavert->num;
                /*
                Caso o vértice não está marcado, calcula-se a distância em
                relação a origem e insere-o na fila para depois visitar seus vizinhos
                */
               if (marcado[w] == 0) {
                   marcado[w] = 1;
                   dist[w] = dist[vertice] + 1;
                   inserir(inicio, fim, w);
               }
               //Próximo vértice adjacente a "v"
               listavert = listavert->prox;
            }
        }
    }
}

void mostrarAdj(listaadj Adj[], int tam) {
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

void mostrarDistancia(int dist[], int tam, int ori) {
    cout << endl << "Distância da origem " << ori << " para os demais vértices: " << endl;
    for (int i = 1; i <= tam; i++) {
        cout << "Vértice " << i << ": " << dist[i] << endl;
    }
}

int main() {
    fila *inicio = NULL;
    fila *fim = NULL;
    fila *temp = NULL;

    //Vetor que armazena se o vértice foi marcado
    int *marcado;
    int *dist;

    //Lista de adjacências entre os vértices
    listaadj *Adj;
    vertice *novo, *aux;
    int tam, org, dest, op, num = 0, tipo, flag = 0;

    cout << endl << "Tipo de grafo (1- Não orientado, 2- Orientado): ";
    cin >> tipo;

    cout << endl << "Número de Vértices: ";
    cin >> tam;

    Adj = new listaadj[tam + 1];
    marcado = new int[tam + 1];
    dist = new int[tam + 1];

    //Inicialização das variáveis
    for (int i = 1; i <= tam; i++) {
        marcado[i] = 0;
        Adj[i].listav = NULL;
    }

    cout << endl << "Arestas do grafo: Vértice de Origem (-1 para parar): ";
    cin >> org;
    
    cout << endl << "Arestas do grafo: Vértice de Destino (-1 para parar): ";
    cin >> dest;

    while ((org != -1) && (dest != -1)) {
        /*
        Alocando um nó com o valor do vértice destino para colocar na
        entrada do vértice de origem da lista de adjacências
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
        cout << endl << "1- Busca em largura";
        cout << endl << "2- Mostrar lista de adjacências";
        cout << endl << "3- Menor distância a partir do vértice de origem";
        cout << endl << "4- Sair";
        cout << endl << "Opção: ";
        cin >> op;

        if (op == 1) {
            cout << "Informe um vértice de partida da busca: ";
            cin >> num;

            for (int i = 1; i <= tam; i++) {
                marcado[i] = 0;
                dist[i] = 0;
            }

            buscaLargura(Adj, inicio, fim, tam, num, marcado, dist);
            flag = 1;
        }
        else if (op == 2) {
            mostrarAdj(Adj, tam);
        }
        else if (op == 3) {
            if (flag == 0) cout << "Faça a busca primeiro!" << endl;
            else mostrarDistancia(dist, tam, num);
        }
    } while (op != 4);

    //Desalocando memória
    delete(marcado);
    delete(dist);
    for (int i = 1; i <= tam; i++) {
        while (Adj[i].listav != NULL) {
            aux = Adj[i].listav;
            Adj[i].listav = Adj[i].listav->prox;
            delete(aux);
        }
    }

    delete(Adj);

    //Fila
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        delete(temp);
    }

    return 0;
}