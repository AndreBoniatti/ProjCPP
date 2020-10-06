/*
Escrever um programa em C++ para realizar a multiplicação de uma matriz A por uma matriz B e armazenar o
resultado em uma matriz C. Escrever a matriz C. Leia a dimensão das matrizes através do teclado. As matrizes
A, B e C são alocadas dinamicamente.
*/

#include<iostream>
using namespace std;

int main(){
	int linhas, colunas;

	cout<<"Linhas: ";
	cin>>linhas;

	cout<<"Colunas: ";
	cin>>colunas;

	int **a=new int*[linhas];

	for(int i=0;i<linhas;i++){
		a[i]=new int[colunas];
	}

	int **b=new int*[linhas];

	for(int i=0;i<linhas;i++){
		b[i]=new int[colunas];
	}

	int **c=new int*[linhas];

	for(int i=0;i<linhas;i++){
		c[i]=new int[colunas];
	}

	//Lendo primeiro vetor
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			cout<<"A["<<i+1<<"]["<<j+1<<"]: ";
			cin>>a[i][j];
		}
	}

	cout<<"Matiz informada"<<endl;
		for(int i=0;i<linhas;i++){
			for(int j=0;j<colunas;j++){
				cout<<a[i][j]<<"  ";
			}
		cout<<endl;
		}

	//Segunda Matriz
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			cout<<"B["<<i+1<<"]["<<j+1<<"]: ";
			cin>>b[i][j];
		}
	}

	cout<<"Matiz informada"<<endl;
		for(int i=0;i<linhas;i++){
			for(int j=0;j<colunas;j++){
				cout<<b[i][j]<<"  ";
			}
		cout<<endl;
		}

	//Multiplicação das matrizes
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			c[i][j]=a[i][j]*b[i][j];
		}
	}

	cout<<"Matiz Alterada"<<endl;
		for(int i=0;i<linhas;i++){
			for(int j=0;j<colunas;j++){
				cout<<c[i][j]<<"  ";
			}
		cout<<endl;
		}

	delete(a);	
	delete(b);
	delete(c);

return(0);
}
