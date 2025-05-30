//Coment�rio importante na linha 76;

#include <iostream>
#include <cstdlib>
#include <ctime>;
using namespace std;

//Estrutura criada/necess�ria, para percorrer/manipular a lista:
typedef struct no{
    int dado;
    struct no *prox;
} Celula;


    //M�TODOS UTILIZADOS:

Celula *inserir(int dado, Celula *lista){
    if(lista && dado >= lista->dado){
        if(dado != lista->dado){
            //avancar na lista
            lista->prox = inserir(dado, lista->prox);
        }
        return lista;
    }else{  //cheguei no final da lista
        Celula *novo = (Celula*)malloc(sizeof(Celula));
        novo->dado = dado;
        novo->prox = lista;
        return novo;
    }
}


void exibir(Celula *lista) {
    if (lista) {
        cout << lista->dado << "\t";
        exibir(lista->prox);
    }
}

int contar(Celula *lista) {
    if (lista) {
        return 1 + contar(lista->prox);
    }
    return 0;
}

Celula *localizar(int numero, Celula *lista) {
    if (lista) {
        if (numero == lista->dado) {
            return lista;
        }
        return localizar(numero, lista->prox);
    }
    return NULL;
}

void exibirComuns(Celula *lista1, Celula *lista2) {
    cout << "\n\n  Elementos comuns entre as duas listas: ";
    for (Celula *p = lista1; p != NULL; p = p->prox) {
        if (localizar(p->dado, lista2)) cout << p->dado << " " << endl;
    }
}

Celula *removerPares(Celula *lista) {
    if (!lista) return NULL;
    if (lista->dado % 2 == 0) {
        Celula *prox = lista->prox;
        free(lista);
        return removerPares(prox);
    }
    lista->prox = removerPares(lista->prox);
    return lista;
}

/*
    O Professor Zamberlan utilizou esses m�todos para remo��o, j� eu decidi utilizar um m�todo mais parecido (acima) do que foi
    treinado nas outras aulas, mas esses tamb�m funcionariam de forma mais perform�tica:

Celula *remover(int dado, Celula *lista) {
    Celula *p, *pR; // p � o ponteiro que percorre a lista e pR � o ponteiro para o n� anterior
    for (p = lista, pR = NULL; p != NULL; pR = p, p = p->prox) {  // Percorre a lista
        if (p->dado == dado) {  // Encontrou o dado a ser removido
            if (pR == NULL) { // Caso especial: o dado est� no primeiro n�
                lista = p->prox;  // A cabe�a da lista � atualizada para o pr�ximo n�
            } else {
                pR->prox = p->prox;  // O n� anterior aponta para o n� seguinte, removendo o n� atual
            }
            free(p);  // Libera a mem�ria do n� removido
            return lista;  // Retorna a lista (pode ser a mesma lista ou a cabe�a atualizada)
        }
    }
    return lista; // Retorna a lista inalterada caso o dado n�o tenha sido encontrado
}

// Fun��o para remover todos os n�meros pares da lista (m�todo iterativo)
Celula *removerPares(Celula *lista) {
    Celula *p;
    for (p = lista; p != NULL; p = p->prox) {  // Percorre a lista
        if (p->dado % 2 == 0) {  // Se o dado for par
            lista = remover(p->dado, lista);  // Chama a fun��o remover para excluir o n�mero par
        }
    }
    return lista;  // Retorna a lista com os n�meros pares removidos
}
*/

Celula *unirListas(Celula *a, Celula *b) {
    if (!a) return b;
    a->prox = unirListas(a->prox, b);
    return a;
}

Celula *ordenar(Celula *lista) {
    if (!lista || !lista->prox) return lista;
    for (Celula *i = lista; i != NULL; i = i->prox) {
        for (Celula *j = i->prox; j != NULL; j = j->prox) {
            if (i->dado > j->dado) {
                int tmp = i->dado;
                i->dado = j->dado;
                j->dado = tmp;
            }
        }
    }
    return lista;
}

//Libera a mem�ria dos n�s da lista:
Celula *liberar(Celula *lista) {
    while (lista) {
        Celula *tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
    return NULL;
}
