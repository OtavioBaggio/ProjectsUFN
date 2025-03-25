/*        PRODUTO DE APRENDIZAGEM III       Aluno: José Otávio Baggio
    Problema 1
Desenvolva um programa na linguagem C, que tenha duas matrizes A e B, com tamanho N x
N (N <= 10). Inicialize (gere) os elementos de cada uma das matrizes. Posteriormente, disponibilize
ao usuário um Menu de opções para fazer as seguintes operações com matrizes:
a) Somar as matrizes A e B (C = A + B)
b) Encontrar o maior elemento da matriz A
c) Encontrar o menor elemento da matriz A
d) Multiplicar a matriz A por um número lido k (D = k * A)
e) Multiplicar a matriz A por um vetor V (E = V * A)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
setlocale(LC_ALL, "portuguese");
    //Variáveis Utilizadas:
    int MatrizA[4][4], MatrizB[4][4], MatrizC[4][4], MatrizD[4][4], MatrizE[4];
    int i, j, k;
    int vetor[4];
    int maior, menor;
    int PosMaior_i, PosMaior_j, PosMenor_i, PosMenor_j;
    int tam = 4;
    char escolha;

    printf("\t\tOlá, irei gerar 2 matrizes com números inteiros aleatórios...\n");
    printf("\t\tEm seguida, iremos manipulálos a partir de 5 opções selecionáveis\n\n");

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Preenche a matriz A com números aleatórios entre 0 e 99
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            MatrizA[i][j] = rand() % 100; // Gera um número aleatório entre 0 e 99
        }
    }

    // Exibe a matriz
    printf("Matriz A com números aleatórios:\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%2d\t", MatrizA[i][j]);
        }
        printf("\n");
    }

    // Preenche a matriz B com números aleatórios entre 0 e 99
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            MatrizB[i][j] = rand() % 100; // Gera um número aleatório entre 0 e 99
        }
    }

    // Exibe a matriz
    printf("Matriz B com números aleatórios:\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%2d\t", MatrizB[i][j]);
        }
        printf("\n");
    }

    //Mostrando o menu de opções
    do{
    	printf("\n\tMenu de opções:\n");
    	printf("\tResponda a, b, c, d, e para as opções OU 'f' para SAIR\n");
    	printf("a)Somar as matrizes A e B (C = A + B)\n");
    	printf("b)Encontrar o maior elemento da matriz A\n");
    	printf("c)Encontrar o menor elemento da matriz A\n");
    	printf("d)Multiplicar a matriz A por um número lido k (D = k * A)\n");
    	printf("e)Multiplicar a matriz A por um vetor V (E = V * A)\n");
    	printf("f) Sair\n");
        printf("Escolha uma opção: ");
    	scanf(" %c", &escolha);

    	//Verifica a escolha do usuário e executa
    	 switch (escolha) {
            case 'a':
                printf("\n\tVocê escolheu a opção a)\n");
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        MatrizC[i][j] = MatrizA[i][j] + MatrizB[i][j];
                    }
                }
                printf("\tResultado da soma das matrizes A e B (Matriz C):\n");
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        printf("%2d\t", MatrizC[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 'b':
                printf("\n\tVocê escolheu a opção b)\n");
                maior = MatrizA[0][0];
                PosMaior_i = 0;
                PosMaior_j = 0;
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        if (MatrizA[i][j] > maior) {
                            maior = MatrizA[i][j];
                            PosMaior_i = i;
                            PosMaior_j = j;
                        }
                    }
                }
                printf("O maior elemento da matriz A é: %d, na posição [%d][%d]\n", maior, PosMaior_i, PosMaior_j);
                break;
            case 'c':
                printf("\n\tVocê escolheu a opção c)\n");
                menor = MatrizA[0][0];
                PosMenor_i = 0;
                PosMenor_j = 0;
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        if (MatrizA[i][j] < menor) {
                            menor = MatrizA[i][j];
                            PosMenor_i = i;
                            PosMenor_j = j;
                        }
                    }
                }
                printf("O menor elemento da matriz A é: %d, na posição [%d][%d]\n", menor, PosMenor_i, PosMenor_j);
                break;
             case 'd':
                printf("\n\tVocê escolheu a opção d)\n");
                printf("Digite o valor de k: ");
                scanf("%d", &k);
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        MatrizD[i][j] = MatrizA[i][j] * k;
                    }
                }
                printf("Resultado da multiplicação da matriz A por %d (Matriz D):\n", k);
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        printf("%2d\t", MatrizD[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 'e':
                printf("\n\tVocê escolheu a opção e)\n");
                printf("Digite os valores do vetor V (tamanho %d):\n", tam);
                for (i = 0; i < 4; i++) {
                    printf("V[%d]: ", i);
                    scanf("%d", &vetor[i]);
                }
                for (i = 0; i < 4; i++) {
                    MatrizE[i] = 0;
                    for (j = 0; j < 4; j++) {
                        MatrizE[i] += vetor[j] * MatrizA[j][i];
                    }
                }
                printf("Resultado da multiplicação do vetor V pela matriz A (V * A):\n");
                for (i = 0; i < 4; i++) {
                    printf("%d\n", MatrizE[i]);
                }
                break;
            case 'f':
                printf("\n\tSaindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }while (escolha != 'f');



return 0;
}
