/*
Codificar um programa em C++ para ler o número de linhas e colunas da matriz F e um valor para a variável A.
Armazenar os valores da matriz F multiplicados por A em um vetor V. Escrever os valores do vetor V. A matriz F
e o vetor V devem ser alocados dinamicamente.
*/

#include<iostream>
using namespace std;

int main(){
	int linhas, colunas,a;

	cout<<"Linhas: ";
	cin>>linhas;

	cout<<"Colunas: ";
	cin>>colunas;

	cout<<"Valor para multiplicação: ";
	cin>>a;

	//Matriz
	int **f=new int*[linhas];

	for(int i=0;i<linhas;i++){
		f[i]=new int[colunas];
	}
	
	//Vetor
	int *v = new int[linhas*colunas];

	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			cout<<"F["<<i+1<<"]["<<j+1<<"]: ";
			cin>>f[i][j];
		}
	}

	cout<<"Matiz informada"<<endl;
		for(int i=0;i<linhas;i++){
			for(int j=0;j<colunas;j++){
				cout<<f[i][j]<<"  ";
			}
		cout<<endl;
		}

	//Multiplicação da Matriz por a
	int cont = 0;
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			v[cont] = f[i][j]*a;
			cont++;
		}
	}

	cout<<"Valores Alterados"<<endl;
		for(int i=0;i<linhas*colunas;i++){
				cout<<v[i]<<endl;
			}
		
	delete(f);
	delete(v);

return(0);
}
