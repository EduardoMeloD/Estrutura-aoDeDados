/******************************************************************
 * Nome: Pilha com apontadores                                    *
 * Descrição: Implementação de uma pilha com apontadores          *
 *            para manipulação de Livro. Este código              *
 *            inclui as principais operações da lista, como:      * 
 * 			  push                                                *
 * 			  pop                                                 *
 *            verTopo                                             *
 * 			  ehVazia	                                          *      
 *                                                                *
 * Autor: Eduardo de Melo domingos                                *
 * Última alteração: 14/12/2024                                   *     
 *                                                                *
 * Autor: Eduardo de Melo                                         *                     
 ******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Definição da estrutura Livro */
typedef struct Livro{
    int codigoLivro;         // Código identificador do livro
    char nomeAutor[100];     // Nome do autor do livro
    char nomeLivro[50];      // Nome do livro
    int anoLancamento;       // Ano de lançamento do livro
    int numeroDePaginas;     // Número de páginas do livro
    char editora[50];        // Nome da editora do livro
    int quantidade;          // Quantidade de exemplares disponíveis
    float preco;             // Preço do livro
    char edicao[50];         // Edição do livro
    char descricao[500];     // Descrição do livro
    char disponivel;         // Disponibilidade ('S' para sim, 'N' para não)
    struct Livro *prox;
} Livro;

/* Definição da estrutura Pilha */
typedef struct {
    Livro *topo;
} Pilha;

/* Declaração de funções */
Pilha* criarPilha();
int ehVazia(Pilha* pilha);
int push(Pilha* pilha, Livro novoLivro);
void verTopo(Pilha* pilha);
int pop(Pilha* pilha);
void excluirPilha(Pilha* pilha);
void salvarDados(Pilha* pilha, const char* arquivo);
void carregarDados(Pilha* pilha, const char* arquivo);

/* Função principal com menu de operações */
int main() {
    Pilha* pilha = criarPilha();
    char nomeArquivo[] = "livro.txt";
    int opcao;
    Livro novoLivro;

    carregarDados(pilha, nomeArquivo);

    do {
        printf("\nMenu\n");
        printf("1. Inserir livro\n");
        printf("2. Remover livro\n");
        printf("3. Ver topo da pilha\n");
        printf("4. Excluir pilha\n");
        printf("5. Verificar se é vazia\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o codigo do livro: ");
                scanf("%d", &novoLivro.codigoLivro);
                printf("Digite o nome do autor: ");
                scanf(" %[^\n]", novoLivro.nomeAutor);
                printf("Digite o nome do livro: ");
                scanf(" %[^\n]", novoLivro.nomeLivro);
                printf("Digite o ano de lançamento: ");
                scanf("%d", &novoLivro.anoLancamento);
                printf("Digite o numero de paginas: ");
                scanf("%d", &novoLivro.numeroDePaginas);
                printf("Digite a editora: ");
                scanf(" %[^\n]", novoLivro.editora);
                printf("Digite a quantidade: ");
                scanf("%d", &novoLivro.quantidade);
                printf("Digite o preco: ");
                scanf("%f", &novoLivro.preco);
                printf("Digite a edicao: ");
                scanf(" %[^\n]", novoLivro.edicao);
                printf("Digite a descricao: ");
                scanf(" %[^\n]", novoLivro.descricao);
                printf("Disponivel (S/N): ");
                scanf(" %c", &novoLivro.disponivel);

                if (push(pilha, novoLivro)) {
                    salvarDados(pilha, nomeArquivo);
                    printf("Livro inserido com sucesso!\n");
                } else {
                    printf("Erro ao inserir livro. Pilha cheia.\n");
                }
                break;

            case 2:
                if (pop(pilha)) {
                    salvarDados(pilha, nomeArquivo);
                    printf("Livro removido com sucesso!\n");
                } else {
                    printf("Erro ao remover livro. Pilha vazia.\n");
                }
                break;

            case 3:
                verTopo(pilha);
                break;

            case 4:
                excluirPilha(pilha);
                pilha = criarPilha();
                salvarDados(pilha, nomeArquivo);
                printf("Pilha excluida com sucesso!\n");
                break;

            case 5:
                if (ehVazia(pilha)) {
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("A pilha nao esta vazia.\n");
                }
                break;

            case 6:
                printf("Saindo...\n");
                salvarDados(pilha, nomeArquivo);
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);

    excluirPilha(pilha);
    return 0;
}

/* Implementação das funções */
Pilha* criarPilha() {
    Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));
    if (novaPilha == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }
    novaPilha->topo = NULL;
    return novaPilha;
}

int ehVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

int push(Pilha *pilha, Livro novoLivro) {
    if (pilha == NULL) {
        printf("A pilha nao foi criada.\n");
        return 0; // Pilha inexistente
    }
    
    // Aloca espaço para o novo livro
    Livro *novoEspaco = (Livro *)malloc(sizeof(Livro));
    if (novoEspaco == NULL) {
        printf("Erro na alocação de memória para novo livro.\n");
        return 0; // Erro na alocação
    }
    
    // Copia os dados do livro para o novo espaço alocado
    novoEspaco->codigoLivro = novoLivro.codigoLivro;
    strcpy(novoEspaco->nomeAutor, novoLivro.nomeAutor);
    strcpy(novoEspaco->nomeLivro, novoLivro.nomeLivro);
    novoEspaco->anoLancamento = novoLivro.anoLancamento;
    novoEspaco->numeroDePaginas = novoLivro.numeroDePaginas;
    strcpy(novoEspaco->editora, novoLivro.editora);
    novoEspaco->quantidade = novoLivro.quantidade;
    novoEspaco->preco = novoLivro.preco;
    strcpy(novoEspaco->edicao, novoLivro.edicao);
    strcpy(novoEspaco->descricao, novoLivro.descricao);
    novoEspaco->disponivel = novoLivro.disponivel;

    // Insere o novo livro no topo da pilha
    novoEspaco->prox = pilha->topo;
    pilha->topo = novoEspaco;

    return 1;
}

void verTopo(Pilha* pilha) {
    if (ehVazia(pilha)) {
        printf("Pilha vazia.\n");
    } else {
        Livro *topo = pilha->topo;
        printf("Livro no topo: %s (%d)\n", topo->nomeAutor, topo->codigoLivro);
    }
}

int pop(Pilha* pilha) {
	
	if(pilha == NULL){
		printf("a pilha nao foi criada amigo");
		return 0;
	}
    if (ehVazia(pilha)) {
        return 0; // Pilha vazia
    }
    Livro *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
    printf("livro removido!");
    return 1;
}

void excluirPilha(Pilha* pilha) {
    free(pilha);
}

void salvarDados(Pilha* pilha, const char* arquivo) {
    Livro *temp = pilha->topo;

    FILE* file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }

    while (temp != NULL) {
        // Escreve os dados do livro no arquivo
        fprintf(file, "%d|%s|%s|%d|%d|%s|%d|%.2f|%s|%s|%c\n",
                temp->codigoLivro,
                temp->nomeAutor,
                temp->nomeLivro,
                temp->anoLancamento,
                temp->numeroDePaginas,
                temp->editora,
                temp->quantidade,
                temp->preco,
                temp->edicao,
                temp->descricao,
                temp->disponivel);
                
        temp = temp->prox; // Avança para o próximo elemento
    }

    fclose(file);
}

void carregarDados(Pilha* pilha, const char* arquivo) {
    FILE* file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para leitura.\n");
        return;
    }
    while (!feof(file)) {
        Livro livro;
        fscanf(file, "%d %[^\n] %[^\n] %d %d %[^\n] %d %f %[^\n] %[^\n] %c",
               &livro.codigoLivro, livro.nomeAutor, livro.nomeLivro,
               &livro.anoLancamento, &livro.numeroDePaginas, livro.editora,
               &livro.quantidade, &livro.preco, livro.edicao, livro.descricao, &livro.disponivel);
        push(pilha, livro);
    }
    fclose(file);
}