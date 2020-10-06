/*
Escrever um programa em C++ para ler o número de linhas e colunas da matriz M. A seguir, calcular e escrever
a soma de todos os elementos da matriz M. A matriz M deve ser alocada dinamicamente.
*/

#include<iostream>
using namespace std;

int main(){
	int linhas, colunas, soma=0;

	cout<<"Linhas: ";
	cin>>linhas;

	cout<<"Colunas: ";
	cin>>colunas;

	//Aloca dinamicamente a matriz
	int **matriz=new int*[linhas];
	for(int i=0;i<linhas;i++){
		//Aloca as colunas da matriz
		matriz[i]=new int[colunas];

	}

	//Realiza a leitura da matriz
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			cout<<"M["<<i+1<<"]["<<j+1<<"]: ";
			cin>>matriz[i][j];
		}
	}

	//Realiza a soma dos elementos da matriz
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			soma=soma+matriz[i][j];
		}
	}
	cout<<"Soma da matriz: "<<soma<<endl;

	//Remove a matriz da memória
	delete (matriz);
	
return(0);
}
