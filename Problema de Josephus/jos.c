#include<stdio.h>
#include<stdlib.h>
#include"jos.h"

Lista *cria_lista(int tamanho){

	Lista *li = (Lista *)malloc(sizeof(Lista));
	
	if(tamanho > 0){
	
		if(li != NULL){
	
			li->qtd = tamanho;
			Elemento *no = (Elemento *)malloc(sizeof(Elemento));
			li->ini = no;
			no->valor = 1;
			Elemento *aux,*ant = no;
			int i = 2;
			while(i <= tamanho){
				 
				aux = (Elemento *)malloc(sizeof(Elemento));
				ant->prox = aux;
				aux->valor = i;
				ant = aux;
				i++;
			
			}
			
			ant->prox = no;
	
		}
	
	}
	
	return li;

}

int resolve_problema(Lista *li,int n){

	if(li == NULL)
		return 0;
	if(li->qtd == 0)
		return 0;
	if(li->qtd == 1)
		return li->ini->valor;
	
	Elemento *aux = li->ini, *ant = NULL;
	
	while(li->qtd > 1){
		int cont = 0;
		while(cont < (n-1)){
			ant = aux;
			aux = aux->prox;
			cont++;
		}
		
		// qtd = 5,4,3,2,1
		// cont = 0,1,2
		// ant = 2,4,
		// aux = 2,4,2
		// cortados: 3,1,5,2
		
		if(aux == li->ini)			// ini = 4
			li->ini = aux->prox;
		
		ant->prox = aux->prox;
		free(aux);
		aux = ant->prox;
		li->qtd--;
	}
	
	return li->ini->valor;

}

int print_lista(Lista *li){

	if(li == NULL)
		return 0;
	if(li->qtd == 0)
		return 0;
	
	Elemento *aux = li->ini;
	
	int i = 0;
	while(i < li->qtd){
		printf("------------------\n");
		printf("Valor: %d\n",aux->valor);
		printf("------------------\n");
		aux = aux->prox;
		i++;
	}
	
	return 1;

}

int libera_lista(Lista *li){

	if(li == NULL)
		return 0;
	
	Elemento *aux;
	
	int i = 0;
	while(i < li->qtd){
	
		aux = li->ini;
		li->ini = li->ini->prox;
		li->qtd--;
		i++;
		free(aux);
		
	}
	
	free(li);
	
	return 1;

}
