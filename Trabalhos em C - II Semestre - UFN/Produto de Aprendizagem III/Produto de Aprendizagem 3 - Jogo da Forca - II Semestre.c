/*      Produto de Aprendizagem 3 - II Semestre - Cenário / Problema 1
            Alunos: José Otávio R. Baggio; Joseph Strucker Calgaro;

    Desenvolva um programa, na linguagem C, para implementar o Jogo da Forca: jogo de adivinhar uma palavra, escolhendo letras que
podem estar contidas na palavra. Como estamos trabalhando a interface em modo texto, use a criatividade para representar quantas
chances o usuário terá para adivinhar a palavra.
*/

    //Os dois alunos participaram do desenvolvimento de ambas as funções do código;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para srand e time
#include <locale.h>

#define MAX_CHANCES 6
#define MAX_WORD_LENGTH 100
#define WORDS_FILE "palavras.txt"

// Função para escolher uma palavra aleatória do arquivo
char *escolher_palavra(const char *nome_arquivo, int linha_aleatoria) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de palavras.\n");
        exit(1);
    }

    char buffer[MAX_WORD_LENGTH];
    int linha_atual = 0;
    while (fgets(buffer, sizeof(buffer), arquivo)) {
        if (linha_atual == linha_aleatoria) {
            fclose(arquivo);
            buffer[strcspn(buffer, "\n")] = '\0'; // 'strcspn(string, parametro)' percorre a string comparando se há um caracter igual ao parametro, se ele existe o remove da string, se não retorna o tamanho da string  Remove o '\n'
            char *palavra = (char *)malloc(strlen(buffer) + 1);
            strcpy(palavra, buffer); // 'strcpy(string1, string2)' copia o contudo da string2 para a string1
            return palavra;
        }
        linha_atual++;
    }
    fclose(arquivo);
    return NULL; // Caso a palavra não seja encontrada
}

// Função para exibir o estado atual da forca
void mostrar_forca(int erros) {
    const char *estados[] = {
        "  +---+\n      |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n  |   |\n      |\n     ===",
        "  +---+\n  O   |\n /|   |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="
    };
    printf("%s\n", estados[erros]);
}

// Função para verificar se o jogador venceu
int venceu(const char *palavra, const char *tentativa) {
    return strcmp(palavra, tentativa) == 0;
    /* 'strcmp(string1, string2)' é usada para comparar duas strings lexicograficamente
    < 0: str1 é lexicograficamente menor que str2.
    0: str1 é igual a str2.
    > 0: str1 é lexicograficamente maior que str2.
    */
}

// Função principal
int main() {
    setlocale(LC_ALL, "portuguese");

    srand(time(NULL)); // Inicializa o gerador de números aleatórios com a semente baseada no tempo

    int total_palavras = 118;
    int linha_aleatoria = rand() % total_palavras; // Gera um índice aleatório entre 0 e total_palavras - 1

    char *palavra = escolher_palavra(WORDS_FILE, linha_aleatoria);
    int tamanho_palavra = strlen(palavra);

    char *tentativa = (char *)malloc(tamanho_palavra + 1);
    memset(tentativa, '_', tamanho_palavra);  //preenche a tentativa com '_' representando caracteres não conhecidos no tamanho da palavra
    tentativa[tamanho_palavra] = '\0';

    int chances = 0;
    char letra;
    int acertou = 0;

    printf("Bem-vindo ao Jogo da Forca!\n");
    while (chances < MAX_CHANCES && !acertou) {
        mostrar_forca(chances);
        printf("Palavra: %s\n", tentativa);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        int encontrou = 0;
        for (int i = 0; i < tamanho_palavra; i++) {
            if (palavra[i] == letra && tentativa[i] == '_') {
                tentativa[i] = letra;
                encontrou = 1;
            }
        }

        if (!encontrou) {
            chances++;
        }

        acertou = venceu(palavra, tentativa);
    }

    mostrar_forca(chances);

    if (acertou) {
        printf("Parabéns! Você acertou a palavra: %s\n", palavra);
    } else {
        printf("Você perdeu! A palavra era: %s\n", palavra);
    }

    free(palavra);
    free(tentativa);

    return 0;
}
