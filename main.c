#include <stdio.h>

int main() {
    int continuarRodando = 1;
    int qtdElementosConjuntoA; 
    int qtdElementosConjuntoB;
    int opcaoEscolhida;

    printf("Digite a quantidade de elementos do conjunto A: ");
    scanf("%i", &qtdElementosConjuntoA);
    printf("Digite a quantidade de elementos do conjunto B: ");
    scanf("%i", &qtdElementosConjuntoB);

    int conjuntoA[qtdElementosConjuntoA];
    int conjuntoB[qtdElementosConjuntoB];

    printf("--------------------------------------------------------------------------------\n");
    printf("Definindo elementos do Conjunto A\n\n");
    for (int i = 0; i < qtdElementosConjuntoA; i++) {
        printf("Digite o valor do #%i elemento: ", i + 1);
        scanf("%i", &conjuntoA[i]);
    }

    printf("--------------------------------------------------------------------------------\n");
    printf("Definindo elementos do Conjunto B\n\n");
    for (int i = 0; i < qtdElementosConjuntoB; i++) {
        printf("Digite o valor do #%i elemento: ", i + 1);
        scanf("%i", &conjuntoB[i]);
    }

    while (continuarRodando) {
        printf("--------------------------------------------------------------------------------\n");

        printf("A = { ");
        for (int i = 0; i < qtdElementosConjuntoA; i++) {
            if (i == qtdElementosConjuntoA - 1)
                printf("%i", conjuntoA[i]);
            else
                printf("%i, ", conjuntoA[i]);
        }
        printf(" }\n");

        printf("B = { ");
        for (int i = 0; i < qtdElementosConjuntoB; i++) {
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

        switch (opcaoEscolhida) {
            case 1:
                break;
            case 2:
                break;
            case 3:
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
