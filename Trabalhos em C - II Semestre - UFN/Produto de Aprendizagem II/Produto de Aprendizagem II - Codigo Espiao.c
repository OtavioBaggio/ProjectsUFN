/* PRODUTO DE APRENDIZAGEM II - II Semestre
    Problema I: Interceptando Informa��es
    Alunos: Jos� Ot�vio Baggio; Joseph Stucker Calgaro; */

    //Ambos os dois alunos participaram da constru��o de todas as fun��es nesse c�digo.
#include <stdio.h>
#include <locale.h>

//Fun��o para Verificar a mensagem espi�:
void verificarMensagem(int *bits[]){
    char result = 'S';
    int i;
    for(i = 0; i < 8; i++){   //Esse la�o percorre todos os 8 bits verificando os bits verdadeiros e falsos
        if(bits[i] == 9){
            result = 'F';
            break;
        }
    }
    if(result == 'F'){
        printf("\n");
        printf("Retorno: F");
    }else{
            printf("\n");
            printf("Retorno: S");
    }
}

int main(){
setlocale(LC_ALL, "portuguese");
    int bits[8];

    //Lendo os bits:
    printf("Informe a passagem dos bits(0, 1 ou 9):\n");
    for(int i = 0; i < 8; i++){
        scanf("%d", &bits[i]);
    }

    //Chamando a fun��o:
    verificarMensagem(bits);

return 0;
}
