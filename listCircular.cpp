#include <iostream>

using namespace std;

struct ligacao{
	int prioridade;
	int codigo;
};

struct elem{
	ligacao dado;
	elem *prox;
};

typedef struct elem *lista; 

lista *Cria_Lista(){
	lista *li = new lista;
	if(li != NULL){
		*li = NULL;
	}
	return li;
}
/*
int Insere_Inicio(lista *li, ligacao info){
	if(li == NULL) return 0;
	elem *no = new elem;
	if(no == NULL)return 0;
	no->dado = info;
	elem *temp = *li;
	if((*li) == NULL || li*->dado.prioridade == 2){
		if(*fi == NULL){
			*li = no;
			no->prox = no;
		}
		else{
			*li = no;
			while(temp->prox != *li ){

			}
		}
	}
	else{
		elem *aux = *li;
		
		while(aux->prox != (*li) || aux->dado.prioridade == aux->prox->dado.prioridade){
			aux = aux->prox;
		}
		if(aux->prox == *li){
			aux->prox = no;
			no->prox = *li;
			*li = no;
		}
		else{
			temp->prox = aux->prox;
			aux->prox = no;
			no->prox = temp->prox;
		}
	}
	return 1;
}
*/

int Insere_Final(lista *li, ligacao info){
	if(li == NULL) return 0;
	elem *no = new elem;
	if(no == NULL)return 0;
	no->dado = info;
	if((*li) == NULL){
		*li = no;
		no->prox = no;
	}
	else{
		elem *aux = *li;
		while(aux->prox != (*li)){
			aux = aux->prox;
		}
		aux->prox = no;
		no->prox = *li;
	}
	return 1;
}

int Insere_Apenas(lista *li, ligacao info){
	if(li == NULL) return 0;
	elem *no = new elem;
	if(no == NULL)return 0;
	no->dado = info;
	if((*li) == NULL){
		*li = no;
		no->prox = no;
	}
	else{
		elem *ant = *li, *atual = (*li)->prox;
		while(atual->prox != (*li) || atual->prox->dado.prioridade != 2 && atual->dado.codigo > info.codigo){
			ant = atual;
			atual = atual->prox;
		}
		no->prox = atual;
		ant->prox = no;
		atual = atual->prox;

	}
	return 1;
}

int Tamanho_Lista(lista *li){
	if(li == NULL || (*li) == NULL)
		return 0;
	int cont = 0;
	elem *no = *li;
	do{
		cont++;
		no = no->prox;
	}while(no != (*li));
	return cont;
}

int Remove_Inicio(lista *li){
	if(li == NULL) return 0;
	if((*li) == NULL) return 0;
	if((*li) == (*li)->prox){
		cout<<"A ligaçao codigo: "<<(*li)->dado.codigo<<" esta sendo excluida"<<endl;
		delete *li;
		*li = NULL;
	}
	elem *atual = *li;
	while(atual->prox != (*li)){
		atual = atual->prox;
	}
	elem *no = *li;
	atual->prox = no->prox;
	(*li)->prox = no->prox;
	cout<<"A ligaçao codigo: "<<(*li)->dado.codigo<<" esta sendo excluida"<<endl;
	delete no;
	return 1;
}

void Imprime_Lista(lista *li){
	if(li == NULL || (*li) == NULL) return;
	elem *no = *li;
	do{
		cout<<"Prioridade = "<<no->dado.prioridade<<endl;
		cout<<"codigo = "<<no->dado.codigo<<endl;
		cout<<"-----------------------------------\n"<<endl;
		no = no->prox;
	}while(no != (*li));
}


void Libera_Lista(lista *li){
	if(li != NULL && (*li) != NULL){
		elem *aux, *no = *li;
		while((*li) != no->prox){
			aux = no;
			no = no->prox;
			delete  aux;
		}
		delete  no;
		delete  li;
		cout<<"Todas as ligaçoes foram liberadas"<<endl;
	}
}

void Menu(lista *li){
	ligacao prio;
	bool sus = true;
	int op;
	int data1 = 1000, data2 = 2000;
	int y, z;
	while (op != 6){
		cout<<"\n\nEscolha uma opçao:\n1) Adicionar uma nova ligaçao\n2) Liberar uma ligaçao\n3) Tamanho da Lista\n4) Liberar todas as Ligaçoes\n5) Imprimir a Lista\n6) Sair"<<endl;
		cin>>op;
		if(op == 1){ 
			cout<<"È priotaria a ligaçao(1 p/ Sim, 2 p/ Não)?"<<endl;
			cin>>prio.prioridade;
			if(prio.prioridade == 2){
				data2++;
				prio.codigo = data2;
				y = Insere_Final(li, prio);
			}
			else if(prio.prioridade == 1){
				data1++;
				prio.codigo = data1;
				y = Insere_Apenas(li, prio);
			}
			else{
				cout<<"ERRO: valor digitado invalido"<<endl;
			}
		}
		else if(op == 2){
			z = Remove_Inicio(li);
		}
		else if(op == 3){
			int x = Tamanho_Lista(li);
			cout<<"Nº de ligaçoes em espera = "<<x<<endl;
		}
		else if(op == 4){
			Libera_Lista(li);
		}
		else if(op == 5){
			Imprime_Lista(li);
		}
		else if(op == 6){
			sus = false;
		}
		else{
			cout<<"ERRO: valor digitado invalido"<<endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	lista *li;

	li = Cria_Lista();

	Menu(li);

	return 0;
}
