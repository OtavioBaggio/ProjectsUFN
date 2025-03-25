/*      PRODUTO DE APRENDIZAGEM III       Aluno: José Otávio Baggio

    Problema 1
A Cifra de César é uma das técnicas de criptografia de dados mais simples. É conhecida
também como Cógido de César ou Troca de César. É um tipo de cifra por substituição, em que cada
caracter é substituido por outro caracter.
Essa Cifra consiste em receber uma mensagem (string) e modificá-la de forma que cada
caracter é substituído por outro caracter que se apresenta no alfabeto abaixo dela um número fixo de
vezes. Esse número fixo de vezes, é chamado de número de troca ou deslocamento à direita ou
chave de criptografia.
Por exemplo, se a mensagem recebida for ABACO e a número de troca for igual a 3, a
mensagem será codificada para: DEDFR, ou seja, o A foi substituído por D, e os demais caracteres
foram substituídos pelo caracter 3 posições à sua frente.
Desenvolva um programa na linguagem C para ler uma mensagem (string) de no máximo
100 caracteres e ler o número de troca. Posteriormente, o programa deve codificar a mensagem
conforme a Cifra de César e exibi-la ao usuário.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
setlocale(LC_ALL, "portuguese");
    //Variáveis Utilizadas:
    int NumDeslocamento;
    int i;
    char mensagem[101];
    char ch;

    // Lendo a mensagem
    printf("\t\tOlá, bem-vindo ao programa baseado no código de Cezar, aonde, de acordo com a Cifra de Cézar\n");
    printf("\tconsiste em receber uma mensagem e modificá-la de acordo com um número informado\n");
    printf("\nDigite uma mensagem (até 100 caracteres): ");
    fgets(mensagem, sizeof(mensagem), stdin);

    // Remover o caractere de nova linha, se houver
    mensagem[strcspn(mensagem, "\n")] = 0;

    // Ler o número de troca
    printf("\nDigite o número de troca: ");
    scanf("%d", &NumDeslocamento);

    // Aplicando a cifra de César
    for(i = 0; mensagem[i] != '\0'; ++i) {
        ch = mensagem[i];
        // Codificar letras maiúsculas
        if(ch >= 'A' && ch <= 'Z') {
            ch = ch + NumDeslocamento;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            mensagem[i] = ch;
        }
        // Codificar letras minúsculas
        else if(ch >= 'a' && ch <= 'z') {
            ch = ch + NumDeslocamento;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            mensagem[i] = ch;
        }
    }

    // Exibir a mensagem codificada
    printf("\nMensagem codificada: %s\n", mensagem);



    return 0;
}
