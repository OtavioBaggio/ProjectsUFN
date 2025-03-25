/* PRODUTO DE APRENDIZAGEM II - II Semestre
    Problema I: Interceptando Informações
    Alunos: José Otávio Baggio; Joseph Stucker Calgaro; */

    //Ambos os dois alunos participaram da construção de todas as funções nesse código.
#include <stdio.h>
#include <locale.h>

//Função para Verificar a mensagem espiã:
void verificarMensagem(int *bits[]){
    char result = 'S';
    int i;
    for(i = 0; i < 8; i++){   //Esse laço percorre todos os 8 bits verificando os bits verdadeiros e falsos
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

    //Chamando a função:
    verificarMensagem(bits);

return 0;
}
