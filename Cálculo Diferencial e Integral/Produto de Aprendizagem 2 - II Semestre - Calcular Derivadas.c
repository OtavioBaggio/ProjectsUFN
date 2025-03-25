/*     Produto de Aprendizagem II - C�lculo I   ||   Aluno: Jos� Ot�vio R. Baggio
    Programa para calcular a derivada de um polin�mio. O usu�rio fornece o grau do polin�mio
    e a seguir seus coeficientes.
*/

#include <stdio.h>
#include <locale.h>   //Utilizo essa biblioteca para acrescentar as acentua��es em portugu�s nos meus c�digos

//Estrutura para o polin�mio:
typedef struct{
    int grau;
    double coeficientes[5];  //Utilizei 'double' pois ele armazena mais bits, menos chance de erros, esse vetor suporta at� polin�mios de grau 4
} Polinomio;

//Gosto de usar essa fun��o para separar se��es mostradas ao usu�rio
void linha(){
    printf("===============================================================================================\n");
}

//Fun��o para ler os coeficientes do polin�mio:
void LerCoeficientes(Polinomio *p){             //A partir daqui, utilizei ponteiros em cada fun��o para economizar vari�veis
    linha();
    for (int i = p->grau; i >= 0; i--){
        printf("Informe o coeficiente de x^%d: ", i);
        scanf("%lf", &(p->coeficientes[i]));
    }
}

//Fun��o para calcular a derivada do polin�mio:
void calcularDerivada(Polinomio *p, double derivada[]){
    for (int i = 1; i <= p->grau; i++){
        derivada[i-1] = p->coeficientes[i] * i;    //Derivando multiplicando o coeficiente pelo grau
    }
}

//Fun��o para exibir a derivada:
void exibirDerivada(int grau, double derivada[]){
    if (grau == 0) return;

    linha();
    printf("\nA derivada do polin�mio �: ");
    for (int i = grau - 1; i >= 0; i--){
        printf("%.2lfx^%d ", derivada[i], i);
        if (i > 0 && derivada[i - 1] >= 0){
            printf("+ ");
        }
    }
    printf("\n");
}

int main(){
    setlocale(LC_ALL, "portuguese");

    Polinomio p;           //Chamando a struct
    int opcao;             //Vari�vel para escolher a op��o no comando switch
    double derivada[5];    //Vetor configurado para armazenar at� a derivada de um polin�mio de grau 4

    printf("\t\t\tCALCULADORA DE DERIVADAS\n");
    printf("\t\t\t\t\tPowered By: UFN Mathematical System\n");
    linha();

    //Exibir op��es de grau e solicitar escolha do usu�rio
    printf("Escolha o grau do polin�mio:\n");
    printf("1 - Grau 1\n");
    printf("2 - Grau 2\n");
    printf("3 - Grau 3\n");
    printf("4 - Grau 4\n");
    printf("Polin�mio de grau: ");
    scanf("%d", &opcao);

    //Utilizei o switch para definir o grau baseado na escolha do usu�rio:
    switch (opcao){
        case 1:
            p.grau = 1;
            break;
        case 2:
            p.grau = 2;
            break;
        case 3:
            p.grau = 3;
            break;
        case 4:
            p.grau = 4;
            break;
        default:
            printf("Op��o inv�lida.\n");
            return 1;
    }

    //CHAMANDO AS FUN��ES NA MAIN:
    // Ler os coeficientes do polin�mio com o grau escolhido:
    LerCoeficientes(&p);

    // Calcular a derivada do polin�mio:
    calcularDerivada(&p, derivada);

    // Exibir a derivada do polin�mio:
    exibirDerivada(p.grau, derivada);

    return 0;
}
