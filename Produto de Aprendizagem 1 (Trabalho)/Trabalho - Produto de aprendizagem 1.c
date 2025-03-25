/* Trabalho - Produto de Aprendizagem 1
        Aluno: José Otávio Baggio;
*/
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
setlocale(LC_ALL, "Portuguese");
    float Vcompra, entrada, prestacao;
    char Fpagamento;

    // Entrada de dados
    printf("Digite o valor total da compra: R$ ");
    scanf("%f", &Vcompra);
    printf("Digite a forma de pagamento (V para à vista ou P para parcelado): ");
    scanf(" %c", &Fpagamento);

    // Verificação da forma de pagamento (utilizei a função ceil para arrendondar para cima possíveis valores fracionados)
    if (Fpagamento == 'P' || Fpagamento == 'p') {
        // Pagamento parcelado
        entrada = Vcompra / 3.0;
        entrada = ceil(entrada * 100) / 100;
        prestacao = entrada;
        printf("Valor da entrada: R$ %.2f\n", entrada);
        printf("Valor das duas prestações: R$ %.2f\n", prestacao);
    } else if (Fpagamento == 'V' || Fpagamento == 'v') {
        // Pagamento à vista
        float desconto = 0.0;
        if (Vcompra <= 300.0) {
            desconto = 0.05;
        } else if (Vcompra <= 500.0) {
            desconto = 0.07;
        } else if (Vcompra <= 800.0) {
            desconto = 0.10;
        } else if (Vcompra <= 1000.0) {
            desconto = 0.12;
        } else {
            desconto = 0.15;
        }

        float Vdesconto = Vcompra * desconto;
        float Vfinal = Vcompra - Vdesconto;

        printf("Valor do desconto: %.2f%% (R$ %.2f)\n", desconto * 100, Vdesconto);
        printf("Valor a pagar: R$ %.2f\n", Vfinal);

        // Cálculo do troco
        float Vpago;
        printf("Se necessário troco, informar a seguir:\n");
        printf("Digite o valor pago em dinheiro: R$ ");
        scanf("%f", &Vpago);

        float troco = Vpago - Vfinal;
        printf("Troco: R$ %.2f\n", troco);

        // Cálculo das notas do troco
        int notas[] = {200, 100, 50, 20, 10, 5, 2};
        int quantidade_notas[7] = {0};

        printf("Notas do troco:\n");
        for (int i = 0; i < 7; i++) {
            while (troco >= notas[i]) {
                quantidade_notas[i]++;
                troco -= notas[i];
            }
            if (quantidade_notas[i] > 0) {
                printf("%d nota(s) de R$ %d\n", quantidade_notas[i], notas[i]);
            }
        }

        // Cálculo das moedas do troco
        float moedas[] = {1.0, 0.5, 0.25, 0.1, 0.05, 0.01};
        int quantidadeDeMoedas[6] = {0};

        printf("Moedas do troco:\n");
        for (int i = 0; i < 6; i++) {
            while (troco >= moedas[i]) {
                quantidadeDeMoedas[i]++;
                troco -= moedas[i];
            }
            if (quantidadeDeMoedas[i] > 0) {
                printf("%d moeda(s) de R$ %.2f\n", quantidadeDeMoedas[i], moedas[i]);
            }
        }
    } else {
        printf("Opção de pagamento inválida.\n");
    }


    system("pause");
    return 0;
}
