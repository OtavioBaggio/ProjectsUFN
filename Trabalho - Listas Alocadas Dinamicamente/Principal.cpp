/*              Aluno: Jos� Ot�vio R. BAGGIO

                Prof: Alexandre de Oliveira Zamberlan / GitHub: https://github.com/alexandrezamberlan

            TRABALHO SEMESTRAL - ESTRUTURA DE DADOS -  III SEMESTRE

    A partir de um programa em C ou C++ que possua 2 listas (lista1/listaA e lista2/listaB) de inteiros, totalmente aleat�rias (com n�meros entre 1 e 100).
    As listas podem ser de tamanhos distintos, mas que sejam maiores que 20 n�meros. Fa�a um m�todo que receba as duas listas e exiba os n�meros que est�o presentes em ambas.

    -> Fa�a um m�todo que exclua todos os n�meros pares da lista1 ou listaA

    -> Fa�a um m�todo que una a lista1 ou listaA na lista2 ou listaB. Ou seja, todos os elementos da primeira lista devem vir primeiro dos elementos da segunda lista

    -> Fa�a um m�todo que receba o resultado da uni�o da lista1 com a lista2 e aplique um m�todo de ordena��o

    -> Fa�a um m�todo que delete todos os elementos da lista criada da uni�o entre lista1 e lista2.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lista.h"
using namespace std;

int main(){

    /*
        Mesmo n�o constando na ordem do trabalho, utilizei recurs�o na implementa��o do meu c�digo
        para treinar o conte�do feito em aula;
    */

    srand(time(NULL));

    //Listas:
    Celula *listaA = NULL;
    Celula *listaB = NULL;

    //la�o que preenche a lista com n�meros aleat�rios:
    for(int i = 0; i < 50; i++){
        listaA = inserir(rand() % 100 + 1, listaA);
        listaB = inserir(rand() % 100 + 1, listaB);
    }

    //Exibindo as listas:
    cout << "-- Lista A: --\n";
    exibir(listaA);

    cout << "\n-- Lista B: --\n\n";
    exibir(listaB);

    //Chamando a fun��o que exibi os elementos comuns entre elas:
    exibirComuns(listaA, listaB);

    //Removendo pares do A e do B:
    listaA = removerPares(listaA);
    cout << "\n-- Lista A apos remocao dos numeros pares: --\n";
    exibir(listaA);

    /*  CASO SEJA NECESS�RIO REMOVER DO B:
    listaB = removerPares(listaB);
    cout << "\nLista B ap�s remo��o dos n�meros pares:\n";
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

    //Liberando a mem�ria:
    listaUnida = liberar(listaUnida);
    cout << "\n\n-- Lista LIBERADA! --\n";
    cout << "  Elementos totais:  " << contar(listaUnida) << endl;




    return 0;
}
