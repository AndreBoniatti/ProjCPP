/*
Desenvolver um programa em C++ para ler um número inteiro, que é a quantidade de itens do vetor X. Alocar
memória para os vetores P e N para armazenar os valores positivos e negativos informados no vetor X.
Escrever os vetores P e N. Os vetores X, P e N devem ser alocados dinamicamente.
*/

#include<iostream>
using namespace std;

int main(){
	int tam, pos, neg;

	cout<<"Tamanho do vetor: ";
	cin>>tam;

	int *x = new int[tam];

	pos = 0; neg = 0;
	for(int i=0;i<tam;i++){
		cout<<i+1<<"° Valor: ";
		cin>>x[i];
		if(x[i]>=0) pos++;
		else neg++;
	}

	int *p = new int[pos];
	int *n = new int[neg];

	pos = 0; neg = 0;
	for(int i=0;i<tam;i++){
		if(x[i]>=0){
			p[pos]=x[i];
			pos++;
		}else{
			n[neg]=x[i];
			neg++;
		}
	}

	cout<<"Vetor P: "<<endl;
	for(int i=0;i<pos;i++){
		cout<<p[i]<<endl;
	}

	cout<<"Vetor N: "<<endl;
	for(int i=0;i<neg;i++){
		cout<<n[i]<<endl;
	}

	delete(x);
	delete(p);
	delete(n);

return(0);
}
