/*          PRODUTO DE APRENDIZAGEM I - Aluno: Jos� Ot�vio Baggio
        Controle de Pacientes */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//Usando define para depois, atribuir � vari�veis um tamanho estipulado de pacientes:
#define PacientesMax 100
#define NomeMax 100
#define PrescricaoMax 500

// Vari�veis Globais:
int TotalPacientes = 0;
int i;
char CodigoOuNome[NomeMax];

// Fun��o para dar espa�o entre cada se��o de comando informado ao usu�rio:
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

// Fun��o para cadastrar o Paciente:
void CadastrarPaciente() {
    if (TotalPacientes >= PacientesMax) {
        printf("Capacidade m�xima de pacientes atingida.\n");
        return;
    }

    struct Paciente NovoPaciente;
    linha();
    printf("C�digo do Paciente: ");
    scanf("%s", NovoPaciente.codigo);

    printf("Nome do Paciente: ");
    getchar(); // Limpando o buffer
    fgets(NovoPaciente.NomePaciente, NomeMax, stdin);
    NovoPaciente.NomePaciente[strcspn(NovoPaciente.NomePaciente, "\n")] = 0;  //estava utilizando fflush(stdin), mas n�o estava funcionando. Ent�o pesquisei outro

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%s", NovoPaciente.DataNascimento);

    printf("Nome da M�e: ");
    getchar();
    fgets(NovoPaciente.NomeMae, NomeMax, stdin);
    NovoPaciente.NomeMae[strcspn(NovoPaciente.NomeMae, "\n")] = 0;

    printf("Nome do Pai: ");
    fgets(NovoPaciente.NomePai, NomeMax, stdin);
    NovoPaciente.NomePai[strcspn(NovoPaciente.NomePai, "\n")] = 0;

    pacientes[TotalPacientes++] = NovoPaciente;
    printf("\n\tPaciente cadastrado com sucesso!\n");
}

// Fun��o para buscar paciente por c�digo ou nome:
struct Paciente* BuscarPaciente(char *CodigoOuNome){   //Utilizei ponteiros a partir daqui, para retornar o endere�o de mem�ria do paciente
    for (i = 0; i < TotalPacientes; i++) {
        if (strcmp(pacientes[i].codigo, CodigoOuNome) == 0 || strcmp(pacientes[i].NomePaciente, CodigoOuNome) == 0) {
            return &pacientes[i];
        }
    }
    return NULL;   //usando NULL, se nenhum paciente for encontrado ele ir� retornar
}

// Fun��o para registrar a consulta:
void RegistrarConsulta() {
    if (TotalPacientes == 0) {
        printf("\n\tNenhum Paciente Cadastrado...\n");
        return;
    }

    linha();
    printf("Informe o c�digo ou o nome do paciente: ");
    getchar();
    fgets(CodigoOuNome, NomeMax, stdin);
    CodigoOuNome[strcspn(CodigoOuNome, "\n")] = 0;  // Remover a quebra de linha

    struct Paciente *paciente = BuscarPaciente(CodigoOuNome);
    if (paciente == NULL) {
        printf("Paciente n�o encontrado...\n");
        return;
    }

    printf("Data da �ltima consulta (dd/mm/aaaa): ");
    scanf("%s", paciente->UltimaConsulta.DataUltimaConsulta);

    printf("Peso (Kg): ");
    scanf("%f", &paciente->UltimaConsulta.peso);

    printf("Altura (cm): ");
    scanf("%f", &paciente->UltimaConsulta.altura);

    printf("Prescri��o: ");
    getchar();
    fgets(paciente->UltimaConsulta.Prescricao, PrescricaoMax, stdin);
    paciente->UltimaConsulta.Prescricao[strcspn(paciente->UltimaConsulta.Prescricao, "\n")] = 0;  // Remover a quebra de linha

    printf("Valor Pago pela consulta: R$ ");
    scanf("%f", &paciente->UltimaConsulta.ValorPago);
    paciente->ConsultaRealizada = 1;

    printf("\n\tConsulta registrada com sucesso!\n");
}

// Fun��o para visualizar a prescri��o:
void VisualizarPrescricao() {
    if (TotalPacientes == 0) {
        printf("Nenhum paciente cadastrado...\n");
        return;
    }

    linha();
    printf("\nInforme o c�digo ou nome do paciente: ");
    getchar(); // Limpar o buffer
    fgets(CodigoOuNome, NomeMax, stdin);
    CodigoOuNome[strcspn(CodigoOuNome, "\n")] = 0;  // Remover a quebra de linha

    struct Paciente *paciente = BuscarPaciente(CodigoOuNome);
    if (paciente == NULL) {
        printf("\n\tPaciente n�o encontrado.\n");
        return;
    }

    if (paciente->ConsultaRealizada == 0) {
        printf("\n\tNenhuma consulta registrada para esse paciente.\n");
        return;
    }

    //novamente, utilizei ponteiros, mas agora pra imprimir os resultados:
    printf("C�digo: %s", paciente->codigo);
    printf("\nNome: %s", paciente->NomePaciente);
    printf("\nData da �ltima Consulta: %s", paciente->UltimaConsulta.DataUltimaConsulta);
    printf("\nPeso: %.2f Kg", paciente->UltimaConsulta.peso);
    printf("\nAltura: %.2f cm", paciente->UltimaConsulta.altura);
    printf("\nPrescri��o: %s", paciente->UltimaConsulta.Prescricao);
}

// Fun��o para listar os pacientes:
void ListarPacientes() {
    if (TotalPacientes == 0) {
        printf("\n\tNenhum paciente cadastrado.\n");
        return;
    }

    for (i = 0; i < TotalPacientes; i++) {
        struct Paciente p = pacientes[i];
        linha();
        printf("\nC�digo: %s\n", p.codigo);
        printf("\nNome: %s", p.NomePaciente);
        printf("\nData de Nascimento: %s", p.DataNascimento);
        printf("\nNome da M�e: %s", p.NomeMae);
        printf("\nNome do Pai: %s", p.NomePai);
        if (p.ConsultaRealizada) {
            printf("\nData da �ltima Consulta: %s\n", p.UltimaConsulta.DataUltimaConsulta);
        } else {
            printf("\n\tNenhuma consulta registrada.\n");
        }
    }
}

// Fun��o para calcular o valor total recebido pelas consultas:
void ValorTotalRecebido() {
    int mes, ano, DiaConsulta, MesConsulta, AnoConsulta;
    float TotalRecebido = 0.0;

    if (TotalPacientes == 0) {
        printf("\n\tNenhum paciente cadastrado.\n");
        return;
    }

    linha();
    printf("Informe o m�s e o ano (mm aaaa): ");
    scanf("%d %d", &mes, &ano);

    for (i = 0; i < TotalPacientes; i++) {
        if (pacientes[i].ConsultaRealizada) {
            sscanf(pacientes[i].UltimaConsulta.DataUltimaConsulta, "%d/%d/%d", &DiaConsulta, &MesConsulta, &AnoConsulta);
            if (mes == MesConsulta && ano == AnoConsulta) {
                TotalRecebido += pacientes[i].UltimaConsulta.ValorPago;
            }
        }
    }

    printf("\nValor total recebido no m�s %02d/%d: R$ %.2f\n", mes, ano, TotalRecebido);
}

int main() {
    setlocale(LC_ALL, "portuguese");   //Localizando o c�digo para Portugu�s

    int opcao;  // Vari�vel para controlar o menu de op��es

    //Imprimindo a apresenta��o do programa:
    printf("\tCONTROLE DE PACIENTES - �rea Pedi�trica\n");
    printf("\t\tPowered by: UFN Medicine\n");
    linha();

    // Menu de op��es oferecido ao usu�rio para come�ar o programa:
    do {
        printf("\nMenu de Op��es:\n");
        printf("1. Cadastrar Paciente\n");
        printf("2. Registrar Consulta\n");
        printf("3. Visualizar Prescri��o\n");
        printf("4. Listar Pacientes\n");
        printf("5. Valor total recebido no m�s\n");
        printf("6. Finalizar\n");
        printf("Escolha uma op��o: ");
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
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 6);


    return 0;
}
