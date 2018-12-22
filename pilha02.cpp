#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

typedef struct Reg{
	int infor;
	Reg *prox;
}No;

typedef struct TipoPilha{
	No * Topo;
	int tamanho;
}Pilha;

Pilha *IniciaPilha(Pilha *PL){
	PL->Topo=NULL;
	PL->tamanho=0;
	return PL;
}

int PilhaVazia(Pilha *PL){
	return (PL->Topo == NULL);
}

Pilha *Empilhar(Pilha *PL, int dado){ 
	No *novo;
	novo = new No;
	novo->infor = dado;
	novo->prox = PL->Topo;
	PL->Topo = novo;
	cout<<"\nElemento "<<dado<<" entrando na fila\n"<<endl;
	PL->tamanho++;
	return PL;
}

Pilha *Desempilhar(Pilha *PL){
	No *aux;
	int sai;
	if (PilhaVazia(PL)) cout<<"PILHA VAZIA!"<<endl;
	else{	
		aux=PL->Topo;
		PL->Topo=aux->prox;
		sai=aux->infor;
		cout<<"\nElemento "<<sai<<" saindo da Pilha!\n"<<endl;
		PL->tamanho--;
		delete aux;
	}
	return PL;
}

void ImprimirPilha(Pilha *PL){ 
	No *copia;
	copia=PL->Topo;
	int cont = 1;
	if(PilhaVazia(PL)) cout<<"PILHA VAZIA!"<<endl;
	else{
		while(copia!=NULL){
			cout<<copia->infor<<endl;
			copia=copia->prox;
			cont++;
		}
	}
}

int random(int menor, int maior){
	srand((unsigned)time(0)); 
	int ale= rand()%(maior-menor)+menor;
	return ale;
}


int main(int argc, char const *argv[])
{
	Pilha *pi;

	pi = IniciaPilha(pi);

	int x = PilhaVazia(pi);

	int xis;

	while(clock()<6000){
		xis = random(-16000, 16000);
		
		if(pi->tamanho >= 3){
			while(pi->tamanho != 0){
				pi = Desempilhar(pi);
				ImprimirPilha(pi);
				sleep_for (seconds(4));
			}
		}
		else{
			pi = Empilhar(pi,xis);
			ImprimirPilha(pi);
			sleep_for (seconds(5));
		}
	}

	//Exclui_pilha(pi);

	return 0;
}