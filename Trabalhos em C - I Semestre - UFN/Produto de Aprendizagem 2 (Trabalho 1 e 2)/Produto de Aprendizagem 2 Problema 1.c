/* PRODUTO DE APRENDIZAGEM 2;       Aluno: José Otávio Baggio
    PROBLEMA I
A Federação Gaúcha de Futebol contratou um estudante de Ciência da Computação para
fazer um levantamento estatístico do resultado de vários Grenais. Escreva um algoritmo que leia
para cada Grenal, o número de gols marcados pelo Grêmio e o número de gols marcados pelo
Internacional, imprimindo o nome do time vitorioso ou a palavra EMPATE. A solução deve ser
desenvolvida com o uso de vetores. Após, o programa ele deve escrever a mensagem:
Novo Grenal (1. Sim 2. Não)?
e solicitar uma resposta. Considere que no máximo serão inseridos 50 Grenais.
Se a resposta for 1, o algoritmo deve solicitar novamente o número de gols marcados pelos
times em uma nova partida; se a resposta for 2 ou a quantidade máxima de Grenais for alcançada,
deve ser exibido na tela:
• quantos Grenais fizeram parte da estatística;
• o número de vitórias do Grêmio;
• o número de vitórias do Internacional;
• o número de empates; e
• uma mensagem indicando qual o time que venceu o maior número de Grenais (ou “Não
houve vencedor”).
Antes de encerrar, o algoritmo deve encontrar e mostrar a(s) partida(s) em que houve maior
quantidade de gols.
*/
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    // Variáveis
    int grenais = 0, gremio = 0, inter = 0, i = 0, NovoGrenal = 1, GolsGremio[50], GolsInter[50], Empates = 0;

    printf("\t\tResultado dos últimos 50 Grenais válidos pela Federeção Gaúcha de Futebol\n\n");

    while (i < 50 && NovoGrenal == 1) {
        int GolsGremioMarcado, GolsInterMarcado;

        // Lendo os Gols marcados
        printf("Informe quantos gols o Grêmio marcou: ");
        scanf("%d", &GolsGremioMarcado);
        printf("Informe quantos gols o Inter marcou: ");
        scanf("%d", &GolsInterMarcado);

        // Armazenando os resultados como vetores
        GolsGremio[grenais] = GolsGremioMarcado;
        GolsInter[grenais] = GolsInterMarcado;

        // Verifica se haverá vitória para algum time ou empate
        if (GolsGremioMarcado > GolsInterMarcado) {
            printf("VITÓRIA PARA O TRICOLOR GAÚCHO, Grêmio ganhou esta partida!\n\n");
            gremio++;
        } else if (GolsInterMarcado > GolsGremioMarcado) {
            printf("VITÓRIA PARA O TIME DO POVO, Inter ganhou esta partida!\n\n");
            inter++;
        } else {
            printf("Empate!!\n");
            Empates++;
        }
        grenais++;
        i++;

        // Programa pergunta se tem mais um Grenal para ler
        if (grenais < 50) {
            printf("Novo Grenal? (Digite 1 para SIM e 2 para NÃO): ");
            scanf("%d", &NovoGrenal);
        }
    }

    // Exibindo estatísticas dos Grenais
    printf("\nEstatísticas dos Grenais:\n");
    printf("Total de Grenais: %d\n", grenais);
    printf("Vitórias do Grêmio: %d\n", gremio);
    printf("Vitórias do Inter: %d\n", inter);
    printf("Empates: %d\n", Empates);

    // Mostra qual time teve mais vitórias
    if (gremio > inter) {
        printf("O Grêmio obteve mais vitórias em Grenais\n");
    } else if (inter > gremio) {
        printf("O Inter obteve mais vitórias em Grenais\n");
    } else {
        printf("Os dois times ficaram empatados no número de partidas ganhas\n");
    }

    // Encontrar e mostrar a(s) partida(s) com maior quantidade de gols
    int GolsM = 0;
    printf("\nPartida(s) com maior quantidade de gols:\n");
    for (int j = 0; j < grenais; j++) {
        if (GolsGremio[j] + GolsInter[j] > GolsM) {
            GolsM = GolsGremio[j] + GolsInter[j];
        }
    }
    for (int j = 0; j < grenais; j++) {
        if (GolsGremio[j] + GolsInter[j] == GolsM) {
            printf("Grenal %d: Grêmio %d x %d Internacional\n", j + 1, GolsGremio[j], GolsInter[j]);
        }
    }

    return 0;
}
