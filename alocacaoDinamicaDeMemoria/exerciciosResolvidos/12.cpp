/*
Codificar um programa em C++ que aloque dinamicamente uma matriz, de acordo com as dimensões (linhas e
colunas) informadas pelo usuário. A seguir, calcule o percentual de números múltiplos de 7 armazenados na
matriz.
*/

#include<iostream>
using namespace std;

int main(){
	int linhas, colunas;
	float percmult7=0,cont=0;

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
			if(matriz[i][j]%7==0) cont++;
		}
	}
	
	percmult7=(cont/(linhas*colunas))*100;
	cout<<"Percentual de múltiplos de 7: "<<percmult7<<endl;

	delete(matriz);	

return(0);
}
