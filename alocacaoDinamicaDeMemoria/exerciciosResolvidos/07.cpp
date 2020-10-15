/*
Codificar um programa em C++ que aloque dinamicamente uma matriz, de acordo com as dimensões (linhas e
colunas) informadas pelo usuário. A seguir, encontre o menor valor e a posição em que foi informado (linha e
coluna), escrevendo essa informação.
*/

#include<iostream>
using namespace std;

int main(){
	int linhas, colunas,maior,linhamaior,colunamaior;

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

	maior=matriz[0][0];
	linhamaior=0;
	colunamaior=0;

	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			if(matriz[i][j]>maior){
				maior=matriz[i][j];
				linhamaior=i;
				colunamaior=j;
			}
		}
	}
	cout<<"Maior elemento da matriz: "<<maior<<endl;
	cout<<"Linha: "<<linhamaior+1<<endl;
	cout<<"Coluna: "<<colunamaior+1<<endl;

	delete(matriz);

return(0);
}
