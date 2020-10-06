/*
Elaborar um programa em C++ para ler um número inteiro, que é a quantidade de itens do vetor A. Ordenar e
escrever a seguir os elementos de A em ordem crescente. O vetor A é alocado dinamicamente.
*/

#include<iostream>
using namespace std;

int main(){
	int tam,aux;

	cout<<"Tamanho do vetor: ";
	cin>>tam;

	int *v = new int[tam];

	for(int i=0;i<tam;i++){
		cout<<i+1<<"° Valor: ";
		cin>>v[i];
	}

	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			if(v[i]<v[j]){
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
		}
	}

	cout<<"Valores ordenados: "<<endl;
		for(int i=0;i<tam;i++){
	cout<<v[i]<<endl;
	}

	delete(v);

return(0);
}
