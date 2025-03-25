/*      PRODUTO DE APRENDIZAGEM III       Aluno: Jos� Ot�vio Baggio

    Problema 1
A Cifra de C�sar � uma das t�cnicas de criptografia de dados mais simples. � conhecida
tamb�m como C�gido de C�sar ou Troca de C�sar. � um tipo de cifra por substitui��o, em que cada
caracter � substituido por outro caracter.
Essa Cifra consiste em receber uma mensagem (string) e modific�-la de forma que cada
caracter � substitu�do por outro caracter que se apresenta no alfabeto abaixo dela um n�mero fixo de
vezes. Esse n�mero fixo de vezes, � chamado de n�mero de troca ou deslocamento � direita ou
chave de criptografia.
Por exemplo, se a mensagem recebida for ABACO e a n�mero de troca for igual a 3, a
mensagem ser� codificada para: DEDFR, ou seja, o A foi substitu�do por D, e os demais caracteres
foram substitu�dos pelo caracter 3 posi��es � sua frente.
Desenvolva um programa na linguagem C para ler uma mensagem (string) de no m�ximo
100 caracteres e ler o n�mero de troca. Posteriormente, o programa deve codificar a mensagem
conforme a Cifra de C�sar e exibi-la ao usu�rio.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
setlocale(LC_ALL, "portuguese");
    //Vari�veis Utilizadas:
    int NumDeslocamento;
    int i;
    char mensagem[101];
    char ch;

    // Lendo a mensagem
    printf("\t\tOl�, bem-vindo ao programa baseado no c�digo de Cezar, aonde, de acordo com a Cifra de C�zar\n");
    printf("\tconsiste em receber uma mensagem e modific�-la de acordo com um n�mero informado\n");
    printf("\nDigite uma mensagem (at� 100 caracteres): ");
    fgets(mensagem, sizeof(mensagem), stdin);

    // Remover o caractere de nova linha, se houver
    mensagem[strcspn(mensagem, "\n")] = 0;

    // Ler o n�mero de troca
    printf("\nDigite o n�mero de troca: ");
    scanf("%d", &NumDeslocamento);

    // Aplicando a cifra de C�sar
    for(i = 0; mensagem[i] != '\0'; ++i) {
        ch = mensagem[i];
        // Codificar letras mai�sculas
        if(ch >= 'A' && ch <= 'Z') {
            ch = ch + NumDeslocamento;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            mensagem[i] = ch;
        }
        // Codificar letras min�sculas
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
