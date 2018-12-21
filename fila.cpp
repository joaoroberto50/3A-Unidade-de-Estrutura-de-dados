#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;



struct elemento{
	int dado;
	elemento *prox;
};

struct fila{
	elemento *inicio;
	elemento *fim;
	int tam;
};

fila *Criar_fila( ){
	fila *fi = new fila;
	if(fi!=NULL){
		fi->inicio = NULL;
		fi->fim = NULL;
	}
	return fi;
}

void Exclui_fila(fila *fi){
	if(fi != NULL){
		elemento *no;
		while(fi->inicio != NULL){
			no = fi->inicio;
			fi->inicio=fi->inicio->prox;
			delete no;
			}
		delete fi;
	}
}

int Tamanho(fila *fi){
	if(fi==NULL) return 0;
	int cont = 0;
	elemento *no = fi->inicio;
	while(no!=NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}

int Insere(fila *fi, int dado){
	if(fi==NULL) return 0;
	elemento *no = new elemento;
	if(no==NULL) return 0;
	no->dado = dado;
	no->prox = NULL;
	if(fi->fim == NULL)
		fi->inicio = no;
	else
		fi->fim->prox = no;
	fi->fim = no;
	fi->tam++;
	cout<<"\nElemento "<<dado<<" foi adicionado com sucesso\n"<<endl;
	return 1;
}

int Exclui(fila *fi){
	if(fi==NULL) return 0;
	if(fi->fim == NULL)
		return 0;
	elemento *no = fi->inicio;
	cout<<"\nElemento "<<no->dado<<" Foi excluido com sucesso\n"<<endl;
	fi->inicio = fi->inicio->prox;
	if (fi->inicio == NULL)
		fi->fim = NULL;
	delete no;
	fi->tam--;
	return 1;
}


void mostra_fila(fila *fi){
	elemento *no;
	no = fi->inicio;
	while(no!=NULL){
		cout<< no->dado <<endl;
		no = no->prox;
	}
}

int random(int menor, int maior){
	srand((unsigned)time(0)); //gerar um numero aleatorio
	int ale= rand()%(maior-menor)+menor;
	return ale;
}

int main(int argc, char const *argv[]){
	fila *fi;
	int xis;
	
	fi = Criar_fila();
	
	while(clock()<6000){
		xis = random(-16000, 16000);
		
		if(fi->tam >= 6){
			Exclui(fi);
			mostra_fila(fi);
			sleep_for (seconds(4));
		}
		else{
			int x = Insere(fi,xis);
			mostra_fila(fi);
			sleep_for (seconds(5));
		}
	}
	
	Exclui_fila(fi);
	
	return 0;
}
