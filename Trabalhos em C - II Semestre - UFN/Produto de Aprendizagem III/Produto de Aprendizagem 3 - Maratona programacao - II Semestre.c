/*      Produto de Aprendizagem 3 - II Semestre - Cenário / Problema 2
            Alunos: José Otávio R. Baggio; Joseph Strucker Calgaro;

    Um sistema de gerenciamento de Maratona de Programação armazena os seguintes dados de cada
equipe: nome da equipe, idade de cada um dos três competidores que compõem a equipe e número de
acertos (quantidade de questões) durante a competição, pela equipe. No máximo, podem estar inscritas
na Maratona 50 equipes.
O programa deve mostrar um menu ao usuário, um Menu Inicial, com as seguintes opções:
    1. Criar arquivo
    2. Ler equipes cadastradas em um arquivo
Posteriormente, o programa deve mostrar ao usuário o seguinte Menu de Opções:
    1. Cadastrar uma equipe
    2. Listar todas as equipes inscritas
    3. Mostrar a maior quantidade de acertos e os dados das equipes que obtiveram este resultado durante a Maratona.
    4. Calcular e mostrar a média de idade dos competidores de cada equipe.
    5. Consultar as equipes cujo nome inicia por uma letra digitada pelo usuário.
    6. Finalizar o programa.
*/

    //Os dois alunos participaram do desenvolvimento de ambas as funções do código;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define TamEquipes 50   //Número máximo de equipes
#define TamNome 50      //Tamanho máximo do nome da equipe

//Estrutura com os dados das equipes
typedef struct{
    char nome[TamNome];     //Nome da equipe
    int idade[3];           //Idade dos três competidores
    int acertos;            //Número de acertos
}Equipe;

//Funções para manipulação do arquivo:
void criarArquivo(const char *nomeArquivo, Equipe equipes[], int *qtdEquipes);
void lerArquivo(const char *nomeArquivo, Equipe equipes[], int *qtdEquipes);
void salvarArquivo(const char *nomeArquivo, Equipe equipes[], int qtdEquipes);

//Funções de gerenciamento:
void cadastrarEquipe(Equipe equipes[], int *qtdEquipes);
void listarEquipes(Equipe equipes[], int qtdEquipes);
void maiorAcerto(Equipe equipes[], int qtdEquipes);
void mediaIdade(Equipe equipes[], int qtdEquipes);
void consultarEquipesPorLetra(Equipe equipes[], int qtdEquipes, char letra);

int main(){
    setlocale(LC_ALL, "portuguese");

    Equipe equipes[TamEquipes];
    int qtdEquipes = 0;
    int opcaoMenuInicial, opcaoMenuOpcoes;      //Variáveis para manipular os menus de opções
    char nomeArquivo[TamNome] = "equipes.txt";

    do{
        //Menu Inicial:
        printf("\n*** Menu Inicial ***\n");
        printf("1. Criar arquivo\n");
        printf("2. Ler equipes cadastradas em um arquivo\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoMenuInicial);

        switch (opcaoMenuInicial){
            case 1:
                criarArquivo(nomeArquivo, equipes, &qtdEquipes);
                break;
            case 2:
                lerArquivo(nomeArquivo, equipes, &qtdEquipes);
                break;
            default:
                printf("Opcao invalida.\n");
        }

        do {
            //Menu de Opções:
            printf("\n*** Menu de Opcoes ***\n");
            printf("1. Cadastrar uma equipe\n");
            printf("2. Listar todas as equipes inscritas\n");
            printf("3. Mostrar a maior quantidade de acertos e as equipes com esse resultado\n");
            printf("4. Calcular e mostrar a media de idade dos competidores de cada equipe\n");
            printf("5. Consultar as equipes cujo nome inicia por uma letra digitada\n");
            printf("6. Finalizar o programa\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcaoMenuOpcoes);

            switch (opcaoMenuOpcoes){
                case 1:
                    cadastrarEquipe(equipes, &qtdEquipes);
                    break;
                case 2:
                    listarEquipes(equipes, qtdEquipes);
                    break;
                case 3:
                    maiorAcerto(equipes, qtdEquipes);
                    break;
                case 4:
                    mediaIdade(equipes, qtdEquipes);
                    break;
                case 5: {
                    char letra;
                    printf("Digite a letra: ");
                    scanf(" %c", &letra);
                    consultarEquipesPorLetra(equipes, qtdEquipes, letra);
                    break;
                }
                case 6:
                    salvarArquivo(nomeArquivo, equipes, qtdEquipes);
                    printf("Programa finalizado.\n");
                    break;
                default:
                    printf("Opcao invalida.\n");
            }

        } while (opcaoMenuOpcoes != 6);

    } while (opcaoMenuInicial != 6);

    return 0;
}

//Função para criar o arquivo:
void criarArquivo(const char *nomeArquivo, Equipe equipes[], int *qtdEquipes){
    FILE *file = fopen(nomeArquivo, "w");  //'fopen' abre o arquivo, já 'wb' cria um arquivo novo binário para ser escrito ou reescrito
    if (file == NULL){  //Verifica se o arquivo foi criado
        printf("Erro ao criar o arquivo.\n");
        return;
    }
    fwrite(qtdEquipes, sizeof(int), 1, file);  //Escreve a quantidade inicial de equipes
    fclose(file);   //Fecha o arquivo
    printf("Arquivo criado com sucesso.\n");
}

//Função para ler os dados do arquivo:
void lerArquivo(const char *nomeArquivo, Equipe equipes[], int *qtdEquipes){
    FILE *file = fopen(nomeArquivo, "r");  //'rb' abre o arquivo binário para ler
    if (file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fread(qtdEquipes, sizeof(int), 1, file);            //Lê a quantidade de equipes
    fread(equipes, sizeof(Equipe), *qtdEquipes, file);  //Lê os dados das equipes
    fclose(file);
    printf("Dados lidos com sucesso.\n");
}

//Função para salvar os dados no arquivo:
void salvarArquivo(const char *nomeArquivo, Equipe equipes[], int qtdEquipes){
    FILE *file = fopen(nomeArquivo, "w");
    if (file == NULL) {
        printf("Erro ao salvar o arquivo.\n");
        return;
    }
    fwrite(&qtdEquipes, sizeof(int), 1, file);              //Escreve a quantidade de equipes
    fwrite(equipes, sizeof(Equipe), qtdEquipes, file);      //Escreve as equipes
    fclose(file);
}

//Função para cadastrar uma equipe:
void cadastrarEquipe(Equipe equipes[], int *qtdEquipes){
    if (*qtdEquipes >= TamEquipes){     //Verifica se a quantidade não ultrupassou o tamanho definido
        printf("Nao ha espaco para mais equipes.\n");
        return;
    }
    //Pede ao usuário os dados da equipe:
    printf("Digite o nome da equipe: ");
    scanf(" %[^\n]", equipes[*qtdEquipes].nome);
    printf("Digite as idades dos 3 competidores: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &equipes[*qtdEquipes].idade[i]);
    }
    printf("Digite o numero de acertos da equipe: ");
    scanf("%d", &equipes[*qtdEquipes].acertos);
    (*qtdEquipes)++;
    printf("Equipe cadastrada com sucesso.\n");
}

//Função para listar todas as equipes:
void listarEquipes(Equipe equipes[], int qtdEquipes){
    if (qtdEquipes == 0){
        printf("Nao ha equipes cadastradas.\n");
        return;
    }
    //Laço que lista as equipes:
    for (int i = 0; i < qtdEquipes; i++){
        printf("Equipe: %s\n", equipes[i].nome);
        printf("Idades: %d, %d, %d\n", equipes[i].idade[0], equipes[i].idade[1], equipes[i].idade[2]);
        printf("Acertos: %d\n", equipes[i].acertos);
        printf("-----------------------------\n");
    }
}

//Função para mostrar a maior quantidade de acertos:
void maiorAcerto(Equipe equipes[], int qtdEquipes){
    if (qtdEquipes == 0){
        printf("Nao ha equipes cadastradas.\n");
        return;
    }
    int maior = equipes[0].acertos;
    for (int i = 1; i < qtdEquipes; i++){
        if (equipes[i].acertos > maior){
            maior = equipes[i].acertos;
        }
    }
    printf("Maior quantidade de acertos: %d\n", maior);
    for (int i = 0; i < qtdEquipes; i++){
        if (equipes[i].acertos == maior){
            printf("Equipe: %s\n", equipes[i].nome);
            printf("Idades: %d, %d, %d\n", equipes[i].idade[0], equipes[i].idade[1], equipes[i].idade[2]);
            printf("Acertos: %d\n", equipes[i].acertos);
            printf("-----------------------------\n");
        }
    }
}

//Função para calcular e mostrar a média de idade dos competidores de cada equipe:
void mediaIdade(Equipe equipes[], int qtdEquipes){
    if (qtdEquipes == 0){
        printf("Nao ha equipes cadastradas.\n");
        return;
    }
    for (int i = 0; i < qtdEquipes; i++){
        float media = (equipes[i].idade[0] + equipes[i].idade[1] + equipes[i].idade[2]) / 3.0;
        printf("Equipe: %s\n", equipes[i].nome);
        printf("Media de idades: %.2f\n", media);
        printf("-----------------------------\n");
    }
}

//Função para consultar as equipes cujo nome começa com uma letra:
void consultarEquipesPorLetra(Equipe equipes[], int qtdEquipes, char letra){
    int encontrou = 0;
    char Nletra = tolower(letra);
    for (int i = 0; i < qtdEquipes; i++) {
        // Verifica se o nome da equipe não está vazio e compara a primeira letra do nome
        if (equipes[i].nome[0] != '\0' && tolower(equipes[i].nome[0]) == Nletra) {
            printf("Equipe: %s\n", equipes[i].nome);
            printf("-----------------------------\n");
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nao ha equipes com esse nome.\n");
    }
}
