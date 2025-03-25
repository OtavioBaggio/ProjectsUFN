/* PRODUTO DE APRENDIZAGEM II - II Semestre
    Problema II: Manipulação de Matrizes
    Alunos: José Otávio Baggio; Joseph Stucker Calgaro; */

    //Ambos os dois alunos participaram da construção de todas as funções nesse código.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void opcaoA(int *matriz, int l, int c){
    int i, j;
    int simetrica = 1, diagonal = 1, triangularSuperior = 1, triangularInferior = 1;

    if(l != c){
        printf("A matriz não é quadrada e, portanto, não pode ser simetrica, diagonal, triangular superior nem triangular inferior\n");
    }

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            // valor = matriz[i][j]
            int valor = matriz[i * l + c];
            //verifica se é uma matriz simétrica (elementos em matriz[i][j] devem ser iguais a elementos em matriz[j][i])
            if(valor !=  matriz[j * l + c]){
                simetrica = 0;
            }
            // Verifica se é uma matriz diagonal (elementos fora da diagonal principal devem ser zero)
            if(i != j && valor != 0){
                diagonal = 0;
            }
            // Verifica se é uma matriz triangular superior (elementos abaixo da diagonal devem ser zero)
            if(i > j && valor != 0){
                triangularSuperior = 0;
            }
           // Verifica se é uma matriz triangular inferior (elementos acima da diagonal devem ser zero)
            if(i < j && valor != 0){
                triangularInferior = 0;
            }
        }
    }
    // se simetrica = 1 a matriz é simetrica
    if (simetrica) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }

    if (diagonal) {
        printf("A matriz é diagonal.\n");
    } else {
        printf("A matriz não é diagonal.\n");
    }

    if (triangularSuperior) {
        printf("A matriz é triangular superior.\n");
    } else {
        printf("A matriz não é triangular superior.\n");
    }

    if (triangularInferior) {
        printf("A matriz é triangular inferior.\n");
    } else {
        printf("A matriz não é triangular inferior.\n");
    }
}

void opcaoB(int *matriz, int l, int c){
    int i, j, somatorioPrimeiraCol = 0, num, somaDiagPrinc = 0, max = 0;

    //soma os valores da primeira coluna
    for(i = 0; i < l; i++){
        somatorioPrimeiraCol = somatorioPrimeiraCol + matriz[i * l + c];
    }
    printf("O somatório da primeira coluna é: %d\n", somatorioPrimeiraCol);

    //multiplica os valores da primeira linha pelo numero informado
    printf("Informe um numero: ");
    scanf("%d", &num);
    for(j = 0; j < l; j++){
    printf("%d ", matriz[j] * num);
    }
    printf("\n");

    //verifica se a matriz é quadrada
    if(l == c){
        for(i = 0; i < l; i++){
            somaDiagPrinc = somaDiagPrinc + matriz[i * c + i]; //  matriz[i][i]
        }
    }else{
        printf("Matriz não é quadrada portanto não possui diagonal principal\n");
    }

    //procura o maior valor da matriz
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(matriz[i * c + j] > max){
                max = matriz[i * c + j];
            }
        }
    }
    printf("O maior valor da matriz = %d\n", max);
    printf("Posicao do maior valor: \n");

    //procura endereços onde o maior valor da matriz aparece
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(matriz[i * c + j] == max){
                printf("Linha: %d Coluna: %d\n", i, j);
            }
        }
    }
}


int main(){
    setlocale(LC_ALL, "portuguese");

    int i, j, l, c, *matriz;
    char opcao;

    //Informa dimensão da matriz
    printf("Informe a quantidade de linhas da matriz: ");
    scanf("%d", &l);
    printf("Informe a quantidade de colunas da matriz: ");
    scanf("%d", &c);

    matriz = (int *) malloc(l*c*sizeof(int)); //multiplica linha * coluna para criar um array unidimencional com todos os elementos matriz [int, int, int, ...]

    //Verifica se houve sucesso na alocação
    if(!matriz){
    printf("Erro ao alocar memoria\n");
    exit(0);
}

    //Percorre a matriz para designação de valores a cada elemento
    printf("Informe os elementos da matriz\n");
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i * c + j]);
        }
}

    //Inicia um loop infinito
    while(1){
    printf("A - Classe de matriz\n");
    printf("B - Calculos sobre a matriz\n");
    printf("C - Sair\n");
    scanf("%c", &opcao);
    if(opcao == 'A' || opcao == 'a'){
        opcaoA(matriz, l, c);
    }
    if(opcao == 'B' || opcao == 'b'){
        opcaoB(matriz, l, c);
    }
    if(opcao == 'C' || opcao == 'c'){
        break; //Quebra o ciclo permitindo a finalização do codigo
    }
}
    return 0;
}
