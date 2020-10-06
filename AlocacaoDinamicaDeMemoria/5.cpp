/*
Elaborar um programa em C++ para ler uma matriz de inteiros de tamanho N x M. O programa deve ler o
número de colunas e linhas do teclado. O programa deve ainda trocar duas linhas da matriz de posição. Os
números das linhas a serem trocadas devem ser lidos do teclado. Escrever a matriz modificada. A matriz deve
ser alocada dinamicamente.
*/

#include<iostream>
using namespace std;

int main(){
	int linhas, colunas,alterlinha1,alterlinha2,aux;

	cout<<"Linhas: ";
	cin>>linhas;

	cout<<"Colunas: ";
	cin>>colunas;

	
	int **matriz=new int*[linhas];

	for(int i=0;i<linhas;i++){
		matriz[i]=new int[colunas];
	}

	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			cout<<"M["<<i+1<<"]["<<j+1<<"]: ";
			cin>>matriz[i][j];
		}
	}

	cout<<"N° da primeira linha a ser trocada: ";
	cin>>alterlinha1;

	cout<<"N° da segunda linha a ser trocada: ";
	cin>>alterlinha2;

	for(int i=0;i<colunas;i++){
			aux=matriz[alterlinha1-1][i];
			matriz[alterlinha1-1][i]=matriz[alterlinha2-1][i];
			matriz[alterlinha2-1][i]=aux;
	}

	cout<<endl<<"Matiz modificada"<<endl;
		for(int i=0;i<linhas;i++){
			for(int j=0;j<colunas;j++){
				cout<<matriz[i][j]<<"  ";
			}
		cout<<endl;
		}

return(0);
}
