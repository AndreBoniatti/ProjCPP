/*
Elaborar um programa em C++ que aloque dinamicamente uma matriz, de acordo com as dimensões (linhas e
colunas) informadas pelo usuário. A seguir, substitua todos os valores negativos por zero e apresente a matriz
com as modificações.
*/

#include<iostream>
using namespace std;

int main(){
	int linhas, colunas;

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

	cout<<"Matiz informada"<<endl;
		for(int i=0;i<linhas;i++){
			for(int j=0;j<colunas;j++){
				cout<<matriz[i][j]<<"  ";
			}
		cout<<endl;
		}

	//Alteração
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			if(matriz[i][j]<0) matriz[i][j]=0;
		}
	}

	cout<<"Matriz Alterada: "<<endl;
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			cout<<matriz[i][j]<<"  ";
		}
	cout<<endl;
	}

	delete(matriz);	

return(0);
}
