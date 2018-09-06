#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int elemento;
    struct Pilha *prox;
} celula;

//Empilha elemento

void push(celula **inicio, int ele) {
    celula *novo = (celula*) malloc(sizeof (celula));
    novo->elemento = ele;
    novo->prox = *inicio;
    *inicio = novo;
}

//Conta a quantidade de nodos da pilha

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

//Desempilha elemento

int pop(celula **inicio) {
    celula *aux = *inicio;
    int resultado = (*inicio)->elemento;
    *inicio = (*inicio)->prox;
    free(aux);
    return resultado;
}

//Verifica se a pilha esta vazia

int isVazia(celula **inicio) {
    if (*inicio == NULL) return 1;
    return 0;
}

int main() {
    celula *inicio = NULL;
    int ele;
    printf("\n0 para sair e mostrar os resultados!");
    printf("\nEscreva um numero que deseja adionar: ");
    scanf("%d", &ele);
    while (ele != 0) {
        push(&inicio, ele);
        printf("\n0 para sair e mostrar os resultados!");
        printf("\nEscreva um numero que deseja adionar: ");
        scanf("%d", &ele);
    }
    printf("\nQuantidade de registros: %d\n", conta(&inicio));
    printf("\nNumeros desempilhados:\n");
    while (isVazia(&inicio) == 0) {
        ele = pop(&inicio);
        printf("%d -> ", ele);
    }
    printf("\n\n");

    system("pause");
    return 0;
}
