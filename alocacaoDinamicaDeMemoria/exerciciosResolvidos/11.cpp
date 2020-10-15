/*
Escrever um programa em C++ que aloque dinamicamente uma matriz, de acordo com as dimensões (linhas e
colunas) informadas pelo usuário. A seguir, calcule a diferença entre as somas das diagonais principais e
secundárias.
*/

#include<iostream>
using namespace std;

int main(){
	int linhas, colunas,sdp=0,sds=0,difsdpsds=0;

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

	//Soma diagonal Principal e Secundária
	for(int i=0;i<linhas;i++){
		sdp=sdp+matriz[i][i];
		sds=sds+matriz[i][linhas-i-1];
	}
	
	difsdpsds=sdp-sds;
	
	cout<<"Diferença entre as diagonais: "<<difsdpsds<<endl;

	delete(matriz);

return(0);
}
