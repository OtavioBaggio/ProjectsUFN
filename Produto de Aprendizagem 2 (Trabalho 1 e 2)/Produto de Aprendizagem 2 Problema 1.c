/* PRODUTO DE APRENDIZAGEM 2;       Aluno: Jos� Ot�vio Baggio
    PROBLEMA I
A Federa��o Ga�cha de Futebol contratou um estudante de Ci�ncia da Computa��o para
fazer um levantamento estat�stico do resultado de v�rios Grenais. Escreva um algoritmo que leia
para cada Grenal, o n�mero de gols marcados pelo Gr�mio e o n�mero de gols marcados pelo
Internacional, imprimindo o nome do time vitorioso ou a palavra EMPATE. A solu��o deve ser
desenvolvida com o uso de vetores. Ap�s, o programa ele deve escrever a mensagem:
Novo Grenal (1. Sim 2. N�o)?
e solicitar uma resposta. Considere que no m�ximo ser�o inseridos 50 Grenais.
Se a resposta for 1, o algoritmo deve solicitar novamente o n�mero de gols marcados pelos
times em uma nova partida; se a resposta for 2 ou a quantidade m�xima de Grenais for alcan�ada,
deve ser exibido na tela:
� quantos Grenais fizeram parte da estat�stica;
� o n�mero de vit�rias do Gr�mio;
� o n�mero de vit�rias do Internacional;
� o n�mero de empates; e
� uma mensagem indicando qual o time que venceu o maior n�mero de Grenais (ou �N�o
houve vencedor�).
Antes de encerrar, o algoritmo deve encontrar e mostrar a(s) partida(s) em que houve maior
quantidade de gols.
*/
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    // Vari�veis
    int grenais = 0, gremio = 0, inter = 0, i = 0, NovoGrenal = 1, GolsGremio[50], GolsInter[50], Empates = 0;

    printf("\t\tResultado dos �ltimos 50 Grenais v�lidos pela Federe��o Ga�cha de Futebol\n\n");

    while (i < 50 && NovoGrenal == 1) {
        int GolsGremioMarcado, GolsInterMarcado;

        // Lendo os Gols marcados
        printf("Informe quantos gols o Gr�mio marcou: ");
        scanf("%d", &GolsGremioMarcado);
        printf("Informe quantos gols o Inter marcou: ");
        scanf("%d", &GolsInterMarcado);

        // Armazenando os resultados como vetores
        GolsGremio[grenais] = GolsGremioMarcado;
        GolsInter[grenais] = GolsInterMarcado;

        // Verifica se haver� vit�ria para algum time ou empate
        if (GolsGremioMarcado > GolsInterMarcado) {
            printf("VIT�RIA PARA O TRICOLOR GA�CHO, Gr�mio ganhou esta partida!\n\n");
            gremio++;
        } else if (GolsInterMarcado > GolsGremioMarcado) {
            printf("VIT�RIA PARA O TIME DO POVO, Inter ganhou esta partida!\n\n");
            inter++;
        } else {
            printf("Empate!!\n");
            Empates++;
        }
        grenais++;
        i++;

        // Programa pergunta se tem mais um Grenal para ler
        if (grenais < 50) {
            printf("Novo Grenal? (Digite 1 para SIM e 2 para N�O): ");
            scanf("%d", &NovoGrenal);
        }
    }

    // Exibindo estat�sticas dos Grenais
    printf("\nEstat�sticas dos Grenais:\n");
    printf("Total de Grenais: %d\n", grenais);
    printf("Vit�rias do Gr�mio: %d\n", gremio);
    printf("Vit�rias do Inter: %d\n", inter);
    printf("Empates: %d\n", Empates);

    // Mostra qual time teve mais vit�rias
    if (gremio > inter) {
        printf("O Gr�mio obteve mais vit�rias em Grenais\n");
    } else if (inter > gremio) {
        printf("O Inter obteve mais vit�rias em Grenais\n");
    } else {
        printf("Os dois times ficaram empatados no n�mero de partidas ganhas\n");
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
            printf("Grenal %d: Gr�mio %d x %d Internacional\n", j + 1, GolsGremio[j], GolsInter[j]);
        }
    }

    return 0;
}
