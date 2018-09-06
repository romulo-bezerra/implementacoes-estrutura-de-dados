#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	struct Lista *ant;
	int elemento;
	struct Lista *prox;
}celula;

void insereInicio(celula **inicio, int ele){
	celula *aux, *novo = (celula*)malloc(sizeof(celula));
	novo->elemento = ele;
	if (*inicio == NULL){
		novo->prox = NULL;
		novo->ant = NULL;
		*inicio = novo;
	}else{
		novo->prox = *inicio;
		aux->ant = novo;
		novo->ant = NULL;
		*inicio = novo;	
	}
	printf("\nAdicionado no inicio com sucesso!\n\n");
}

void insereMeio(celula **inicio, int ele){
	celula *novo = (celula*)malloc(sizeof(celula));
	celula *aux = *inicio, *anterior = NULL;
	novo->elemento = ele;
	novo->prox = NULL;
	novo->ant = NULL;	
	if (*inicio == NULL){
		*inicio = novo;
	}
	else if (aux->ant == NULL && aux->elemento > ele){
		novo->prox = aux;
		novo->ant = NULL;
		aux->ant = novo;
		*inicio = novo;
	}
	else{
		while (aux != NULL && aux->elemento < ele){
			anterior = aux;
			aux = aux->prox;
		}
		if (anterior != NULL && anterior->prox != NULL){
			anterior->prox = novo;
			novo->prox = aux;
			novo->ant = anterior;
			aux->ant = novo;
		}
		else{
			anterior->prox = novo;
			novo->prox = aux;
			novo->ant = anterior;
		}	
	}
	printf("\nAdicionado com sucesso!\n\n");		
}
 
void insereFinal(celula **inicio, int ele){
	celula *pegaAntes = *inicio; 
	celula *aux = *inicio;
	celula *novo = (celula*)malloc(sizeof(celula));
	novo->prox = NULL;
	novo->ant = NULL;
	novo->elemento = ele;
	if(*inicio == NULL){
		*inicio = novo;
	}
	else{
		while (aux != NULL){
			pegaAntes = aux;
			aux = aux->prox;
		}
		novo->prox = NULL;
		novo->ant = pegaAntes;
		pegaAntes->prox = novo;
	}
	printf("\nAdicionado no fim com sucesso!\n\n");
}

void removeInicio(celula **inicio){
	if (*inicio == NULL)
		printf("\nNao existe lista!\n\n");
	else{
		celula *aux = *inicio;
		*inicio = aux->prox;
		free(aux);
	}
	printf("\nVoce removeu o primeiro elemento da lista!\n\n");	
}

void removeMeio(celula **inicio, int ele){
	celula *aux = *inicio, *pegaAntes, *pegaDepois;
	if (*inicio == NULL)
		printf("\nNao existe nenhum elemento na lista!\n\n");
	else{
		while (aux != NULL && aux->elemento != ele){
			pegaAntes = aux;
			aux = aux->prox;
		}
		if (aux == NULL) 
			printf("\nNao existe o elemento na lista!\n\n");
		else if (aux == *inicio){
			*inicio = aux->prox;
			free(aux);
			printf("\nA remocao no inicio foi um sucesso!\n\n");
		}
		else if (aux->elemento == ele && aux->prox == NULL){
			pegaAntes->prox = aux->prox;
			free(aux);
			printf("\nA remocao no fim foi um sucesso!\n\n");
		}
		else{
			pegaAntes->prox = aux->prox;
			pegaDepois = aux->prox;
			pegaDepois->ant = pegaAntes;
			free(aux);
			printf("\nA remocao foi um sucesso!\n\n");
		}
	}		
}


void removeFinal(celula **inicio){
	celula *aux = *inicio; 
	celula *pegaAntes, *pegaAnteAntes;
	if (*inicio == NULL)
		printf("\nLista ja esta vazia!\n\n");
	else{
		while (aux != NULL){
			pegaAntes = aux;
			aux = aux->prox;
		}
		if (aux == *inicio){		
			*inicio = NULL;
			free(aux);
		}
		else{
			pegaAnteAntes = pegaAntes->ant;
			pegaAnteAntes->prox = NULL;
			free(pegaAntes);
		}	
	}
	printf("\nVoce removeu o ultimo elemento da lista\n\n!");			
}	

void printar(celula *inicio){
	celula *aux;
	aux = inicio;
	if (aux != NULL){
		printf("\nResultado:\n\n");
		do{
			printf(" <- %d -> ", aux->elemento);
			aux = aux->prox;
		}while(aux != NULL);
		printf("\n\n");
	}
	else printf("\nLista!\n\n");
}

int main(){
	celula *inicio = NULL;
	int ele, opt;
	do{
		printf("MENU\n");
		printf("Digite 1 para inserir no inicio: \n");
		printf("Digite 2 para inserir ordenadamente: \n");
		printf("Digite 3 para inserir no fim: \n");
		printf("Digite 4 para remover no inicio: \n");
		printf("Digite 5 para remover determinado elemento: \n");
		printf("Digite 6 para remover no fim: \n");
		printf("0 para sair: \n");	
		printf("Opcao: ");
		scanf("%d", &opt);
		switch (opt){
			case 1:
				printf("\nEscreva um numero: ");
				scanf("%d", &ele);
				insereInicio(&inicio, ele);
			break;
			
			case 2:
				printf("\nEscreva um numero: ");
				scanf("%d", &ele);
				insereMeio(&inicio, ele);
			break;
			
			case 3:
				printf("\nEscreva um numero: ");
				scanf("%d", &ele);
				insereFinal(&inicio, ele);
			break;
			
			case 4:
				removeInicio(&inicio);
			break;

			case 5:
				printf("\nEscreva o numero que deseja remover: ");
				scanf("%d", &ele);
				removeMeio(&inicio, ele);
			break;
			
			case 6:
				removeFinal(&inicio);
			break;
			
			case 0:
				printf("\nVoce Saiu!\n");
			
			default: 
				printf("\nValor Invalido!\n\n");
				
		}	
	}while (opt != 0);
	printar(inicio);
	
	system("pause");
	return 0;
}
