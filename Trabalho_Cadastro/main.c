#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs
typedef struct Cadastro{
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
} TCadastro;

typedef struct CadastroU {
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo; // 'I', 'C' ou 'S'
} TCadastroU;

// 1. Lista da Industria - Encadeada Simples
typedef struct NoI{
    TCadastro *Dados;
    struct NoI *Prox;
} TNoI;

// 2. Lista Comercio - Duplamento Encadeada
typedef struct NoC{
    TCadastro *Dados;
    struct NoC *Ant;
    struct NoC *Prox; 
} TNoC;

// 3. Lista do Servico - Duplamente Encadeada com descritor
typedef struct NoS{
    TCadastro *Dados;
    struct NoS *Ant;
    struct NoS *Prox;
} TNoS;

typedef struct DescritorS{
    TNoS *Inicio;
    int Tamanho;
    TNoS *Fim;
} TDescritorS;

// 4. Lista Unificada - Dupla Encadeada e descritor

typedef struct NoU{
    TCadastroU *Dados;
    struct NoU *Ant;
    struct NoU *Prox;
} TNoU;

typedef struct DescritorU{
    TNoU *Inicio;
    int Tamanho;
    TNoU *Fim;
} TDescritorU;

void insereIndustriaFim(TNoI **inicio, TCadastro *dados){
    TNoI *novo = (TNoI*) malloc(sizeof(TNoI));
    novo -> Dados = dados;
    novo -> Prox = NULL;
    if(*inicio == NULL){
        *inicio = novo;
    } else {
        TNoI *aux = *inicio;
        while(aux -> Prox != NULL) {
            aux = aux -> Prox;
        }
        aux -> Prox = novo;
    }
}

void insereComercioFim(TNoC **inicio, TCadastro *dados){
    TNoC *novo = (TNoC*) malloc(sizeof(TNoC));
    novo -> Dados = dados;
    novo -> Prox = NULL;
    if(*inicio == NULL){
        novo -> Ant = NULL;
        *inicio = novo;
    } else {
        TNoC *aux = *inicio;
        while(aux -> Prox != NULL){
            aux = aux -> Prox;
        }
        aux -> Prox = novo;
        novo -> Ant = aux;
    }
}

void insereServicoFim(TDescritorS *desc, TCadastro *dados){
    TNoS *novo = (TNoS*) malloc(sizeof(TNoS));
    novo -> Dados = dados;
    novo -> Prox = NULL;
    novo -> Ant = desc -> Fim;

    if(desc -> Inicio == NULL){
        desc -> Inicio = novo;
    } else {
        desc -> Fim -> Prox = novo;
    }
    desc -> Fim = novo;
    desc -> Tamanho++;
}

void insereUnificadaFim(TDescritorU *desc, TCadastroU *dados){
    TNoU *novo = (TNoU*) malloc (sizeof(TNoU));
    novo -> Dados = dados;
    novo -> Prox = NULL;
    novo -> Ant = desc -> Fim;

    if (desc -> Inicio == NULL){
        desc -> Inicio = novo;
    } else {
        desc -> Fim -> Prox = novo;
    }
    desc -> Fim = novo;
    desc -> Tamanho++;
}

// peguei da IA mesmo, pra criar os arquivos seguindo a estrutura

void criarArquivosDeTeste() {
    FILE *f;
    f = fopen("Industria.txt", "r");
    if (!f) {
        f = fopen("Industria.txt", "w");
        if (f) {
            fprintf(f, "12345678000100;Metalurgica Alfa;Brasilia;61999991111\n");
            fprintf(f, "11111111000111;Alimentos Beta;Taguatinga;61988882222\n");
            fclose(f);
        }
    } else { fclose(f); }
    f = fopen("Comercio.txt", "r");
    if (!f) {
        f = fopen("Comercio.txt", "w");
        if (f) {
            fprintf(f, "22222222000122;Supermercado Gamma;Ceilandia;61977773333\n");
            fprintf(f, "33333333000133;Lojas Delta;Sobradinho;61966664444\n");
            fclose(f);
        }
    } else { fclose(f); }
    f = fopen("Servico.txt", "r");
    if (!f) {
        f = fopen("Servico.txt", "w");
        if (f) {
            fprintf(f, "44444444000144;Clinica Epsilon;Gama;61955555555\n");
            fprintf(f, "55555555000155;Consultoria Zeta;Planaltina;61944446666\n");
            fclose(f);
        }
    } else { fclose(f); }
}

// Leitura dos arquivos Idustra Comercio e servico

void carregarIndustria(TNoI **lista){
    FILE *file = fopen("Industria.txt", "r");
    if(!file){
        printf("Erro ao abrir Industria.txt");
        return;
    }

    char linha[200];

    while(fgets(linha, sizeof(linha), file)){
        if(linha[0] == '\n' || linha[0] == '\r') continue;
        
        TCadastro *c = (TCadastro*) malloc(sizeof(TCadastro));
        linha[strcspn(linha, "\r\n")] = '\0';

        char *cnpj = strtok(linha, ";");
        char *razao = strtok(NULL, ";");
        char *cidade = strtok(NULL, ";");
        char *fone = strtok(NULL, ";");

        if(cnpj && razao && cidade && fone){
            strncpy(c -> CNPJ, cnpj, 14); c -> CNPJ[14] = '\0';
            strncpy(c -> RazaoSocial, razao, 49); c -> RazaoSocial[49] = '\0';
            strncpy(c->Cidade, cidade, 29); c->Cidade[29] = '\0';
            strncpy(c->Fone, fone, 11); c->Fone[11] = '\0';
            insereIndustriaFim(lista, c);
        } else {
            free(c);
        }
    }
    fclose(file);
    printf("Carregou Industria\n");
}

void carregarComercio(TNoC **lista) {
    FILE *file = fopen("Comercio.txt", "r");
    if (!file) {
        printf("Erro ao abrir Comercio.txt\n");
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '\r') continue;
        TCadastro *c = (TCadastro*) malloc(sizeof(TCadastro));
        
        line[strcspn(line, "\r\n")] = '\0';
        char *cnpj = strtok(line, ";");
        char *razao = strtok(NULL, ";");
        char *cidade = strtok(NULL, ";");
        char *fone = strtok(NULL, ";");
        
        if (cnpj && razao && cidade && fone) {
            strncpy(c->CNPJ, cnpj, 14); c->CNPJ[14] = '\0';
            strncpy(c->RazaoSocial, razao, 49); c->RazaoSocial[49] = '\0';
            strncpy(c->Cidade, cidade, 29); c->Cidade[29] = '\0';
            strncpy(c->Fone, fone, 11); c->Fone[11] = '\0';
            insereComercioFim(lista, c);
        } else {
            free(c);
        }
    }
    fclose(file);
    printf("Dados de Comercio carregados.\n");
}

void carregarServico(TDescritorS *desc) {
    FILE *file = fopen("Servico.txt", "r");
    if (!file) {
        printf("Erro ao abrir Servico.txt\n");
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '\r') continue;
        TCadastro *c = (TCadastro*) malloc(sizeof(TCadastro));
        
        line[strcspn(line, "\r\n")] = '\0';
        char *cnpj = strtok(line, ";");
        char *razao = strtok(NULL, ";");
        char *cidade = strtok(NULL, ";");
        char *fone = strtok(NULL, ";");
        
        if (cnpj && razao && cidade && fone) {
            strncpy(c->CNPJ, cnpj, 14); c->CNPJ[14] = '\0';
            strncpy(c->RazaoSocial, razao, 49); c->RazaoSocial[49] = '\0';
            strncpy(c->Cidade, cidade, 29); c->Cidade[29] = '\0';
            strncpy(c->Fone, fone, 11); c->Fone[11] = '\0';
            insereServicoFim(desc, c);
        } else {
            free(c);
        }
    }
    fclose(file);
    printf("Dados de Servicos carregados.\n");
}

// apagar as listas

void apagarListaIndustria(TNoI **inicio){
    TNoI *aux = *inicio;
    while(aux){
        TNoI *prox = aux -> Prox;
        free(aux -> Dados);
        free(aux);
        aux = prox;
    }
    *inicio = NULL;
}

void apagarListaComercio(TNoC **inicio){
    TNoC *aux = *inicio;
    while (aux){
        TNoC *prox = aux -> Prox;
        free(aux -> Dados);
        free(aux);
        aux = prox;
    }
    *inicio = NULL;
}

void apagarListaServico(TDescritorS *desc){
    TNoS *aux = desc -> Inicio;
    while(aux){
        TNoS *prox = aux -> Prox;
        free(aux -> Dados);
        free(aux);
        aux = prox;
    }

    desc -> Inicio = NULL;
    desc -> Fim = NULL;
    desc -> Tamanho = 0;
}

void apagarListaUnificada(TDescritorU *desc) {
    TNoU *aux = desc->Inicio;
    while (aux) {
        TNoU *prox = aux->Prox;
        free(aux->Dados);
        free(aux);
        aux = prox;
    }
    desc->Inicio = NULL;
    desc->Fim = NULL;
    desc->Tamanho = 0;
}

// gerar a lista unificada

void gerarListaUnificada(TNoI *ind, TNoC *com, TDescritorS *ser, TDescritorU *uni) {
    apagarListaUnificada(uni); // Limpa lista antiga se existir
    // 1. Copia Industria
    TNoI *auxI = ind;
    while (auxI) {
        TCadastroU *u = (TCadastroU*) malloc(sizeof(TCadastroU));
        strcpy(u->CNPJ, auxI->Dados->CNPJ);
        strcpy(u->RazaoSocial, auxI->Dados->RazaoSocial);
        strcpy(u->Cidade, auxI->Dados->Cidade);
        strcpy(u->Fone, auxI->Dados->Fone);
        u->Tipo = 'I';
        insereUnificadaFim(uni, u);
        auxI = auxI->Prox;
    }
    // 2. Copia Comercio
    TNoC *auxC = com;
    while (auxC) {
        TCadastroU *u = (TCadastroU*) malloc(sizeof(TCadastroU));
        strcpy(u->CNPJ, auxC->Dados->CNPJ);
        strcpy(u->RazaoSocial, auxC->Dados->RazaoSocial);
        strcpy(u->Cidade, auxC->Dados->Cidade);
        strcpy(u->Fone, auxC->Dados->Fone);
        u->Tipo = 'C';
        insereUnificadaFim(uni, u);
        auxC = auxC->Prox;
    }
    // 3. Copia Servico
    TNoS *auxS = ser->Inicio;
    while (auxS) {
        TCadastroU *u = (TCadastroU*) malloc(sizeof(TCadastroU));
        strcpy(u->CNPJ, auxS->Dados->CNPJ);
        strcpy(u->RazaoSocial, auxS->Dados->RazaoSocial);
        strcpy(u->Cidade, auxS->Dados->Cidade);
        strcpy(u->Fone, auxS->Dados->Fone);
        u->Tipo = 'S';
        insereUnificadaFim(uni, u);
        auxS = auxS->Prox;
    }
    printf("Lista unificada gerada com sucesso! (Total: %d registros).\n", uni->Tamanho);
}
// --- IMPRESSÃO DOS RELATÓRIOS ---
void imprimeCadastro(TCadastro *c) {
    printf("CNPJ: %-15s | Razao: %-25s | Cidade: %-15s | Fone: %-12s\n", 
           c->CNPJ, c->RazaoSocial, c->Cidade, c->Fone);
}
void imprimeCadastroU(TCadastroU *c) {
    printf("CNPJ: %-15s | Razao: %-25s | Cidade: %-15s | Fone: %-12s | Tipo: %c\n", 
           c->CNPJ, c->RazaoSocial, c->Cidade, c->Fone, c->Tipo);
}
void relatorioIndustria(TNoI *inicio) {
    printf("\n--- RELATORIO: INDUSTRIAS ---\n");
    if (!inicio) { printf("Lista vazia.\n"); return; }
    while (inicio) {
        imprimeCadastro(inicio->Dados);
        inicio = inicio->Prox;
    }
}
void relatorioComercio(TNoC *inicio) {
    printf("\n--- RELATORIO: COMERCIO ---\n");
    if (!inicio) { printf("Lista vazia.\n"); return; }
    while (inicio) {
        imprimeCadastro(inicio->Dados);
        inicio = inicio->Prox;
    }
}
void relatorioComercioInvertido(TNoC *inicio) {
    printf("\n--- RELATORIO: COMERCIO INVERTIDO ---\n");
    if (!inicio) { printf("Lista vazia.\n"); return; }
    TNoC *aux = inicio;
    while (aux->Prox) { aux = aux->Prox; } // Encontra o último
    while (aux) {
        imprimeCadastro(aux->Dados);
        aux = aux->Ant;
    }
}
void relatorioServico(TDescritorS *desc) {
    printf("\n--- RELATORIO: SERVICOS ---\n");
    if (!desc || !desc->Inicio) { printf("Lista vazia.\n"); return; }
    TNoS *aux = desc->Inicio;
    while (aux) {
        imprimeCadastro(aux->Dados);
        aux = aux->Prox;
    }
}
void relatorioServicoInvertido(TDescritorS *desc) {
    printf("\n--- RELATORIO: SERVICOS INVERTIDO ---\n");
    if (!desc || !desc->Fim) { printf("Lista vazia.\n"); return; }
    TNoS *aux = desc->Fim;
    while (aux) {
        imprimeCadastro(aux->Dados);
        aux = aux->Ant;
    }
}
void relatorioUnificada(TDescritorU *desc) {
    printf("\n--- RELATORIO: LISTA UNIFICADA ---\n");
    if (!desc || !desc->Inicio) { printf("Lista vazia.\n"); return; }
    TNoU *aux = desc->Inicio;
    while (aux) {
        imprimeCadastroU(aux->Dados);
        aux = aux->Prox;
    }
}
void relatorioUnificadaInvertido(TDescritorU *desc) {
    printf("\n--- RELATORIO: LISTA UNIFICADA INVERTIDA ---\n");
    if (!desc || !desc->Fim) { printf("Lista vazia.\n"); return; }
    TNoU *aux = desc->Fim;
    while (aux) {
        imprimeCadastroU(aux->Dados);
        aux = aux->Ant;
    }
}
int main(){

    int opcao = -1;

    // inicializar as estruturas locais

    TNoI *listaIndustria = NULL;
    TNoC *listaComercio = NULL;
    TDescritorS descritorServico;
    descritorServico.Inicio = NULL;
    descritorServico.Fim = NULL;
    descritorServico.Tamanho = 0;
    TDescritorU descritorUnificada;
    descritorUnificada.Inicio = NULL;
    descritorUnificada.Fim = NULL;
    descritorUnificada.Tamanho = 0;

    // chama a func que garante que os txt existem, se n tiver ela cria exemplos
    criarArquivosDeTeste();

    while (opcao != 0){
    printf("=== Secretaria da Fazenda do Distrito Federal ===\n");
    printf("1. Carregar dados de entrada\n");
    printf("2. Gerar Lista Unificada\n");
    printf("3. Relatorio: Industrias\n");
    printf("4. Relatorio: Comercio\n");
    printf("5. Relatorio: Comercio Invertida\n");
    printf("6. Relatorio: Servicos\n");
    printf("7. Relatorio: Servicos Invertida\n");
    printf("8. Relatorio: Lista Unificada\n");
    printf("9. Relatorio: Lista Unificada Invertida\n");
    printf("10. Apagar Listas\n");
    printf("0. Sair\n");
    printf("=== Secretaria da Fazenda do Distrito Federal ===\n");
    scanf(" %d", &opcao);

    switch(opcao){
        
        case 1:

            // prevencao de carregar dados sem limpar

            apagarListaIndustria(&listaIndustria);
            apagarListaComercio(&listaComercio);
            apagarListaServico(&descritorServico);

            // agora vai carregar

            carregarIndustria(&listaIndustria);
            carregarComercio(&listaComercio);
            carregarServico(&descritorServico);
            break;

        case 2:

            // chama a func de gerar a lista unificada

            gerarListaUnificada(listaIndustria, listaComercio, &descritorServico, &descritorUnificada);
            break;

        case 3:

            relatorioIndustria(listaIndustria);
            break;

        case 4:

            relatorioComercio(listaComercio);
            break;

        case 5:

            relatorioComercioInvertido(listaComercio);
            break;

        case 6:

            relatorioServico(&descritorServico);
            break;

        case 7:

            relatorioServicoInvertido(&descritorServico);
            break;

        case 8:

            relatorioUnificada(&descritorUnificada);
            break;

        case 9:

            relatorioUnificadaInvertido(&descritorUnificada);
            break;

        case 10:

            apagarListaIndustria(&listaIndustria);
            apagarListaComercio(&listaComercio);
            apagarListaServico(&descritorServico);
            apagarListaUnificada(&descritorUnificada);
            printf("Todas as listas foram apagadas com sucesso.\n");
            break;

        case 0:

            printf("Saindo...\n");
            apagarListaIndustria(&listaIndustria);
            apagarListaComercio(&listaComercio);
            apagarListaServico(&descritorServico);
            apagarListaUnificada(&descritorUnificada);
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}