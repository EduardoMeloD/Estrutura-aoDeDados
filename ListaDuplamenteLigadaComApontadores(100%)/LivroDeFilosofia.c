/****************************************************************** 
 * Nome: Lista duplamente encadeada                               *
 * Descricao: Implementacao de lista duplamente encadeada         *
 *            Esse codigo possui as principais operacoes da       *
 *            lista, como:                                        *
 *            criar lista,                                        *
 *            inserir elemento,                                   *
 *            remover elemento,                                   *
 *            buscar elemento,                                    *
 *            mostrar elementos,                                  *
 *            atualizar elementos,                                *
 *            excluir lista.                                      *
 * Autor: Eduardo De Melo                                         *
 * Ultima alteracao: 15/12/2024                                   *
 ******************************************************************/


/*Include das bibliotecas*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


/*Definicao da estrutura*/
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
} Livro;

typedef struct listaNo {
    Livro livro;
    struct listaNo *prox;
    struct listaNo *ant;
} ListaNo;

typedef struct lista {
    ListaNo *prim;
    ListaNo *ult;
} Lista;

/* Prototipação das funções */
Lista* criarLista();
int inverterLista(Lista*);
int inserirElemento(Lista*, Livro);
int inserirElementoID(Lista*, Livro, int);
int inserirElementoInicio(Lista*, Livro);
ListaNo* buscarElemento(Lista*, int);
int atualizarElemento(Lista*, int, Livro);
int removerElemento(Lista*, int);
Lista* excluirLista(Lista*);
void imprimirElementos(Lista*);
int tamanho(Lista*);
void salvarDados(Lista*, const char*);
void carregarDados(Lista*, const char*);

/* Função principal com menu de operações */
int main() {
    Lista *lista = criarLista();
    char nomeArquivo[] = "livro.txt";
    int opcao, busca;
    Livro novoLivro;
    
    carregarDados(lista, "livro");

    do {
        
        printf("\nMenu\n");
        printf("1. Inserir livro no final\n");
        printf("2. Inserir livro no inicio\n");
        printf("3. Inserir livro em uma posicao especifica\n");
        printf("4. Buscar livro\n");
        printf("5. Atualizar livro\n");
        printf("6. Remover livro\n");
        printf("7. Listar livros\n");
        printf("8. Tamanho da lista\n");
        printf("9. Excluir lista\n");
        printf("10. Inverter a lista\n");
        printf("11. Sair\n");
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
			inserirElemento(lista, novoLivro);
			salvarDados(lista, "livro");
			break;
		case 2:
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
			inserirElementoInicio(lista, novoLivro);
			salvarDados(lista, "livro");
			
			break;
		case 3:
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

			int posicao;
			printf("Digite a posicao onde inserir: ");
            scanf("%d", &posicao);
            inserirElementoID(lista, novoLivro, posicao);
            salvarDados(lista, "livro");
			
			break;

		case 4:
			printf("Digite o codigo do livro para buscar: ");
			scanf("%d", &busca);
			ListaNo *encontrado = buscarElemento(lista, busca);
			if (encontrado != NULL)
			{

				Livro livro = encontrado->livro;
				printf("Livro encontrado:\n");
				printf("Código do Livro: %d\n", livro.codigoLivro);
				printf("Nome do Autor: %s\n", livro.nomeAutor);
				printf("Nome do Livro: %s\n", livro.nomeLivro);
				printf("Ano de Lançamento: %d\n", livro.anoLancamento);
				printf("Número de Páginas: %d\n", livro.numeroDePaginas);
				printf("Editora: %s\n", livro.editora);
				printf("Quantidade: %d\n", livro.quantidade);
				printf("Preço: %.2f\n", livro.preco);
				printf("Edição: %s\n", livro.edicao);
				printf("Descrição: %s\n", livro.descricao);
				printf("Disponível: %c\n", livro.disponivel);
			}
			else
			{
				printf("Livro não encontrado.\n");
			}
			break;

		case 5:
			printf("Digite o codigo do livro para atualizar: ");
			scanf("%d", &busca);
			if (buscarElemento(lista, busca))
			{
				printf("Digite o novo preco: ");
				scanf("%f", &novoLivro.preco);
				atualizarElemento(lista, busca, novoLivro);
				printf("Livro atualizado com sucesso.\n");
			}
			else
			{
				printf("Livro nao encontrado.\n");
			}
			break;

		case 6:
			printf("Digite o codigo do livro para remover: ");
			scanf("%d", &busca);
			if (removerElemento(lista, busca))
			{
				printf("Livro removido com sucesso.\n");
			}
			else
			{
				printf("Livro nao encontrado.\n");
			}
			break;

		case 7:
			imprimirElementos(lista);
			break;

		case 8:
			printf("Tamanho da lista: %d\n", tamanho(lista));
			break;

		case 9:
			lista = excluirLista(lista);
			printf("Lista excluida.\n");
			lista = criarLista();
			break;
		case 10:
			inverterLista(lista);
			break;

		case 11:
			printf("Saindo...\n");
			salvarDados(lista, nomeArquivo);
			break;

		default:
			printf("Opção invalida! Tente novamente.\n");

		}
      } while (opcao != 11);
    	excluirLista(lista);
    	return 0;
    } 


/* Funções auxiliares e lógicas */

Lista* criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    if (nova == NULL) {
        printf("Sem espaço para criar lista\n");
        return NULL;
    }
    nova->prim = NULL;
    nova->ult = NULL;
    return nova;
}

int inverterLista(Lista *lista) {
    if (lista == NULL || lista->prim == NULL) {
        printf("A lista está vazia.\n");
        return 0;
    }

    ListaNo *p = lista->ult;  // Começa do último elemento
    printf("Lista invertida:\n");
    while (p != NULL) {
        // Exibe informações detalhadas de cada livro
        printf("Código do Livro: %d\n", p->livro.codigoLivro);
        printf("Nome do Livro: %s\n", p->livro.nomeLivro);
        printf("Autor: %s\n", p->livro.nomeAutor);
        printf("Ano de Lançamento: %d\n", p->livro.anoLancamento);
        printf("Número de Páginas: %d\n", p->livro.numeroDePaginas);
        printf("Editora: %s\n", p->livro.editora);
        printf("Quantidade: %d\n", p->livro.quantidade);
        printf("Preço: %.2f\n", p->livro.preco);
        printf("Edição: %s\n", p->livro.edicao);
        printf("Descrição: %s\n", p->livro.descricao);
        printf("Disponível: %c\n", p->livro.disponivel);
        printf("\n");
        p = p->ant;  // Move para o nó anterior
    }

    return 1;
}

int inserirElemento(Lista *lista, Livro novoLivro) {
    ListaNo *nova = (ListaNo*)malloc(sizeof(ListaNo));
    if (nova == NULL) {
 	
		return 0;
	}
	
    nova->livro = novoLivro;
    nova->prox = NULL;  
    nova->ant = lista->ult;

    if (lista->prim == NULL) {  
        lista->prim = nova;
        
    } else {
        lista->prim->prox = nova;
    }

    lista->ult = nova;
    return 1;
}

int inserirElementoInicio(Lista *lista, Livro novoLivro) {
    ListaNo *nova = (ListaNo*)malloc(sizeof(ListaNo));
    if (nova == NULL) return 0;
    nova->livro = novoLivro;
    nova->prox = lista->prim;
    nova->ant = NULL;

    if (lista->prim == NULL) {
        lista->ult = nova;
    } else {
        lista->prim->ant = nova;
    }

    lista->prim = nova;
    return 1;
}

int inserirElementoID(Lista *lista, Livro novoLivro, int posicao) {
    int i;
    ListaNo *nova = (ListaNo*)malloc(sizeof(ListaNo));
    if (nova == NULL) return 0;
    nova->livro = novoLivro;

    if (posicao == 0 || lista->prim == NULL) {
        return inserirElementoInicio(lista, novoLivro);
    } else {
        ListaNo *p = lista->prim;
        for (i = 0; p->prox != NULL && i < posicao - 1; i++)
            p = p->prox;

        nova->prox = p->prox;
        nova->ant = p;
        
        if (p->prox != NULL)
            p->prox->ant = nova;

        p->prox = nova;

        if (nova->prox == NULL)
            lista->ult = nova;
    }
    return 1;
}

ListaNo* buscarElemento(Lista *lista, int codigoLivro) {
    ListaNo *p = lista->prim;
    while (p != NULL) {
        if (p->livro.codigoLivro == codigoLivro) return p;
        p = p->prox;
    }
    return NULL;
}

int atualizarElemento(Lista *lista, int codigoLivro, Livro novoLivro) {
    ListaNo *p = buscarElemento(lista, codigoLivro);
    if (p != NULL) {
        p->livro = novoLivro;
        return 1;
    }
    return 0;
}

int removerElemento(Lista *lista, int codigoLivro) {
    if (lista->prim == NULL) return 0;

    ListaNo *p = lista->prim;

    if (p->livro.codigoLivro == codigoLivro) {
        lista->prim = p->prox;
        if (lista->prim != NULL) 
            lista->prim->ant = NULL;
        else  
            lista->ult = NULL;

        free(p);
        return 1;
    }

    while (p != NULL && p->livro.codigoLivro != codigoLivro) {
        p = p->prox;
    }

    if (p != NULL) {
        if (p->prox != NULL)
            p->prox->ant = p->ant;
        else 
            lista->ult = p->ant;

        p->ant->prox = p->prox;
        free(p);
        return 1;
    }

    return 0;
}

Lista* excluirLista(Lista *lista) {
    if (lista == NULL) return NULL;
    ListaNo *p = lista->prim;
    while (p != NULL) {
        ListaNo *aux = p;
        p = p->prox;
        free(aux);
    }
    free(lista);
    return NULL;
}

void imprimirElementos(Lista *lista) {
    if (lista == NULL || lista->prim == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    ListaNo *p = lista->prim;
    while (p != NULL) {
        printf("Codigo do Livro: %d\n", p->livro.codigoLivro);
        printf("Nome do Livro: %s\n", p->livro.nomeLivro);
        printf("Autor: %s\n", p->livro.nomeAutor);
        printf("Ano de Lancamento: %d\n", p->livro.anoLancamento);
        printf("Numero de Paginas: %d\n", p->livro.numeroDePaginas);
        printf("Editora: %s\n", p->livro.editora);
        printf("Quantidade: %d\n", p->livro.quantidade);
        printf("Preco: %.2f\n", p->livro.preco);
        printf("Edicao: %s\n", p->livro.edicao);
        printf("Descricao: %s\n", p->livro.descricao);
        printf("Disponivel: %c\n", p->livro.disponivel);
        printf("\n");
        p = p->prox;
    }
}

int tamanho(Lista *lista) {
    int tam = 0;
    ListaNo *p = lista->prim;
    while (p != NULL) {
        tam++;
        p = p->prox;
    }
    return tam;
}

void carregarDados(Lista *lista, const char *arquivo) {
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para leitura.\n");
        return;
    }

    Livro livro;
    while (fscanf(file, "%d", &livro.codigoLivro) == 1) { // Verifica se a leitura foi bem-sucedida
        fgetc(file);  // Limpa o buffer de nova linha
        fgets(livro.nomeAutor, sizeof(livro.nomeAutor), file);
        livro.nomeAutor[strcspn(livro.nomeAutor, "\n")] = 0; // Remove nova linha
        fgets(livro.nomeLivro, sizeof(livro.nomeLivro), file);
        livro.nomeLivro[strcspn(livro.nomeLivro, "\n")] = 0;
        fscanf(file, "%d %d", &livro.anoLancamento, &livro.numeroDePaginas);
        fgetc(file);
        fgets(livro.editora, sizeof(livro.editora), file);
        livro.editora[strcspn(livro.editora, "\n")] = 0;
        fscanf(file, "%d %f", &livro.quantidade, &livro.preco);
        fgetc(file);
        fgets(livro.edicao, sizeof(livro.edicao), file);
        livro.edicao[strcspn(livro.edicao, "\n")] = 0;
        fgets(livro.descricao, sizeof(livro.descricao), file);
        livro.descricao[strcspn(livro.descricao, "\n")] = 0;
        fscanf(file, " %c", &livro.disponivel);
        fgetc(file);

        inserirElemento(lista, livro); // Insere o livro na lista
    }

    fclose(file); // Fecha o arquivo após a leitura
}

// Função que salva os dados da lista em um arquivo
void salvarDados(Lista *lista, const char *arquivo) {
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }

    ListaNo *p = lista->prim;
    while (p != NULL) {
        Livro livro = p->livro;
        fprintf(file, "%d\n%s\n%s\n%d\n%d\n%s\n%d\n%.2f\n%s\n%s\n%c\n",
                livro.codigoLivro, livro.nomeAutor, livro.nomeLivro,
                livro.anoLancamento, livro.numeroDePaginas, livro.editora,
                livro.quantidade, livro.preco, livro.edicao, livro.descricao, livro.disponivel);
        p = p->prox; // Avança para o próximo nó
    }

    fclose(file); // Fecha o arquivo após a gravação
}