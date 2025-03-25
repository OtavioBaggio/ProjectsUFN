/*        PRODUTO DE APRENDIZAGEM III       Aluno: Jos� Ot�vio Baggio
    Problema 1
Desenvolva um programa na linguagem C, que tenha duas matrizes A e B, com tamanho N x
N (N <= 10). Inicialize (gere) os elementos de cada uma das matrizes. Posteriormente, disponibilize
ao usu�rio um Menu de op��es para fazer as seguintes opera��es com matrizes:
a) Somar as matrizes A e B (C = A + B)
b) Encontrar o maior elemento da matriz A
c) Encontrar o menor elemento da matriz A
d) Multiplicar a matriz A por um n�mero lido k (D = k * A)
e) Multiplicar a matriz A por um vetor V (E = V * A)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
setlocale(LC_ALL, "portuguese");
    //Vari�veis Utilizadas:
    int MatrizA[4][4], MatrizB[4][4], MatrizC[4][4], MatrizD[4][4], MatrizE[4];
    int i, j, k;
    int vetor[4];
    int maior, menor;
    int PosMaior_i, PosMaior_j, PosMenor_i, PosMenor_j;
    int tam = 4;
    char escolha;

    printf("\t\tOl�, irei gerar 2 matrizes com n�meros inteiros aleat�rios...\n");
    printf("\t\tEm seguida, iremos manipul�los a partir de 5 op��es selecion�veis\n\n");

    // Inicializa o gerador de n�meros aleat�rios com o tempo atual
    srand(time(NULL));

    // Preenche a matriz A com n�meros aleat�rios entre 0 e 99
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            MatrizA[i][j] = rand() % 100; // Gera um n�mero aleat�rio entre 0 e 99
        }
    }

    // Exibe a matriz
    printf("Matriz A com n�meros aleat�rios:\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%2d\t", MatrizA[i][j]);
        }
        printf("\n");
    }

    // Preenche a matriz B com n�meros aleat�rios entre 0 e 99
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            MatrizB[i][j] = rand() % 100; // Gera um n�mero aleat�rio entre 0 e 99
        }
    }

    // Exibe a matriz
    printf("Matriz B com n�meros aleat�rios:\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%2d\t", MatrizB[i][j]);
        }
        printf("\n");
    }

    //Mostrando o menu de op��es
    do{
    	printf("\n\tMenu de op��es:\n");
    	printf("\tResponda a, b, c, d, e para as op��es OU 'f' para SAIR\n");
    	printf("a)Somar as matrizes A e B (C = A + B)\n");
    	printf("b)Encontrar o maior elemento da matriz A\n");
    	printf("c)Encontrar o menor elemento da matriz A\n");
    	printf("d)Multiplicar a matriz A por um n�mero lido k (D = k * A)\n");
    	printf("e)Multiplicar a matriz A por um vetor V (E = V * A)\n");
    	printf("f) Sair\n");
        printf("Escolha uma op��o: ");
    	scanf(" %c", &escolha);

    	//Verifica a escolha do usu�rio e executa
    	 switch (escolha) {
            case 'a':
                printf("\n\tVoc� escolheu a op��o a)\n");
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
                printf("\n\tVoc� escolheu a op��o b)\n");
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
                printf("O maior elemento da matriz A �: %d, na posi��o [%d][%d]\n", maior, PosMaior_i, PosMaior_j);
                break;
            case 'c':
                printf("\n\tVoc� escolheu a op��o c)\n");
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
                printf("O menor elemento da matriz A �: %d, na posi��o [%d][%d]\n", menor, PosMenor_i, PosMenor_j);
                break;
             case 'd':
                printf("\n\tVoc� escolheu a op��o d)\n");
                printf("Digite o valor de k: ");
                scanf("%d", &k);
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        MatrizD[i][j] = MatrizA[i][j] * k;
                    }
                }
                printf("Resultado da multiplica��o da matriz A por %d (Matriz D):\n", k);
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        printf("%2d\t", MatrizD[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 'e':
                printf("\n\tVoc� escolheu a op��o e)\n");
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
                printf("Resultado da multiplica��o do vetor V pela matriz A (V * A):\n");
                for (i = 0; i < 4; i++) {
                    printf("%d\n", MatrizE[i]);
                }
                break;
            case 'f':
                printf("\n\tSaindo...\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
                break;
        }
    }while (escolha != 'f');



return 0;
}
