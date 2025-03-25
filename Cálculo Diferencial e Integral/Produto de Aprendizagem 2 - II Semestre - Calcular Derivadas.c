/*     Produto de Aprendizagem II - Cálculo I   ||   Aluno: José Otávio R. Baggio
    Programa para calcular a derivada de um polinômio. O usuário fornece o grau do polinômio
    e a seguir seus coeficientes.
*/

#include <stdio.h>
#include <locale.h>   //Utilizo essa biblioteca para acrescentar as acentuações em português nos meus códigos

//Estrutura para o polinômio:
typedef struct{
    int grau;
    double coeficientes[5];  //Utilizei 'double' pois ele armazena mais bits, menos chance de erros, esse vetor suporta até polinômios de grau 4
} Polinomio;

//Gosto de usar essa função para separar seções mostradas ao usuário
void linha(){
    printf("===============================================================================================\n");
}

//Função para ler os coeficientes do polinômio:
void LerCoeficientes(Polinomio *p){             //A partir daqui, utilizei ponteiros em cada função para economizar variáveis
    linha();
    for (int i = p->grau; i >= 0; i--){
        printf("Informe o coeficiente de x^%d: ", i);
        scanf("%lf", &(p->coeficientes[i]));
    }
}

//Função para calcular a derivada do polinômio:
void calcularDerivada(Polinomio *p, double derivada[]){
    for (int i = 1; i <= p->grau; i++){
        derivada[i-1] = p->coeficientes[i] * i;    //Derivando multiplicando o coeficiente pelo grau
    }
}

//Função para exibir a derivada:
void exibirDerivada(int grau, double derivada[]){
    if (grau == 0) return;

    linha();
    printf("\nA derivada do polinômio é: ");
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
    int opcao;             //Variável para escolher a opção no comando switch
    double derivada[5];    //Vetor configurado para armazenar até a derivada de um polinômio de grau 4

    printf("\t\t\tCALCULADORA DE DERIVADAS\n");
    printf("\t\t\t\t\tPowered By: UFN Mathematical System\n");
    linha();

    //Exibir opções de grau e solicitar escolha do usuário
    printf("Escolha o grau do polinômio:\n");
    printf("1 - Grau 1\n");
    printf("2 - Grau 2\n");
    printf("3 - Grau 3\n");
    printf("4 - Grau 4\n");
    printf("Polinômio de grau: ");
    scanf("%d", &opcao);

    //Utilizei o switch para definir o grau baseado na escolha do usuário:
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
            printf("Opção inválida.\n");
            return 1;
    }

    //CHAMANDO AS FUNÇÕES NA MAIN:
    // Ler os coeficientes do polinômio com o grau escolhido:
    LerCoeficientes(&p);

    // Calcular a derivada do polinômio:
    calcularDerivada(&p, derivada);

    // Exibir a derivada do polinômio:
    exibirDerivada(p.grau, derivada);

    return 0;
}
