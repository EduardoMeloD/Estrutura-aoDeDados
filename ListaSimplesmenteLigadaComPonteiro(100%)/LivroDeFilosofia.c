#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa um Livro
typedef struct {
    int codigoLivro;         // C�digo identificador do livro
    char nomeAutor[100];     // Nome do autor do livro
    char nomeLivro[50];      // Nome do livro
    int anoLancamento;       // Ano de lan�amento do livro
    int numeroDePaginas;     // N�mero de p�ginas do livro
    char editora[50];        // Nome da editora do livro
    int quantidade;          // Quantidade de exemplares dispon�veis
    float preco;             // Pre�o do livro
    char edicao[50];         // Edi��o do livro
    char descricao[500];     // Descri��o do livro
    char disponivel;         // Disponibilidade ('S' para sim, 'N' para n�o)
} Livro;

typedef struct listaNo {
    Livro livro;
    struct listaNo *prox;
} ListaNo;

typedef struct lista {
    ListaNo *prim;
} Lista;

/* Prototipa��o das fun��es */
Lista* criarLista();
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

/* Fun��o principal com menu de opera��es */
int main() {
    Lista *lista = criarLista();
    char nomeArquivo[] = "livro.txt";
    carregarDados(lista, nomeArquivo);
    int opcao, busca;
    Livro novoLivro;
    

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
        printf("10. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
            case 2: 
            case 3: 
                printf("Digite o codigo do livro: ");
                scanf("%d", &novoLivro.codigoLivro);
                printf("Digite o nome do autor: ");
                scanf(" %[^\n]", novoLivro.nomeAutor);
                printf("Digite o nome do livro: ");
                scanf(" %[^\n]", novoLivro.nomeLivro);
                printf("Digite o ano de lan�amento: ");
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

                if (opcao == 1) inserirElemento(lista, novoLivro);
                else if (opcao == 2) inserirElementoInicio(lista, novoLivro);
                else {
                    int posicao;
                    printf("Digite a posicao onde inserir: ");
                    scanf("%d", &posicao);
                    inserirElementoID(lista, novoLivro, posicao);
                }
                break;

            case 4:
                printf("Digite o codigo do livro para buscar: ");
                scanf("%d", &busca);
                ListaNo *encontrado = buscarElemento(lista, busca);
                if (encontrado != NULL) {
			        
			        Livro livro = encontrado->livro;
			        printf("Livro encontrado:\n");
			        printf("C�digo do Livro: %d\n", livro.codigoLivro);
			        printf("Nome do Autor: %s\n", livro.nomeAutor);
			        printf("Nome do Livro: %s\n", livro.nomeLivro);
			        printf("Ano de Lan�amento: %d\n", livro.anoLancamento);
			        printf("N�mero de P�ginas: %d\n", livro.numeroDePaginas);
			        printf("Editora: %s\n", livro.editora);
			        printf("Quantidade: %d\n", livro.quantidade);
			        printf("Pre�o: %.2f\n", livro.preco);
			        printf("Edi��o: %s\n", livro.edicao);
			        printf("Descri��o: %s\n", livro.descricao);
			        printf("Dispon�vel: %c\n", livro.disponivel);
			    } else {
			        printf("Livro n�o encontrado.\n");
			    }
			    break;

            case 5:
                printf("Digite o codigo do livro para atualizar: ");
                scanf("%d", &busca);
                if (buscarElemento(lista, busca)) {
                    printf("Digite o novo preco: ");
                    scanf("%f", &novoLivro.preco);
                    atualizarElemento(lista, busca, novoLivro);
                    printf("Livro atualizado com sucesso.\n");
                } else {
                    printf("Livro nao encontrado.\n");
                }
                break;

            case 6:
                printf("Digite o codigo do livro para remover: ");
                scanf("%d", &busca);
                if (removerElemento(lista, busca)) {
                    printf("Livro removido com sucesso.\n");
                } else {
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
                printf("Saindo...\n");
                salvarDados(lista, nomeArquivo);
                break;

            default:
                printf("Op��o invalida! Tente novamente.\n");
                
        }
        
    } while (opcao != 10);

    excluirLista(lista);
    return 0;
}

Lista* criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    if (nova == NULL) {
        printf("Sem espa�o para criar lista\n");
        return NULL;
    }
    nova->prim = NULL;
    return nova;
}

int inserirElemento(Lista *lista, Livro novoLivro) {
    ListaNo *nova = (ListaNo*)malloc(sizeof(ListaNo));
    if (nova == NULL) return 0;
    nova->livro = novoLivro;
    nova->prox = NULL;

    if (lista->prim == NULL) {
        lista->prim = nova;  // Se a lista estiver vazia, o novo n� se torna o primeiro
    } else {
        ListaNo *p = lista->prim;
        while (p->prox != NULL) p = p->prox;  // Percorre at� o �ltimo n�
        p->prox = nova;  // Adiciona o novo n� no final
    }
    return 1;
}

int inserirElementoInicio(Lista *lista, Livro novoLivro) {
    ListaNo *nova = (ListaNo*)malloc(sizeof(ListaNo));
    if (nova == NULL) return 0;
    nova->livro = novoLivro;
    nova->prox = lista->prim;  // O novo n� aponta para o primeiro n� atual
    lista->prim = nova;  // O novo n� se torna o primeiro
    return 1;
}

int inserirElementoID(Lista *lista, Livro novoLivro, int posicao) {
	int i;
    ListaNo *nova = (ListaNo*)malloc(sizeof(ListaNo));
    if (nova == NULL) return 0;
    nova->livro = novoLivro;

    if (posicao == 0 || lista->prim == NULL) {
        nova->prox = lista->prim;  // Insere no in�cio
        lista->prim = nova;
    } else {
        ListaNo *p = lista->prim;
        for ( i = 0; p->prox != NULL && i < posicao - 1; i++) p = p->prox;
        nova->prox = p->prox;  // O novo n� aponta para o pr�ximo n�
        p->prox = nova;  // O n� anterior aponta para o novo n�
    }
    return 1;
}

ListaNo* buscarElemento(Lista *lista, int codigoLivro) {
    ListaNo *p = lista->prim;
    while (p != NULL) {
        if (p->livro.codigoLivro == codigoLivro) return p;  // Livro encontrado
        p = p->prox;  // Avan�a para o pr�ximo n�
    }
    return NULL;  // Livro n�o encontrado
}

int atualizarElemento(Lista *lista, int codigoLivro, Livro novoLivro) {
    ListaNo *p = buscarElemento(lista, codigoLivro);
    if (p != NULL) {
        // Atualiza todos os campos do livro encontrado
        p->livro = novoLivro;  
        return 1;  // Atualiza��o bem-sucedida
    }
    return 0;  // Livro n�o encontrado
}

int removerElemento(Lista *lista, int codigoLivro) {
    if (lista->prim == NULL) return 0;  // Lista vazia, nada para remover

    ListaNo *p = lista->prim;
    if (p->livro.codigoLivro == codigoLivro) {
        lista->prim = p->prox;  // Remove o primeiro n�
        free(p);
        return 1;  // Remo��o bem-sucedida
    }
    
    while (p->prox != NULL && p->prox->livro.codigoLivro != codigoLivro) {
        p = p->prox;  // Percorre at� encontrar o livro ou chegar ao final
    }
    if (p->prox != NULL) {
        ListaNo *aux = p->prox;  // N� a ser removido
        p->prox = aux->prox;  // Remove o n� da lista
        free(aux);
        return 1;  // Remo��o bem-sucedida
    }
    return 0;  // Livro n�o encontrado
}

Lista* excluirLista(Lista *lista) {
    if (lista == NULL) return NULL;  // Verifica se a lista j� � NULL
    ListaNo *p = lista->prim;
    while (p != NULL) {
        ListaNo *aux = p;
        p = p->prox;  // Avan�a para o pr�ximo n�
        free(aux);  // Libera a mem�ria do n� atual
    }
    free(lista);  // Libera a mem�ria da lista
    return NULL;  // Retorna NULL para indicar que a lista foi exclu�da
}

void imprimirElementos(Lista *lista) {
    if (lista == NULL || lista->prim == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    ListaNo *p = lista->prim;
    while (p != NULL) {
        // Exibe informa��es detalhadas de cada livro
        printf("C�digo do Livro: %d\n", p->livro.codigoLivro);
        printf("Nome do Livro: %s\n", p->livro.nomeLivro);
        printf("Autor: %s\n", p->livro.nomeAutor);
        printf("Ano de Lan�amento: %d\n", p->livro.anoLancamento);
        printf("N�mero de P�ginas: %d\n", p->livro.numeroDePaginas);
        printf("Editora: %s\n", p->livro.editora);
        printf("Quantidade: %d\n", p->livro.quantidade);
        printf("Pre�o: %.2f\n", p->livro.preco);
        printf("Edi��o: %s\n", p->livro.edicao);
        printf("Descri��o: %s\n", p->livro.descricao);
        printf("Dispon�vel: %c\n", p->livro.disponivel);
        printf("\n");  // Espa�o entre livros
        p = p->prox;  // Avan�a para o pr�ximo n�
    }
}

int tamanho(Lista *lista) {
    int tam = 0;
    ListaNo *p = lista->prim;
    while (p != NULL) {
        tam++;  // Conta os n�s na lista
        p = p->prox;  // Avan�a para o pr�ximo n�
    }
    return tam;  // Retorna o tamanho da lista
}

// Fun��o que carrega os dados da lista a partir de um arquivo
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
        livro.nomeAutor[strcspn(livro.nomeAutor, "\n")] = 0;  // Remove nova linha
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

        inserirElemento(lista, livro);  // Insere o livro na lista
    }

    fclose(file);  // Fecha o arquivo ap�s a leitura
}

// Fun��o que salva os dados da lista em um arquivo
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
        p = p->prox;  // Avan�a para o pr�ximo n�
    }

    fclose(file);  // Fecha o arquivo ap�s a grava��o
}