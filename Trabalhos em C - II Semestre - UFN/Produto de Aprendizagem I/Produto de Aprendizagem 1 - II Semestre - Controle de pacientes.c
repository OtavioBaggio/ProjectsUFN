/*          PRODUTO DE APRENDIZAGEM I - Aluno: José Otávio Baggio
        Controle de Pacientes */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//Usando define para depois, atribuir à variáveis um tamanho estipulado de pacientes:
#define PacientesMax 100
#define NomeMax 100
#define PrescricaoMax 500

// Variáveis Globais:
int TotalPacientes = 0;
int i;
char CodigoOuNome[NomeMax];

// Função para dar espaço entre cada seção de comando informado ao usuário:
void linha() {
    printf("==============================================================\n");
}

// Estrutura para os dados da consulta:
struct Consulta {
    char DataUltimaConsulta[11];
    float peso;
    float altura;
    float ValorPago;
    char Prescricao[PrescricaoMax];
};

// Estrutura para armazenar os dados do paciente:
struct Paciente {
    char codigo[20];
    char NomePaciente[NomeMax];
    char NomeMae[NomeMax];
    char NomePai[NomeMax];
    char DataNascimento[11];
    struct Consulta UltimaConsulta;
    int ConsultaRealizada;
};

struct Paciente pacientes[PacientesMax];

// Função para cadastrar o Paciente:
void CadastrarPaciente() {
    if (TotalPacientes >= PacientesMax) {
        printf("Capacidade máxima de pacientes atingida.\n");
        return;
    }

    struct Paciente NovoPaciente;
    linha();
    printf("Código do Paciente: ");
    scanf("%s", NovoPaciente.codigo);

    printf("Nome do Paciente: ");
    getchar(); // Limpando o buffer
    fgets(NovoPaciente.NomePaciente, NomeMax, stdin);
    NovoPaciente.NomePaciente[strcspn(NovoPaciente.NomePaciente, "\n")] = 0;  //estava utilizando fflush(stdin), mas não estava funcionando. Então pesquisei outro

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%s", NovoPaciente.DataNascimento);

    printf("Nome da Mãe: ");
    getchar();
    fgets(NovoPaciente.NomeMae, NomeMax, stdin);
    NovoPaciente.NomeMae[strcspn(NovoPaciente.NomeMae, "\n")] = 0;

    printf("Nome do Pai: ");
    fgets(NovoPaciente.NomePai, NomeMax, stdin);
    NovoPaciente.NomePai[strcspn(NovoPaciente.NomePai, "\n")] = 0;

    pacientes[TotalPacientes++] = NovoPaciente;
    printf("\n\tPaciente cadastrado com sucesso!\n");
}

// Função para buscar paciente por código ou nome:
struct Paciente* BuscarPaciente(char *CodigoOuNome){   //Utilizei ponteiros a partir daqui, para retornar o endereço de memória do paciente
    for (i = 0; i < TotalPacientes; i++) {
        if (strcmp(pacientes[i].codigo, CodigoOuNome) == 0 || strcmp(pacientes[i].NomePaciente, CodigoOuNome) == 0) {
            return &pacientes[i];
        }
    }
    return NULL;   //usando NULL, se nenhum paciente for encontrado ele irá retornar
}

// Função para registrar a consulta:
void RegistrarConsulta() {
    if (TotalPacientes == 0) {
        printf("\n\tNenhum Paciente Cadastrado...\n");
        return;
    }

    linha();
    printf("Informe o código ou o nome do paciente: ");
    getchar();
    fgets(CodigoOuNome, NomeMax, stdin);
    CodigoOuNome[strcspn(CodigoOuNome, "\n")] = 0;  // Remover a quebra de linha

    struct Paciente *paciente = BuscarPaciente(CodigoOuNome);
    if (paciente == NULL) {
        printf("Paciente não encontrado...\n");
        return;
    }

    printf("Data da última consulta (dd/mm/aaaa): ");
    scanf("%s", paciente->UltimaConsulta.DataUltimaConsulta);

    printf("Peso (Kg): ");
    scanf("%f", &paciente->UltimaConsulta.peso);

    printf("Altura (cm): ");
    scanf("%f", &paciente->UltimaConsulta.altura);

    printf("Prescrição: ");
    getchar();
    fgets(paciente->UltimaConsulta.Prescricao, PrescricaoMax, stdin);
    paciente->UltimaConsulta.Prescricao[strcspn(paciente->UltimaConsulta.Prescricao, "\n")] = 0;  // Remover a quebra de linha

    printf("Valor Pago pela consulta: R$ ");
    scanf("%f", &paciente->UltimaConsulta.ValorPago);
    paciente->ConsultaRealizada = 1;

    printf("\n\tConsulta registrada com sucesso!\n");
}

// Função para visualizar a prescrição:
void VisualizarPrescricao() {
    if (TotalPacientes == 0) {
        printf("Nenhum paciente cadastrado...\n");
        return;
    }

    linha();
    printf("\nInforme o código ou nome do paciente: ");
    getchar(); // Limpar o buffer
    fgets(CodigoOuNome, NomeMax, stdin);
    CodigoOuNome[strcspn(CodigoOuNome, "\n")] = 0;  // Remover a quebra de linha

    struct Paciente *paciente = BuscarPaciente(CodigoOuNome);
    if (paciente == NULL) {
        printf("\n\tPaciente não encontrado.\n");
        return;
    }

    if (paciente->ConsultaRealizada == 0) {
        printf("\n\tNenhuma consulta registrada para esse paciente.\n");
        return;
    }

    //novamente, utilizei ponteiros, mas agora pra imprimir os resultados:
    printf("Código: %s", paciente->codigo);
    printf("\nNome: %s", paciente->NomePaciente);
    printf("\nData da Última Consulta: %s", paciente->UltimaConsulta.DataUltimaConsulta);
    printf("\nPeso: %.2f Kg", paciente->UltimaConsulta.peso);
    printf("\nAltura: %.2f cm", paciente->UltimaConsulta.altura);
    printf("\nPrescrição: %s", paciente->UltimaConsulta.Prescricao);
}

// Função para listar os pacientes:
void ListarPacientes() {
    if (TotalPacientes == 0) {
        printf("\n\tNenhum paciente cadastrado.\n");
        return;
    }

    for (i = 0; i < TotalPacientes; i++) {
        struct Paciente p = pacientes[i];
        linha();
        printf("\nCódigo: %s\n", p.codigo);
        printf("\nNome: %s", p.NomePaciente);
        printf("\nData de Nascimento: %s", p.DataNascimento);
        printf("\nNome da Mãe: %s", p.NomeMae);
        printf("\nNome do Pai: %s", p.NomePai);
        if (p.ConsultaRealizada) {
            printf("\nData da Última Consulta: %s\n", p.UltimaConsulta.DataUltimaConsulta);
        } else {
            printf("\n\tNenhuma consulta registrada.\n");
        }
    }
}

// Função para calcular o valor total recebido pelas consultas:
void ValorTotalRecebido() {
    int mes, ano, DiaConsulta, MesConsulta, AnoConsulta;
    float TotalRecebido = 0.0;

    if (TotalPacientes == 0) {
        printf("\n\tNenhum paciente cadastrado.\n");
        return;
    }

    linha();
    printf("Informe o mês e o ano (mm aaaa): ");
    scanf("%d %d", &mes, &ano);

    for (i = 0; i < TotalPacientes; i++) {
        if (pacientes[i].ConsultaRealizada) {
            sscanf(pacientes[i].UltimaConsulta.DataUltimaConsulta, "%d/%d/%d", &DiaConsulta, &MesConsulta, &AnoConsulta);
            if (mes == MesConsulta && ano == AnoConsulta) {
                TotalRecebido += pacientes[i].UltimaConsulta.ValorPago;
            }
        }
    }

    printf("\nValor total recebido no mês %02d/%d: R$ %.2f\n", mes, ano, TotalRecebido);
}

int main() {
    setlocale(LC_ALL, "portuguese");   //Localizando o código para Português

    int opcao;  // Variável para controlar o menu de opções

    //Imprimindo a apresentação do programa:
    printf("\tCONTROLE DE PACIENTES - Área Pediátrica\n");
    printf("\t\tPowered by: UFN Medicine\n");
    linha();

    // Menu de opções oferecido ao usuário para começar o programa:
    do {
        printf("\nMenu de Opções:\n");
        printf("1. Cadastrar Paciente\n");
        printf("2. Registrar Consulta\n");
        printf("3. Visualizar Prescrição\n");
        printf("4. Listar Pacientes\n");
        printf("5. Valor total recebido no mês\n");
        printf("6. Finalizar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                CadastrarPaciente();
                break;
            case 2:
                RegistrarConsulta();
                break;
            case 3:
                VisualizarPrescricao();
                break;
            case 4:
                ListarPacientes();
                break;
            case 5:
                ValorTotalRecebido();
                break;
            case 6:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);


    return 0;
}
