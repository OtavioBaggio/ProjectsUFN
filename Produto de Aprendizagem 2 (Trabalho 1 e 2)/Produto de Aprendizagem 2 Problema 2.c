/* PRODUTO DE APRENDIZAGEM 2;       Aluno: José Otávio Baggio
    PROBLEMA II
Ler um vetor de 10 números chamado amostragem. Cada número desse vetor corresponde à
quantidade de amostras de um determinado item. O algoritmo deverá colocar em um segundo vetor,
chamado percentual, a porcentagem que a quantidade de cada amostra contida em amostragem,
corresponde em relação ao total.
O algoritmo em C deve:
• mostrar o valor contido em cada amostrangem e o percentual correspondente;
• calcular a média de valores das amostras;
• encontrar a maior quantidade de amostra e seu respectivo percentual;
• mostrar quais são as amostras que possuem quantidade acima da média.
*/
#include <stdio.h>
#include <locale.h>

int main(){
setlocale(LC_ALL, "portuguese");

    //Variáveis
    int amostragem[10];
    float percentual[10];
    int total = 0;
    float media = 0.0;
    int MaiorValor = 0;
    float MaiorPercentual = 0.0;
    int i;

    // Lendo o vetor amostragem
    printf("Digite 10 números para o vetor amostragem:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &amostragem[i]);
        total += amostragem[i];
    }

    // Calculando os percentuais
    for (i = 0; i < 10; i++) {
        percentual[i] = ((float)amostragem[i] / total) * 100;
    }

    // Encontrando o maior valor e seu percentual
    for (i = 0; i < 10; i++) {
        if (amostragem[i] > MaiorValor) {
            MaiorValor = amostragem[i];
            MaiorPercentual = percentual[i];
        }
    }

    // Calculando a média
    media = (float)total / 10;

    // Mostrando os valores e percentuais
    printf("\nValores e percentuais:\n");
    for (i = 0; i < 10; i++) {
        printf("Valor: %d, Percentual: %.2f%%\n", amostragem[i], percentual[i]);
    }

    // Mostrando a média
    printf("\nMedia das amostras: %.2f\n", media);

    // Mostrando o maior valor e seu percentual
    printf("Maior valor: %d, Percentual correspondente: %.2f%%\n", MaiorValor, MaiorPercentual);

    // Mostrando valores acima da média
    printf("\nValores acima da média:\n");
    for (i = 0; i < 10; i++) {
        if (amostragem[i] > media) {
            printf("Valor: %d, Percentual: %.2f%%\n", amostragem[i], percentual[i]);
        }
    }

    return 0;
}
