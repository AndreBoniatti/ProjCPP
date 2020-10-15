/*
Escrever um programa em C++ para ler um número inteiro, que é a quantidade de itens do vetor C. Encontrar
e escrever, a seguir, o maior elemento de C. O vetor C é alocado dinamicamente.
*/

#include<iostream>
using namespace std;

int main(){
	int tam;

	cout<<"Tamanho do vetor: ";
	cin>>tam;

	//Aloca dinamicamente o vetor V
	int *v = new int[tam];

	//Realiza a leitura do vetor V
	for(int i=0;i<tam;i++){
		cout<<i+1<<"° Valor: ";
		cin>>v[i];
	}

	//Encontra o maior valor de V
	int maior=v[0];
	for(int i=1;i<tam;i++){
		if (v[i]>maior) maior=v[i];
	}

	cout<<"Maior Valor: "<<maior<<endl;

	//Remove vetor alocado da memória
	delete(v);

return(0);
}
