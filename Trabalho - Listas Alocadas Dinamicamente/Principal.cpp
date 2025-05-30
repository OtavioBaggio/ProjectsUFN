/*              Aluno: José Otávio R. BAGGIO

                Prof: Alexandre de Oliveira Zamberlan / GitHub: https://github.com/alexandrezamberlan

            TRABALHO SEMESTRAL - ESTRUTURA DE DADOS -  III SEMESTRE

    A partir de um programa em C ou C++ que possua 2 listas (lista1/listaA e lista2/listaB) de inteiros, totalmente aleatórias (com números entre 1 e 100).
    As listas podem ser de tamanhos distintos, mas que sejam maiores que 20 números. Faça um método que receba as duas listas e exiba os números que estão presentes em ambas.

    -> Faça um método que exclua todos os números pares da lista1 ou listaA

    -> Faça um método que una a lista1 ou listaA na lista2 ou listaB. Ou seja, todos os elementos da primeira lista devem vir primeiro dos elementos da segunda lista

    -> Faça um método que receba o resultado da união da lista1 com a lista2 e aplique um método de ordenação

    -> Faça um método que delete todos os elementos da lista criada da união entre lista1 e lista2.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lista.h"
using namespace std;

int main(){

    /*
        Mesmo não constando na ordem do trabalho, utilizei recursão na implementação do meu código
        para treinar o conteúdo feito em aula;
    */

    srand(time(NULL));

    //Listas:
    Celula *listaA = NULL;
    Celula *listaB = NULL;

    //laço que preenche a lista com números aleatórios:
    for(int i = 0; i < 50; i++){
        listaA = inserir(rand() % 100 + 1, listaA);
        listaB = inserir(rand() % 100 + 1, listaB);
    }

    //Exibindo as listas:
    cout << "-- Lista A: --\n";
    exibir(listaA);

    cout << "\n-- Lista B: --\n\n";
    exibir(listaB);

    //Chamando a função que exibi os elementos comuns entre elas:
    exibirComuns(listaA, listaB);

    //Removendo pares do A e do B:
    listaA = removerPares(listaA);
    cout << "\n-- Lista A apos remocao dos numeros pares: --\n";
    exibir(listaA);

    /*  CASO SEJA NECESSÁRIO REMOVER DO B:
    listaB = removerPares(listaB);
    cout << "\nLista B após remoção dos números pares:\n";
    exibir(listaB);
    */

    //Unindo as duas listas:
    Celula *listaUnida = unirListas(listaA, listaB);
    cout << "\n\n-- Uniao das duas listas: --\n";
    exibir(listaUnida);

    //Mostrando a nova lista unida ordanamente:
    listaUnida = ordenar(listaUnida);
    cout <<"\n\n-- Nova lista ordenada: --\n";
    exibir(listaUnida);

    //Liberando a memória:
    listaUnida = liberar(listaUnida);
    cout << "\n\n-- Lista LIBERADA! --\n";
    cout << "  Elementos totais:  " << contar(listaUnida) << endl;




    return 0;
}
