#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	int elemento;
	struct Lista *prox;
}celula;

void insereInicio(celula **inicio, int ele){
	celula *novo = (celula*)malloc(sizeof(celula));
	novo->elemento = ele;
	if (*inicio==NULL){
		novo->prox = NULL;
		*inicio = novo;
	}else{
		novo->prox = *inicio;
		*inicio = novo;	
	}
}

void insereMeio(celula **inicio, int ele){
	celula *novo = (celula*) malloc(sizeof(celula));
	celula *anterior = NULL;
	celula *aux = *inicio;
	novo->elemento = ele;	
	while (aux != NULL && aux->elemento < ele){
		anterior = aux;
		aux = aux->prox;
	}
	if (anterior == NULL){
		novo->prox = *inicio;
		*inicio = novo;
	}
	else{
		anterior->prox = novo;
		novo->prox = aux;
	}	
} 

void insereFinal(celula **inicio, int ele){
	celula *novo, *anterior, *aux;
	novo = (celula*)malloc(sizeof(celula));
	novo->prox = NULL;
	novo->elemento = ele;
	aux = *inicio;
	anterior = NULL;
	if(*inicio == NULL){
		*inicio = novo;
	}
	else{
		while (aux!=NULL){
			anterior = aux;
			aux = aux->prox;
		}
		anterior->prox = novo;
	}
}

void removeInicio(celula **inicio){
	if (*inicio == NULL)
		printf("\nNao existe lista!\n\n");
	else{
		celula *aux;
		aux = *inicio;
		*inicio = aux->prox;
		free(aux);
	}	
}

void removeMeio(celula **inicio, int ele){
	celula *aux = *inicio, *anterior;
	if (*inicio == NULL)
		printf("\nNao existe nenhum elemento na lista!\n\n");
	else{
		while (aux != NULL && aux->elemento != ele){
			anterior = aux;
			aux = aux->prox;
		}
		if (aux == NULL) 
			printf("\nNao existe o elemento na lista!\n\n");
		if (aux == *inicio)
			*inicio = aux->prox;
		else
			anterior->prox = aux->prox;
		free(aux);		
	}		
}

void removeFinal(celula **inicio){
	celula *aux, *anterior;
	aux = *inicio;
	if (*inicio == NULL)
		printf("\nLista ja esta vazia!\n\n");
	else{
		while (aux->prox!=NULL){
			anterior = aux;
			aux = aux->prox;
		}
		if (aux == *inicio)
			*inicio = aux->prox;
		else
			anterior->prox = NULL;
		free(aux);	
	}			
}	

void printar(celula *inicio){
	celula *aux;
	aux = inicio;
	if (aux != NULL){
		printf("\nResultado:\n\n");
		do{
			printf("%d -> ", aux->elemento);
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
				printf("Escreva o numero que quer remover: ");
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
