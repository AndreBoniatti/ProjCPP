/*
Codificar um programa em C++ para ler um número inteiro, que é a quantidade de itens do vetor N. Se a
quantidade de itens for par, substituir o 1o elemento com o 2°, o 3° com o 4° elemento e assim por diante.
Escrever o vetor N assim modificado. Se a quantidade de itens for ímpar escrever o vetor N ao contrário. O
vetor N deve ser alocado dinamicamente.
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

	if(tam%2==0){
		for(int i=0;i<tam;i++){
			if (i % 2 ==0) {			
			aux=v[i];
			v[i]=v[i+1];
			v[i+1]=aux;
			}
		}

	cout<<"Vetor modificado: "<<endl;
	for(int i=0;i<tam;i++){
		cout<<v[i]<<endl;
	}
	}

	if(tam%2!=0){
		for(int i=tam-1;i>=0;i--){
			cout<<v[i]<<endl;
		}
	}

return(0);
}
