#include<iostream>
using namespace std;

void OrdenaPorBolha (int Vet[], int pos) {
	int aux, i, j;
	
	for (i = 0; i < pos - 1; i++) {
		for (j = i + 1; j < pos; j++) {
			if (Vet[i] > Vet[j]) {
				aux = Vet[i];
				Vet[i] = Vet[j];
				Vet[j] = aux;
			}
		}
	}
	
	for (i = 0; i < pos; i++) {
		cout << Vet[i] << "  ";
	}
}

int main() {
	int opcao;
	
	do {
		cout << "Menu de Opcoes" << endl;
		cout << "1- Media aritmetica de 3 numeros" << endl;
		cout << "2- Informar um numero inteiro e verificar se e primo" << endl;
		cout << "3- Calcular fatorial de um numero inteiro" << endl;
		cout << "4- Informar tres numeros e ordenar de forma crescente" << endl;
		cout << "5- Informar um vetor e calcular a media dos elementos" << endl;
		cout << "6- Chamar uma funcao para ordenar um vetor utilizando o bubble sort" << endl;
		cout << "7- Desafio Surpresa!" << endl;
		cout << "Opcao: ";
		cin >> opcao;
		
		if (opcao == 1) {
			float n1, n2, n3, media;
			
			cout << "Numero 1: ";
			cin >> n1;
			
			cout << "Numero 2: ";
			cin >> n2;
			
			cout << "Numero 3: ";
			cin >> n3;
			
			media = (n1 + n2 + n3) / 3;
			
			cout << "A media dos numeros e: " << media << endl;
		}
		
		if (opcao == 2) {
			int numero, cont = 0, i;
			
			cout << "Numero: ";
			cin >> numero;
			
			for (i = 1; i <= numero; i++) {
				if (numero % i == 0)
					cont++;
			}
			
			if (cont > 2)
				cout << "O numero nao e primo!" << endl;
			else
				cout << "O numero e primo!" << endl;
		}
		
		if (opcao == 3) {
			int numero, i;
			
			cout << "Numero: ";
			cin >> numero;
			
			int fatorial = 1;
			for (i = 1; i <= numero; i++) {
				fatorial *= i ;
			}
			
			cout << "Fatoria de " << numero << " = " << fatorial << endl;
		}
		
		if (opcao == 4) {
			int n1, n2, n3, aux;
			
			cout << "Numero 1: ";
			cin >> n1;
			
			cout << "Numero 2: ";
			cin >> n2;
			
			cout << "Numero 3: ";
			cin >> n3;
			
			if (n1 > n2) {
				aux = n1;
				n1 = n2;
				n2 = aux;
			}
			
			if (n1 > n3) {
				aux = n1;
				n1 = n3;
				n3 = aux;
			}
			
			if (n2 > n3) {
				aux = n2;
				n2 = n3;
				n3 = aux;
			}
			
			cout << "Valores ordenados: " << n1 << ", " << n2 << " e " << n3 << endl;
		}
		
		if (opcao == 5) {
			int i, posicoes, V[posicoes];
			
			cout << "Numero de posicoes do vetor: ";
			cin >> posicoes;
			
			float soma = 0;
			for (i = 0; i < posicoes; i++) {
				cout << "V[" << i + 1 << "]: ";
				cin >> V[i];
				soma += V[i];
			}
			
			cout << "A media dos elementos e: " << soma / posicoes << endl;
		}
		
		if (opcao == 6) {
			int posicoes, V[posicoes];
			
			cout << "Numero de posicoes: ";
			cin >> posicoes;
			
			for (int i = 0; i < posicoes; i++) {
				cout << "V[" << i + 1 << "]: ";
				cin >> V[i];
			}
			
			OrdenaPorBolha(V, posicoes);
			cout << endl;
		}
		
		if (opcao == 7) {
			cout << "Calma ai curioso!" << endl;
		}
		
	} while(opcao >=1 && opcao <=7);
	
	return (0);
}
