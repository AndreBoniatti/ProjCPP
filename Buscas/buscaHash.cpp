#include<iostream>
#include<limits.h>
 
using namespace std;

void Insert(int ary[],int hFn, int Size){
    int element,pos,n=0;
 
	cout<<"Numero a ser inserido: ";
	cin>>element;
 
	pos = element % hFn;
 
	while(ary[pos]!= INT_MIN) {
		if(ary[pos]== INT_MAX)
            break;
		pos = (pos+1)%hFn;
		n++;
		if(n==Size)
            break;
	}
 
	if(n==Size) {
       	cout << "A tabela hash esta cheia de elementos" << endl;
		cout << "Nenhum local para inserir este elemento" << endl << endl;
	}
	else
        ary[pos] = element;
}
 
void Delete(int ary[],int hFn,int Size){
	int element,n=0,pos;
 
	cout<<"Elemento a ser excluido: " << endl;
	cin>>element;
 
	pos = element%hFn;
 
	while(n++ != Size){
		if(ary[pos]==INT_MIN){
			cout<<"Elemento não encontrado na tabela hash" << endl;
			break;
		}
		else if(ary[pos]==element){
			ary[pos]=INT_MAX;
			cout<<"Elemento excluido" << endl << endl;
			break;
		}
		else{
			pos = (pos+1) % hFn;
		}
	}
	if(--n==Size)
        cout<<"Elemento não encontrado na tabela hash" << endl;
}
 
void Search(int ary[],int hFn,int Size){
	int element,pos,n=0;
 
	cout<<"Elemento a ser procurado: ";
	cin>>element;
 
	pos = element%hFn;
 
	while(n++ != Size){
		if(ary[pos]==element){
			cout<<"Elemento encontrado no indice "<<pos<< endl << endl;
			break;
		}
		else
            if(ary[pos]==INT_MAX ||ary[pos]!=INT_MIN)
                pos = (pos+1) %hFn;
	}
	if(--n==Size)
        cout<<"Elemento não encontrado na tabela hash" << endl;
}
 
void display(int ary[],int Size){
	int i;
 
	cout<<"Indice\tValor" << endl;
 
	for(i=0;i<Size;i++)
        cout<<i<<"\t"<<ary[i]<< endl;
}
 
int main(){
	int Size,hFn,i,choice;
 
	cout<<"Digite o tamanho da tabela hash" << endl;
	cin>>Size;
 
	int ary[Size];
 
    cout<<"Digite a funcao Hash" << endl;
	cin>>hFn;
 
	for(i=0;i<Size;i++)
        ary[i]=INT_MIN;
 
	do{
		cout << "Menu de Opcoes" << endl;
		cout << "1-> Inserir" << endl;
		cout << "2-> Excluir" << endl;
		cout << "3-> Exibir" << endl;
		cout << "4-> Procurar" << endl;
		cout << "0-> Sair" << endl;
		cout << "Opcao: ";
		cin>>choice;
 
		switch(choice){
			case 1:
				Insert(ary,hFn,Size);
				break;
			case 2:
				Delete(ary,hFn,Size);
				break;
			case 3:
				display(ary,Size);
				break;
			case 4:
				Search(ary,hFn,Size);
				break;
			default:
				cout<<"Insira uma opcao valida" << endl;
				break;
		}
	}while(choice);
 
	return 0;
}
