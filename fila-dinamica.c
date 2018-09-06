#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int elemento;
    struct Fila *prox;
} celula;

//Cria um novo elemento

void enfileira(celula **inicio, int ele) {
    celula *aux, *novo = (celula*) malloc(sizeof (celula));
    novo->elemento = ele;
    novo->prox = NULL;
    if (*inicio == NULL) *inicio = novo;
    else {
        aux = *inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

//Conta a quantidade de nodos da fila

int conta(celula **inicio) {
    celula *aux = *inicio;
    int cont;
    if (*inicio == NULL) return 0;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int desenfileira(celula **inicio) {
    celula *aux = *inicio;
    int resultado = (*inicio)->elemento;
    *inicio = (*inicio)->prox;
    free(aux);
    return resultado;
}

//Verifica se esta vazia

int isVazia(celula **inicio) {
    if (*inicio == NULL) return 1;
    return 0;
}

int main() {
    celula *inicio = NULL;
    int ele;
    printf("\n0 para sair e mostrar o resultado!");
    printf("\nEscreva um numero que deseja enfileirar: ");
    scanf("%d", &ele);
    while (ele != 0) {
        enfileira(&inicio, ele);
        printf("\n0 para sair e mostrar o resultado!");
        printf("\nEscreva um numero que deseja enfileirar: ");
        scanf("%d", &ele);
    }
    printf("\nQuantidade de registros: %d\n", conta(&inicio));
    printf("\nNumeros desenfileirados:\n");
    while (isVazia(&inicio) == 0) {
        ele = desenfileira(&inicio);
        printf("%d -> ", ele);
    }
    printf("\n\n");

    system("pause");
    return 0;
}
