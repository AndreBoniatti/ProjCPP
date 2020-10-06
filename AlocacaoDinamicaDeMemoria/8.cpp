/*
Elaborar um programa em C++ que aloque dinamicamente uma matriz, de acordo com as dimensões (linhas e
colunas) informadas pelo usuário. A seguir, calcule e escreva a soma das linhas pares da matriz.
*/

#include<iostream>
using namespace std;

int main(){
	int linhas, colunas, somalpares=0;

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

	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			if(i%2==0){
				somalpares=somalpares+matriz[i][j];
			}
		}
	}
	
	cout<<"Soma das linhas pares da matriz: "<<somalpares<<endl;

	delete (matriz);


return(0);
}
