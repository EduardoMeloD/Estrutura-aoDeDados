#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5 // Define o tamanho máximo da lista de livros

// Estrutura que representa um Livro
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

// Estrutura que representa uma Lista de livros
typedef struct {
    int id;             // Número atual de livros na lista
    Livro *elementos;    // Array dinâmico de livros
} Lista;

// Funções para manipulação da lista de livros
Lista* criarLista(); // Cria uma nova lista de livros
int inserirElemento(Lista*, Livro); // Insere um livro no final da lista
int inserirElementoID(Lista*, Livro, int); // Insere um livro em uma posição específica da lista
int inserirElementoInicio(Lista*, Livro); // Insere um livro no início da lista
int removerElemento(Lista*, int); // Remove um livro da lista com base na posição
int atualizarElemento(Lista*, int, Livro); // Atualiza os dados de um livro na lista
int buscarElemento(Lista*, int); // Busca um livro na lista pelo código
int tamanho(Lista*); // Retorna o tamanho atual da lista
void excluirLista(Lista*); // Libera a memória e exclui a lista
void carregarDados(Lista*, const char*); // Carrega dados de livros a partir de um arquivo
void salvarDados(Lista*, const char*); // Salva os dados da lista em um arquivo
void listarElementos(Lista*); // Lista todos os livros presentes na lista

// Função principal
int main() {
    // Cria uma nova lista de livros
    Lista *lista = criarLista();

    // Cria alguns livros para inserir na lista inicialmente
    Livro livro1 = {1, "Julio Verne", "A Jornada ao Centro da Terra", 1864, 360, "Editora Globo", 15, 89.90, "3a Edicao", "Um dos maiores classicos da literatura de aventura, com uma viagem epica ao interior da Terra.", 'S'};
    Livro livro2 = {2, "H. G. Wells", "A Maquina do Tempo", 1895, 288, "Companhia das Letras", 8, 74.50, "2a Edicao", "Obra visionaria que apresenta um dos primeiros relatos de viagem no tempo.", 'S'};
    Livro livro3 = {3, "George Orwell", "1984", 1949, 328, "Companhia das Letras", 20, 59.90, "1a Edicao", "Uma distopia classica que explora temas de vigilancia, totalitarismo e controle social.", 'S'};

    // Insere os livros na lista
    inserirElementoInicio(lista, livro1); // Insere o primeiro livro no início da lista
    inserirElementoID(lista, livro2, 1);  // Insere o segundo livro na posição 1
    inserirElemento(lista, livro3);       // Insere o terceiro livro no final da lista

    // Exibe os livros iniciais da lista
    printf("\n--- Livros Iniciais ---\n");
    listarElementos(lista); // Lista todos os livros
    printf("Tamanho da lista: %d\n", tamanho(lista)); // Exibe o tamanho da lista

    // Permite ao usuário adicionar um novo livro
    Livro novoLivro;
    printf("\n--- Adicione um novo livro ---\n");
    printf("Codigo: ");
    scanf("%d", &novoLivro.codigoLivro);
    printf("Nome do autor: ");
    scanf(" %[^\n]s", novoLivro.nomeAutor);
    printf("Nome do livro: ");
    scanf(" %[^\n]s", novoLivro.nomeLivro);
    printf("Ano de lancamento: ");
    scanf("%d", &novoLivro.anoLancamento);
    printf("Numero de paginas: ");
    scanf("%d", &novoLivro.numeroDePaginas);
    printf("Editora: ");
    scanf(" %[^\n]s", novoLivro.editora);
    printf("Quantidade: ");
    scanf("%d", &novoLivro.quantidade);
    printf("Preco: ");
    scanf("%f", &novoLivro.preco);
    printf("Edicao: ");
    scanf(" %[^\n]s", novoLivro.edicao);
    printf("Descricao: ");
    scanf(" %[^\n]s", novoLivro.descricao);
    printf("Disponivel (S/N): ");
    scanf(" %c", &novoLivro.disponivel);

    // Insere o novo livro na lista
    inserirElemento(lista, novoLivro);

    // Exibe a lista atualizada após a inserção do novo livro
    printf("\n--- Lista atualizada apos adicionar novo livro ---\n");
    listarElementos(lista);
    printf("Tamanho da lista: %d\n", tamanho(lista));

    // Atualização dos dados de um livro existente
    int codigoAtualizar;
    Livro livroAtualizado;
    printf("\n--- Atualize os dados de um livro ---\n");
    printf("Digite o codigo do livro a atualizar: ");
    scanf("%d", &codigoAtualizar);

    printf("Novo Codigo: ");
    scanf("%d", &livroAtualizado.codigoLivro);
    printf("Novo Nome do autor: ");
    scanf(" %[^\n]s", livroAtualizado.nomeAutor);
    printf("Novo Nome do livro: ");
    scanf(" %[^\n]s", livroAtualizado.nomeLivro);
    printf("Novo Ano de lancamento: ");
    scanf("%d", &livroAtualizado.anoLancamento);
    printf("Novo Numero de paginas: ");
    scanf("%d", &livroAtualizado.numeroDePaginas);
    printf("Nova Editora: ");
    scanf(" %[^\n]s", livroAtualizado.editora);
    printf("Nova Quantidade: ");
    scanf("%d", &livroAtualizado.quantidade);
    printf("Novo Preco: ");
    scanf("%f", &livroAtualizado.preco);
    printf("Nova Edicao: ");
    scanf(" %[^\n]s", livroAtualizado.edicao);
    printf("Nova Descricao: ");
    scanf(" %[^\n]s", livroAtualizado.descricao);
    printf("Novo Disponivel (S/N): ");
    scanf(" %c", &livroAtualizado.disponivel);

    // Atualiza os dados do livro
    if (atualizarElemento(lista, codigoAtualizar, livroAtualizado)) {
        printf("Livro atualizado com sucesso!\n");
        listarElementos(lista); // Lista os livros após a atualização
    } else {
        printf("Erro ao atualizar livro.\n");
    }

    // Busca um livro pelo código
    int codigoBuscar;
    printf("\n--- Busque um livro pelo codigo ---\n");
    printf("Digite o codigo do livro a buscar: ");
    scanf("%d", &codigoBuscar);

    int posicao = buscarElemento(lista, codigoBuscar); // Busca o livro
    if (posicao == -1) {
        printf("Livro nao encontrado.\n");
    } else {
        Livro livro = lista->elementos[posicao]; // Recupera os dados do livro encontrado
        printf("\n--- Detalhes do Livro Encontrado ---\n");
        printf("Codigo do Livro: %d\n", livro.codigoLivro);
        printf("Nome do Autor: %s\n", livro.nomeAutor);
        printf("Nome do Livro: %s\n", livro.nomeLivro);
        printf("Ano de Lancamento: %d\n", livro.anoLancamento);
        printf("Numero de Paginas: %d\n", livro.numeroDePaginas);
        printf("Editora: %s\n", livro.editora);
        printf("Disponivel: %c\n", livro.disponivel);
        printf("Quantidade: %d\n", livro.quantidade);
        printf("Preco: %.2f\n", livro.preco);
        printf("Edicao: %s\n", livro.edicao);
        printf("Descricao: %s\n", livro.descricao);
    }

    // Remove um livro da lista pelo código
    int codigoRemover;
    printf("\n--- Remova um livro pelo codigo ---\n");
    printf("Digite o codigo do livro a remover: ");
    scanf("%d", &codigoRemover);

    if (removerElemento(lista, codigoRemover)) {
        printf("Livro removido com sucesso!\n");
        listarElementos(lista); // Lista os livros após a remoção
        printf("Tamanho da lista: %d\n", tamanho(lista));
    } else {
        printf("Erro ao remover livro.\n");
    }

    // Exclui a lista e libera a memória
    printf("\n--- Excluindo a lista ---\n");
    excluirLista(lista); // Libera a memória alocada
   // Finaliza o programa
    printf("Programa encerrado.\n");

    return 0;
}

//funçao para criar uma lista vazia de livros
Lista* criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    nova->id = 0;
    nova->elementos = (Livro*)malloc(TAM * sizeof(Livro));
    return nova;
}

//funçao para inserir um elemento no final da lista
int inserirElemento(Lista *lista, Livro livro) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return 0;
    }
    if (lista->id < TAM) {
        lista->elementos[lista->id] = livro;
        lista->id++;
        return 1;
    } else {
        printf("Sem espaco na lista\n");
        return 0;
    }
}

//funçao para inserir um elemento em uma posicçao especifica da lista
int inserirElementoID(Lista *lista, Livro livro, int posicaoLivro) {
    int i;
    if (lista == NULL) {
        printf("Lista vazia\n");
        return 0;
    }
    if (lista->id >= TAM) {
        printf("Lista cheia\n");
        return 0;
    }
    if (posicaoLivro < 0 || posicaoLivro > lista->id) {
        printf("Posicao invalida\n");
        return 0;
    }

    for (i = lista->id; i > posicaoLivro; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }

    lista->elementos[posicaoLivro] = livro;
    lista->id++;
    return 1;
}

//funçao para inserir um elemento no inicio da lista
int inserirElementoInicio(Lista *lista, Livro livro) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return 0;
    } else {
        return inserirElementoID(lista, livro, 0);
    }
}

//funçao para listar todos os elementos da lista
void listarElementos(Lista *lista) {
    int i;
    if (lista == NULL) {
        printf("Lista vazia\n");
        return;
    }

    for (i = 0; i < lista->id; i++) {
        Livro livro = lista->elementos[i];
        printf("Codigo do Livro: %d\n", livro.codigoLivro);
        printf("Nome do Autor: %s\n", livro.nomeAutor);
        printf("Nome do Livro: %s\n", livro.nomeLivro);
        printf("Ano de Lancamento: %d\n", livro.anoLancamento);
        printf("Numero de Paginas: %d\n", livro.numeroDePaginas);
        printf("Editora: %s\n", livro.editora);
        printf("Disponivel: %c\n", livro.disponivel);
        printf("Quantidade: %d\n", livro.quantidade);
        printf("Preco: %.2f\n", livro.preco);
        printf("Edicao: %s\n", livro.edicao);
        printf("Descricao: %s\n", livro.descricao);
        printf("\n");
    }
}

//funçao para remover os elementos de uma lista
int removerElemento(Lista *lista, int posicao) {
    int i;
    if (lista == NULL) {
        printf("Lista vazia\n");
        return 0;
    }
    if (lista->id == 0 || posicao < 0 || posicao >= lista->id) {
        printf("Posicao invalida\n");
        return 0;
    }

    for (i = posicao; i < lista->id - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->id--;
    return 1;
}

//atualiza os elementos de uma lista com novos dados
int atualizarElemento(Lista *lista, int posicao, Livro novoLivro) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return 0;
    }

    if (posicao < 0 || posicao >= lista->id) {
        printf("Posicao invalida\n");
        return 0;
    }

    lista->elementos[posicao] = novoLivro;
    return 1;
}

//busca dentro da lista de livros um elemento especifico
int buscarElemento(Lista *lista, int codigo) {
    int i;
    for (i = 0; i < lista->id; i++) {
        if (lista->elementos[i].codigoLivro == codigo) {
            return 1;
        }
    }
    printf("Livro nao encontrado\n");
    return -1;
}

//mostra o tamanho da lista
int tamanho(Lista *lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return 0;
    }
    return lista->id;
}

//apaga a lista de livros
void excluirLista(Lista *lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return;
    }
    free(lista->elementos);
    free(lista);
}

//funçao que pegas os dados da lista de um arquivo
void carregarDados(Lista *lista, const char *arquivo) {
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (!feof(file)) {
        Livro livro;
        fscanf(file, "%d %s %s %d %d %s %d %f %s %s %c",
               &livro.codigoLivro, livro.nomeAutor, livro.nomeLivro,
               &livro.anoLancamento, &livro.numeroDePaginas, livro.editora,
               &livro.quantidade, &livro.preco, livro.edicao, livro.descricao, &livro.disponivel);
        inserirElemento(lista, livro);
    }

    fclose(file);
}

//funçao que salvo dos dados da lista em um arquivo
void salvarDados(Lista *lista, const char *arquivo) {
    int i;
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    for (i = 0; i < lista->id; i++) {
        Livro livro = lista->elementos[i];
        fprintf(file, "%d %s %s %d %d %s %d %.2f %s %s %c\n",
                livro.codigoLivro, livro.nomeAutor, livro.nomeLivro,
                livro.anoLancamento, livro.numeroDePaginas, livro.editora,
                livro.quantidade, livro.preco, livro.edicao, livro.descricao, livro.disponivel);
    }

    fclose(file);
}