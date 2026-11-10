#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_ACOES 100

typedef struct {
    int codigo;
    char escola[50];
    char tema[50];
    char dataPrevista[20];
    char publicoAlvo[50];
    char responsavel[50];
    int quantidadePrevista;
    char situacao[12];
    int participantesEfetivos;
} Acao;


void lerTexto(char destino[], int tamanho) {
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }

    size_t tamanhoTexto = strlen(destino);

    if (tamanhoTexto > 0 && destino[tamanhoTexto - 1] == '\n') {
        destino[tamanhoTexto - 1] = '\0';
    } else {
        // Limpa o restante caso a entrada seja maior que o buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}


void lerTextoObrigatorio(char destino[], int tamanho, char mensagem[]) {
    do {
        printf("%s", mensagem);
        lerTexto(destino, tamanho);

        if (strlen(destino) == 0) {
            printf("Campo obrigatorio! Preencha novamente.\n");
        }

    } while (strlen(destino) == 0);
}

int lerInteiro(char mensagem[], int minimo, int maximo) {
    char linha[50];
    char *fim;
    long valor;

    while (1) {
        printf("%s", mensagem);
        lerTexto(linha, sizeof(linha));

        valor = strtol(linha, &fim, 10);

        // Verifica se existe um numero valido
        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (linha[0] != '\0' && fim != linha && *fim == '\0'
            && valor >= minimo && valor <= maximo) {
            return (int)valor;
        }

        printf("Valor invalido! Digite um numero entre %d e %d.\n",
               minimo, maximo);
    }
}

int contemTexto(char texto[], char pesquisa[]) {
    int tamanhoTexto = strlen(texto);
    int tamanhoPesquisa = strlen(pesquisa);
    int i, j;

    if (tamanhoPesquisa == 0) {
        return 1;
    }

    for (i = 0; i <= tamanhoTexto - tamanhoPesquisa; i++) {
        int encontrou = 1;

        for (j = 0; j < tamanhoPesquisa; j++) {
            if (tolower((unsigned char)texto[i + j]) !=
                tolower((unsigned char)pesquisa[j])) {
                encontrou = 0;
                break;
            }
        }

        if (encontrou) {
            return 1;
        }
    }

    return 0;
}

int localizarCodigo(Acao acoes[], int total, int codigo) {
	int i;
    for (i = 0; i < total; i++) {
        if (acoes[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void exibirAcao(Acao a) {
    printf("\n----------------------------------------\n");
    printf("Codigo: %d\n", a.codigo);
    printf("Escola: %s\n", a.escola);
    printf("Tema: %s\n", a.tema);
    printf("Data prevista: %s\n", a.dataPrevista);
    printf("Publico-alvo: %s\n", a.publicoAlvo);
    printf("Responsavel: %s\n", a.responsavel);
    printf("Quantidade prevista: %d\n", a.quantidadePrevista);
    printf("Situacao: %s\n", a.situacao);
    printf("Participantes efetivos: %d\n", a.participantesEfetivos);
    printf("----------------------------------------\n");
}

void mostrarMenu() {
    printf("\n========== SISTEMA PSE ==========\n");
    printf("1 - Cadastrar acao\n");
    printf("2 - Listar acoes\n");
    printf("3 - Pesquisar acao\n");
    printf("4 - Atualizar situacao\n");
    printf("5 - Gerar resumo\n");
    printf("0 - Encerrar\n");
    printf("================================\n");
}


int cadastrarAcao(Acao acoes[], int total) {

    if (total >= MAX_ACOES) {
        printf("\nLimite maximo de acoes atingido!\n");
        return total;
    }

    printf("\n========== CADASTRO DE ACAO ==========\n");

    int codigo;

    while (1) {
        codigo = lerInteiro("Codigo da acao: ", 1, INT_MAX);

        if (localizarCodigo(acoes, total, codigo) == -1) {
            break;
        }

        printf("Esse codigo ja esta cadastrado! Tente outro.\n");
    }

    acoes[total].codigo = codigo;

    lerTextoObrigatorio(acoes[total].escola, 50,
                        "Nome da escola: ");

    lerTextoObrigatorio(acoes[total].tema, 50,
                        "Tema da acao: ");

    lerTextoObrigatorio(acoes[total].dataPrevista, 20,
                        "Data prevista: ");

    lerTextoObrigatorio(acoes[total].publicoAlvo, 50,
                        "Publico-alvo: ");

    lerTextoObrigatorio(acoes[total].responsavel, 50,
                        "Responsavel: ");

    acoes[total].quantidadePrevista =
        lerInteiro("Quantidade prevista de participantes: ", 0, INT_MAX);

    printf("\nSituacao inicial:\n");
    printf("1 - Planejada\n");
    printf("2 - Realizada\n");
    printf("3 - Cancelada\n");

    int opcao = lerInteiro("Escolha: ", 1, 3);

    switch (opcao) {
        case 1:
            strcpy(acoes[total].situacao, "Planejada");
            acoes[total].participantesEfetivos = 0;
            break;
        case 2:
            strcpy(acoes[total].situacao, "Realizada");
            acoes[total].participantesEfetivos = lerInteiro("Quantidade efetiva de participantes: ", 0, INT_MAX);
            break;
        case 3:
            strcpy(acoes[total].situacao, "Cancelada");
            acoes[total].participantesEfetivos = 0;
            break;
    }

    printf("\nAcao cadastrada com sucesso!\n");

    return total + 1;
}

void listarAcoes(Acao acoes[], int total) {
	int i;

    printf("\n========== LISTA DE ACOES ==========\n");

    if (total == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        exibirAcao(acoes[i]);
    }

    printf("\nTotal de acoes cadastradas: %d\n", total);
}

void pesquisarAcao(Acao acoes[], int total) {
	int i;

    if (total == 0) {
        printf("\nNenhuma acao cadastrada para pesquisar.\n");
        return;
    }

    printf("\n========== PESQUISAR ACAO ==========\n");
    printf("1 - Pesquisar por codigo\n");
    printf("2 - Pesquisar por escola\n");
    printf("3 - Pesquisar por tema\n");

    int opcao = lerInteiro("Escolha: ", 1, 3);

    int encontrou = 0;

    if (opcao == 1) {
        int codigo = lerInteiro("Digite o codigo: ", 1, INT_MAX);

        int posicao = localizarCodigo(acoes, total, codigo);

        if (posicao != -1) {
            exibirAcao(acoes[posicao]);
            encontrou = 1;
        }
    }

    else if (opcao == 2 || opcao == 3) {

        char pesquisa[50];

        if (opcao == 2) {
            lerTextoObrigatorio(pesquisa, 50, "Digite o nome da escola: ");
        } else { lerTextoObrigatorio(pesquisa, 50, "Digite o tema: ");
          }

        for (i = 0; i < total; i++) {
            if ((opcao == 2 &&
                 contemTexto(acoes[i].escola, pesquisa)) || (opcao == 3 && contemTexto(acoes[i].tema, pesquisa))) {
                exibirAcao(acoes[i]);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("\nNenhuma acao encontrada com esses dados.\n");
    }
}

void atualizarSituacao(Acao acoes[], int total) {

    if (total == 0) {
        printf("\nNenhuma acao cadastrada para atualizar.\n");
        return;
    }

    printf("\n========== ATUALIZAR ACAO ==========\n");

    int codigo = lerInteiro("Digite o codigo da acao: ", 1, INT_MAX);

    int posicao = localizarCodigo(acoes, total, codigo);

    if (posicao == -1) {
        printf("\nAcao nao encontrada!\n");
        return;
    }

    printf("\nAcao localizada:\n");
    exibirAcao(acoes[posicao]);

    printf("\nNova situacao:\n");
    printf("1 - Planejada\n");
    printf("2 - Realizada\n");
    printf("3 - Cancelada\n");

    int opcao = lerInteiro("Escolha: ", 1, 3);

    switch (opcao) {
        case 1:
            strcpy(acoes[posicao].situacao, "Planejada");
            acoes[posicao].participantesEfetivos = 0;
            break;
        case 2:
            strcpy(acoes[posicao].situacao, "Realizada");
            acoes[posicao].participantesEfetivos = lerInteiro("Quantidade efetiva de participantes: ", 0, INT_MAX);
            break;
        case 3:
            strcpy(acoes[posicao].situacao, "Cancelada");
            acoes[posicao].participantesEfetivos = 0;
            break;
    }
    printf("\nSituacao atualizada com sucesso!\n");
}

void gerarResumo(Acao acoes[], int total) {

    int planejadas = 0;
    int realizadas = 0;
    int canceladas = 0;

    int participantesPrevistos = 0;
    int participantesEfetivos = 0;

	int i;
    printf("\n========== RESUMO GERAL ==========\n");

    if (total == 0) {
        printf("Nenhuma acao cadastrada.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        participantesPrevistos += acoes[i].quantidadePrevista;

        if (strcmp(acoes[i].situacao, "Planejada") == 0) {
            planejadas++;
        } else if (strcmp(acoes[i].situacao, "Realizada") == 0) {
            realizadas++;
            participantesEfetivos += acoes[i].participantesEfetivos;
        } else if (strcmp(acoes[i].situacao, "Cancelada") == 0) {
            canceladas++;
        }
    }

    float percentual = 0;

    if (participantesPrevistos > 0) {
        percentual = ((float)participantesEfetivos /
                      participantesPrevistos) * 100;
    }

    printf("\nTotal de acoes: %d\n", total);

    printf("\nSituacao das acoes:\n");
    printf("Planejadas: %d\n", planejadas);
    printf("Realizadas: %d\n", realizadas);
    printf("Canceladas: %d\n", canceladas);

    printf("\nParticipantes:\n");
    printf("Total previsto: %d\n", participantesPrevistos);
    printf("Total efetivo: %d\n", participantesEfetivos);

    printf("\nPercentual de participacao: %.2f%%\n", percentual);

    printf("\n==================================\n");
}

int main() {
    Acao acoes[MAX_ACOES];

    int total = 0;
    int opcao;

    do {
        mostrarMenu();
        opcao = lerInteiro("Escolha uma opcao: ", 0, 5);
        switch (opcao) {
            case 1:
                total = cadastrarAcao(acoes, total);
                break;
            case 2:
                listarAcoes(acoes, total);
                break;
            case 3:
                pesquisarAcao(acoes, total);
                break;
            case 4:
                atualizarSituacao(acoes, total);
                break;
            case 5:
                gerarResumo(acoes, total);
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
