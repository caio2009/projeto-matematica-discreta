#include <stdio.h>
#include <stdlib.h>

int jaExisteElemento(int *array, int tamanho, int elemento);
void uniao(int *conjuntoA, int tamanhoConjuntoA, int *conjuntoB, int tamanhoConjuntoB);

int main() {
    int continuarRodando = 1;
    int i;
    int qtdElementosConjuntoA;
    int qtdElementosConjuntoB;
    int opcaoEscolhida;
    int elemento;

    printf("Digite a quantidade de elementos do conjunto A: ");
    scanf("%i", &qtdElementosConjuntoA);
    printf("Digite a quantidade de elementos do conjunto B: ");
    scanf("%i", &qtdElementosConjuntoB);

    int conjuntoA[qtdElementosConjuntoA];
    int conjuntoB[qtdElementosConjuntoB];

    printf("--------------------------------------------------------------------------------\n");
    printf("Definindo elementos do Conjunto A\n\n");
    for (i = 0; i < qtdElementosConjuntoA; i++) {
        printf("Digite o valor do #%i elemento: ", i + 1);
        scanf("%i", &elemento);
        if (jaExisteElemento(conjuntoA, qtdElementosConjuntoA, elemento)) {
            printf("Já existe esse elemento dentro do conjunto A!\n");
            i--;
        } else {
            conjuntoA[i] = elemento;
        }
    }

    printf("--------------------------------------------------------------------------------\n");
    printf("Definindo elementos do Conjunto B\n\n");
    for (i = 0; i < qtdElementosConjuntoB; i++) {
        printf("Digite o valor do #%i elemento: ", i + 1);
        scanf("%i", &elemento);
        if (jaExisteElemento(conjuntoB, qtdElementosConjuntoB, elemento)) {
            printf("Já existe esse elemento dentro do conjunto B!\n");
            i--;
        } else {
            conjuntoB[i] = elemento;
        }
    }

    while (continuarRodando) {
        printf("--------------------------------------------------------------------------------\n");

        printf("A = { ");
        for (i = 0; i < qtdElementosConjuntoA; i++) {
            if (i == qtdElementosConjuntoA - 1)
                printf("%i", conjuntoA[i]);
            else
                printf("%i, ", conjuntoA[i]);
        }
        printf(" }\n");

        printf("B = { ");
        for (i = 0; i < qtdElementosConjuntoB; i++) {
            if (i == qtdElementosConjuntoB - 1)
                printf("%i", conjuntoB[i]);
            else
                printf("%i, ", conjuntoB[i]);
        }
        printf(" }\n\n");

        printf("Escolha uma opção:\n\n");
        printf("1 - Diferença\n");
        printf("2 - Intersecção\n");
        printf("3 - União\n");
        printf("0 - Sair\n\n");
        scanf("%i", &opcaoEscolhida);
        printf("\n");

        switch (opcaoEscolhida) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                uniao(conjuntoA, qtdElementosConjuntoA, conjuntoB, qtdElementosConjuntoB);
                break;
            case 0:
                continuarRodando = 0;
                break;
            default:
                continue;
        }
    }

    return 0;
}

int jaExisteElemento(int *array, int tamanho, int elemento) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (array[i] == elemento) return 1;
    }
    return 0;
}

void uniao(int *conjuntoA, int tamanhoConjuntoA, int *conjuntoB, int tamanhoConjuntoB) {
    int elementoAMais = 0;
    int i;
    int maior;
    int menor;
    int tamanhoConjuntoUniao;
    int *maiorConjunto;
    int *menorConjunto;
    int *uniao;

    if (tamanhoConjuntoA >= tamanhoConjuntoB) {
        maior = tamanhoConjuntoA;
        maiorConjunto = conjuntoA;
        menor = tamanhoConjuntoB;
        menorConjunto = conjuntoB;
    } else {
        maior = tamanhoConjuntoB;
        maiorConjunto = conjuntoB;
        menor = tamanhoConjuntoA;
        menorConjunto = conjuntoA;
    }

    // Criar um vetor dinâmico para poder armazenar a união entre os dois conjuntos.

    uniao = (int *) malloc((maior + menor) * sizeof(int));
    for (i = 0; i < maior; i++) {
        uniao[i] = maiorConjunto[i];
    }
    for (i = 0; i < menor; i++) {
        if (!jaExisteElemento(maiorConjunto, maior, menorConjunto[i])) {
            uniao[maior + elementoAMais] = menorConjunto[i];
            elementoAMais++;
        }
    }

    tamanhoConjuntoUniao = maior + elementoAMais;
    if (tamanhoConjuntoUniao < maior + menor) {
        uniao = (int *) realloc(uniao, tamanhoConjuntoUniao * sizeof(int));
    }

    // Imprimir na tela.

    printf("S = { ");
    for (i = 0; i < tamanhoConjuntoUniao; i++) {
        if (i < tamanhoConjuntoUniao - 1) printf("%i, ", uniao[i]);
        else printf("%i", uniao[i]);
    }
    printf(" }\n\n");
}
