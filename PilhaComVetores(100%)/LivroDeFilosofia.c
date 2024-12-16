/******************************************************************
 * Nome: Pilha com vetores                                        *
 * Descrição: Implementação de uma pilha com vetores              *
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

#define TAM 100 // Tamanho máximo da pilha

/* Definição da estrutura Livro */
typedef struct {
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
} Livro;

/* Definição da estrutura Pilha */
typedef struct {
    int topo;
    Livro elementos[TAM];
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
    novaPilha->topo = 0;
    return novaPilha;
}

int ehVazia(Pilha* pilha) {
    return pilha->topo == 0;
}

//push:funcao para implementar um elemento no topo da pilha
int push(Pilha* pilha, Livro novoLivro) {
    if (pilha->topo >= TAM) {
        return 0; // Pilha cheia
    }
    pilha->elementos[pilha->topo++] = novoLivro;
    return 1;
}

//ver topo:funcao para poder ver o elemento no topo da pilha
void verTopo(Pilha* pilha) {
    if (ehVazia(pilha)) {
        printf("Pilha vazia.\n");
    } else {
        Livro topo = pilha->elementos[pilha->topo - 1];
        printf("Livro no topo: %s (%d)\n", topo.nomeLivro, topo.codigoLivro);
    }
}

//pop:funcao para remover um elemento da pilha
int pop(Pilha* pilha) {
    if (ehVazia(pilha)) {
        return 0; // Pilha vazia
    }
    pilha->topo--;
    return 1;
}

//excluir pilha: funcao para exlcuir a pilha
void excluirPilha(Pilha* pilha) {
    free(pilha);
}

//salvar dados: funcao para salvar dados
void salvarDados(Pilha* pilha, const char* arquivo) {
	int i;
	
    FILE* file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }
    for (i = 0; i < pilha->topo; i++) {
        Livro livro = pilha->elementos[i];
        fprintf(file, "%d %s %s %d %d %s %d %.2f %s %s %c\n",
                livro.codigoLivro, livro.nomeAutor, livro.nomeLivro,
                livro.anoLancamento, livro.numeroDePaginas, livro.editora,
                livro.quantidade, livro.preco, livro.edicao, livro.descricao, livro.disponivel);
    }
    fclose(file);
}

//carregar dados: funcao para carregar dados
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