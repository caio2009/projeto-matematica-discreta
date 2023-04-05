#include <stdio.h>
#include <stdlib.h>

void diferenca(int *conjuntoA, int qtdElementosConjuntoA, int *conjuntoB, int qtdElementosConjuntoB);
void interseccao(int *conjuntoA, int qtdElementosConjuntoA, int *conjuntoB, int qtdElementosConjuntoB);
int jaExisteElemento(int *array, int tamanho, int elemento);
void uniao(int *conjuntoA, int qtdElementosConjuntoA, int *conjuntoB, int qtdElementosConjuntoB);

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
        if (i != 0 && jaExisteElemento(conjuntoA, qtdElementosConjuntoA, elemento)) {
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
        if (i != 0 && jaExisteElemento(conjuntoB, qtdElementosConjuntoB, elemento)) {
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
                diferenca(conjuntoA, qtdElementosConjuntoA, conjuntoB, qtdElementosConjuntoB);
                break;
            case 2:
                interseccao(conjuntoA, qtdElementosConjuntoA, conjuntoB, qtdElementosConjuntoB);
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

void diferenca(int *conjuntoA, int qtdElementosConjuntoA, int *conjuntoB, int qtdElementosConjuntoB) {
    int i;
    int qtdElementosConjuntoDiferenca = 0;
    int *diferenca;

    // Criar um vetor dinâmico para poder armazenar a diferença entre os dois conjutos.

    diferenca = (int *) malloc(qtdElementosConjuntoA * sizeof(int));
    for (i = 0; i < qtdElementosConjuntoA; i++) {
        if (!jaExisteElemento(conjuntoB, qtdElementosConjuntoB, conjuntoA[i])) {
            diferenca[qtdElementosConjuntoDiferenca++] = conjuntoA[i];
        }
    }

    if (qtdElementosConjuntoDiferenca < qtdElementosConjuntoA) {
        diferenca = (int *) realloc(diferenca, qtdElementosConjuntoDiferenca * sizeof(int));
    }

    // Imprimir na tela.

    printf("S = { ");
    for (i = 0; i < qtdElementosConjuntoDiferenca; i++) {
        if (i < qtdElementosConjuntoDiferenca - 1) printf("%i, ", diferenca[i]);
        else printf("%i", diferenca[i]);
    }
    printf(" }\n\n");
}

void interseccao(int *conjuntoA, int qtdElementosConjuntoA, int *conjuntoB, int qtdElementosConjuntoB) {
    int i;
    int maior;
    int menor;
    int qtdElementosConjuntoInterseccao = 0;
    int *interseccao;
    int *menorConjunto;
    int *maiorConjunto;

    // Achar o menor e maior o conjunto.
    // E achar o tamanho do menor conjunto para determinar a quantidade máxima de elementos do conjunto da intersecção.

    if (qtdElementosConjuntoA >= qtdElementosConjuntoB) {
        maior = qtdElementosConjuntoA;
        maiorConjunto = conjuntoA;
        menor = qtdElementosConjuntoB;
        menorConjunto = conjuntoB;
    } else {
        maior = qtdElementosConjuntoB;
        maiorConjunto = conjuntoB;
        menor = qtdElementosConjuntoA;
        menorConjunto = conjuntoA;
    }

    // Criar um vetor dinâmico para poder armazenar a diferença entre os dois conjutos.

    interseccao = (int *) malloc(menor * sizeof(int));
    for (i = 0; i < menor; i++) {
        if (jaExisteElemento(maiorConjunto, maior, menorConjunto[i])) {
            interseccao[qtdElementosConjuntoInterseccao++] = menorConjunto[i];
        }
    }

    if (qtdElementosConjuntoInterseccao < menor) {
        interseccao = (int *) realloc(interseccao, qtdElementosConjuntoInterseccao * sizeof(int));
    }

    // Imprimir na tela.

    printf("S = { ");
    for (i = 0; i < qtdElementosConjuntoInterseccao; i++) {
        if (i < qtdElementosConjuntoInterseccao - 1) printf("%i, ", interseccao[i]);
        else printf("%i", interseccao[i]);
    }
    printf(" }\n\n");
}

int jaExisteElemento(int *array, int tamanho, int elemento) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (array[i] == elemento) return 1;
    }
    return 0;
}

void uniao(int *conjuntoA, int qtdElementosConjuntoA, int *conjuntoB, int qtdElementosConjuntoB) {
    int i;
    int maior;
    int menor;
    int qtdElementosConjuntoUniao = 0;
    int *maiorConjunto;
    int *menorConjunto;
    int *uniao;

    // Achar o menor e maior o conjunto.

    if (qtdElementosConjuntoA >= qtdElementosConjuntoB) {
        maior = qtdElementosConjuntoA;
        maiorConjunto = conjuntoA;
        menor = qtdElementosConjuntoB;
        menorConjunto = conjuntoB;
    } else {
        maior = qtdElementosConjuntoB;
        maiorConjunto = conjuntoB;
        menor = qtdElementosConjuntoA;
        menorConjunto = conjuntoA;
    }

    // Criar um vetor dinâmico para poder armazenar a união entre os dois conjuntos.

    uniao = (int *) malloc((qtdElementosConjuntoA + qtdElementosConjuntoB) * sizeof(int));
    for (i = 0; i < maior; i++) {
        uniao[qtdElementosConjuntoUniao++] = maiorConjunto[i];
    }
    for (i = 0; i < menor; i++) {
        if (!jaExisteElemento(maiorConjunto, maior, menorConjunto[i])) {
            uniao[qtdElementosConjuntoUniao++] = menorConjunto[i];
        }
    }

    if (qtdElementosConjuntoUniao < maior + menor) {
        uniao = (int *) realloc(uniao, qtdElementosConjuntoUniao * sizeof(int));
    }

    // Imprimir na tela.

    printf("S = { ");
    for (i = 0; i < qtdElementosConjuntoUniao; i++) {
        if (i < qtdElementosConjuntoUniao - 1) printf("%i, ", uniao[i]);
        else printf("%i", uniao[i]);
    }
    printf(" }\n\n");
}
