/****************************************************************** 
 * Nome: Lista Cirucular                                          *
 * Descricao: Implementacao de lista Circular                     *
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
 * Ultima alteracao: 08/12/2024                                   *
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
    struct Livro *prox;
} Livro;

/* Estrutura que representa a lista, com um ponteiro para o primeiro elemento */
typedef struct {
	Livro *inicio;          //Ponteiro para o primeiro livro da lista
}Lista;



/* Nome: BuscarElemento
 * Retorno: o retorno e vazio
 * Descricao: Funcao criada para buscar um livro na lista
 */
Livro* BuscarElemento(Lista *lista, int codigoLivro){
	if(lista == NULL){
        printf("A lista nao foi criada\n");
        return NULL;
    }
	
	if(lista->inicio == NULL){
		printf("\n A lista esta vazia\n");
		return NULL;
	}
	
	Livro *temp = lista->inicio; 
	
	do{
		if(temp->codigoLivro == codigoLivro){
			return temp;
		}
		temp = temp->prox;
	}while(temp != lista->inicio);
	
	return NULL; //livro nao encontrado
}


/* Nome: AtualizarLivro
 * Descricao: Funcao responsavel por atualizar um livro
 *            da lista, caso o mesmo esteja na lista indicada
 */
int AtualizarLivro(Lista *lista, int codigoLivro){
	Livro *livro = BuscarElemento(lista, codigoLivro);  //Busca o livro pelo seu codigo
	
	if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
	
	 //Se o livro foi encontrado
	if (livro != NULL) {
        printf("Digite o codigo do livro: ");
			    scanf("%d", &livro->codigoLivro);
			    printf("Digite o nome do autor: ");
			    scanf(" %[^\n]", livro->nomeAutor);
			    printf("Digite o nome do livro: ");
			    scanf(" %[^\n]", livro->nomeLivro);
			    printf("Digite o ano de lancamento: ");
			    scanf("%d", &livro->anoLancamento);
			    printf("Digite o numero de paginas: ");
			    scanf("%d", &livro->numeroDePaginas);
			    printf("Digite a editora: ");
			    scanf(" %[^\n]", livro->editora);
			    printf("Digite a quantidade: ");
			    scanf("%d", &livro->quantidade);
			    printf("Digite o preco: ");
			    scanf("%f", &livro->preco);
			    printf("Digite a edicao: ");
			    scanf(" %[^\n]", livro->edicao);
			    printf("Digite a descricao: ");
			    scanf(" %[^\n]", livro->descricao);
			    printf("Disponivel (S/N): ");
			    scanf(" %c", &livro->disponivel);
        return 1;
    } 
	
	//Se o livro nao foi encontrado
	else {
        printf("\n livro nao foi encontrado!\n");
        return 0;
    }
}


/* Nome: CriarLivro
 * Retorno: retorna um ponteiro para um novo livro alocado dinamicamente
 * Descricao: Cria um novo livro com os atributos fornecidos e retorna
 *            um ponteiro para ele.
 */
Livro* criarLivro(int codigoLivro, char *nomeAutor, char *nomeLivro, int anoLancamento, int numeroDepaginas, char *editora, int quantidade, float preco, char *edicao, char *descricao, char disponivel){
	Livro *novo = (Livro*)malloc(sizeof(Livro)); //Aloca memoria para um novo livro
	novo->codigoLivro = codigoLivro;
	strcpy(novo->nomeAutor, nomeAutor); //Define os atributos do livro
	strcpy(novo->nomeLivro, nomeLivro);
	novo->anoLancamento = anoLancamento;
	novo->numeroDePaginas = numeroDepaginas;
	strcpy(novo->editora, editora);
	novo->quantidade = quantidade;
	strcpy(novo->edicao, edicao);
	strcpy(novo->descricao, descricao);
	novo->disponivel = disponivel;
	novo->prox = NULL; //Inicializa o proximo elemento como NULL 
	return novo;
}


/* Nome: InserirElemento
 * Descricao: Insere um novo livro no final da lista. Caso a lista esteja vazia,
 *            o novo livro sera o primeiro elemento. Caso contrario, ele sera 
 *            inserido no final.
 */
int InserirElemento(Lista *lista, Livro *novo) {
    if (lista == NULL) {
        printf("A lista não foi criada\n");
        return 0;
    }

    if (novo == NULL) {
        printf("Informações inválidas\n");
        return 0;
    }

    // Aloca memória para o novo livro
    Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
    if (novoLivro == NULL) {
        printf("Erro ao alocar memória para o novo livro\n");
        return 0;
    }

    // Copia os dados do Livro para o novo Livro alocado
    novoLivro->codigoLivro = novo->codigoLivro;
    strcpy(novoLivro->nomeAutor, novo->nomeAutor);
    strcpy(novoLivro->nomeLivro, novo->nomeLivro);
    novoLivro->anoLancamento = novo->anoLancamento;
    novoLivro->numeroDePaginas = novo->numeroDePaginas;
    strcpy(novoLivro->editora, novo->editora);
    novoLivro->quantidade = novo->quantidade;
    strcpy(novoLivro->edicao, novo->edicao);
    strcpy(novoLivro->descricao, novo->descricao);

    // Caso a lista esteja vazia, o novo livro será o primeiro elemento
    if (lista->inicio == NULL) {
        lista->inicio = novoLivro;
        novoLivro->prox = novoLivro; // Aponta para si mesmo, criando a lista circular
        return 1;
    }

    // Caso contrário, insere no final da lista
    Livro *temp = lista->inicio;
    while (temp->prox != lista->inicio) {
        temp = temp->prox;
    }

    temp->prox = novoLivro;          // Último elemento aponta para o novo
    novoLivro->prox = lista->inicio; // Novo elemento aponta para o início, mantendo a circularidade

    return 1;
}


/* Nome: ExcluirLista
 * Descricao: Exclui todos os livros da lista, liberando a memoria alocada
 *            e redefinindo o ponteiro de inicio para NULL.
 */
Lista* ExcluirLista(Lista *lista){
	if(lista == NULL){
        printf("A lista nao foi criada\n");
        return NULL;
    }
	
	if(lista->inicio == NULL){
		printf("\n Lista Vazia!\n");
		return NULL;
	}
	
	Livro *temp = lista->inicio;
	Livro *prox;
	
	do{
		prox = temp->prox;
		free(temp);
		temp = prox;
	}while(temp != lista->inicio);
	
	lista->inicio = NULL; 
	
	return NULL;	
}


/* Nome: carregarDados
 * Descricao: Carrega os dados dos livro armazenados em um arquivo
 *            que abre juntamente com o programa
 */

void carregarDados(Lista* lista, const char* arquivo) {
    FILE* file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para leitura.\n");
        return;
    }

    int codigoLivro, anoLancamento, numeroDePaginas, quantidade;
    float preco;
    char nomeAutor[100], nomeLivro[50], editora[50], edicao[50], descricao[500], disponivel;

    // Leia linha por linha
    while (fscanf(file, "%d", &codigoLivro) != EOF) {
        // Agora lemos o resto dos dados da linha, usando uma abordagem diferente
        fscanf(file, "%s", nomeAutor);
        fscanf(file, "%s", nomeLivro);
        fscanf(file, "%d", &anoLancamento);
        fscanf(file, "%d", &numeroDePaginas);
        fscanf(file, "%s", editora);
        fscanf(file, "%d", &quantidade);
        fscanf(file, "%f", &preco);
        fscanf(file, "%s", edicao);
        fscanf(file, "%s", descricao);
        fscanf(file, " %c", &disponivel); // A leitura de char pode requerer um espaço extra para ignorar espaços pendentes

        // Crie o objeto Livro
        Livro* livro = (Livro*)malloc(sizeof(Livro));
        livro->codigoLivro = codigoLivro;
        livro->anoLancamento = anoLancamento;
        livro->numeroDePaginas = numeroDePaginas;
        livro->quantidade = quantidade;
        livro->preco = preco;
        strcpy(livro->nomeAutor, nomeAutor);
        strcpy(livro->nomeLivro, nomeLivro);
        strcpy(livro->editora, editora);
        strcpy(livro->edicao, edicao);
        strcpy(livro->descricao, descricao);
        livro->disponivel = disponivel;

        // Inserir na lista
        InserirElemento(lista, livro);
    }

    fclose(file);
}



/* Nome: salvarDados
 * Descricao: Salva os dados do livro inserido num txt
 */
void salvarDados(Lista* lista, const char* arquivo) {
    if (lista == NULL || lista->inicio == NULL) {
        printf("A fila está vazia ou não foi inicializada.\n");
        return;
    }

    FILE* file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Livro *temp =  lista->inicio;
    do{
        fprintf(file, "%d %s %s %d %d %s %d %.2f %s %s %c\n",
                temp->codigoLivro, temp->nomeAutor, temp->nomeLivro,
                temp->anoLancamento, temp->numeroDePaginas, temp->editora,
                temp->quantidade, temp->preco, temp->edicao, temp->descricao, temp->disponivel);
        
    }while(temp != lista->inicio);

    fclose(file);
    printf("Dados salvos com sucesso em %s.\n", arquivo);
}


/* Nome: RemoverElemento
 * Descri??o: Remove um livro especifico da lista com base no codigo do livro fornecido.
 *            Libera a memoria alocada para o livro removido.
 */
int RemoverElemento(Lista *lista, int codigoLivro){
	Livro *temp = lista->inicio; //ponteiro temporario do inicio da lista
	Livro *anterior = NULL; //ponterio para o elemento anterior
	
	if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
	
	while(temp != NULL){ //percorre a lista
		if(temp->codigoLivro == codigoLivro){ //verifica se o codigo do livro corresponde
			if(anterior == NULL){ //se for o primeiro elemento
				lista->inicio = temp->prox;
			}
			
			else{ //remove o elemento do meio ou do fim
				anterior->prox = temp->prox;
			}
			
			free(temp);
			printf("\n livro com codigo: %d. Removido com sucesso!\n", codigoLivro);
			return 1;
		}
		//avanca os ponteiros
		anterior = temp;
		temp = temp->prox;
	}
	printf("\n livro com codigo: %d. N?o encontrado.\n", codigoLivro);
	return 0;
}


/* Nome: InserirElementoInicio
 * Descri??o: Insere um novo livro no inicio da lista, deslocando os outros 
 *            elementos para a proxima posicao.
 */
void InserirElementoInicio(Lista *lista, Livro *novo){
	if(lista == NULL){
        printf("A lista nao foi criada\n");
        return;
    }
	
	if (lista->inicio == NULL) { 
        lista->inicio = novo;
        novo->prox = novo; // Torna a lista circular
    } 
	
	else {
        Livro *temp = lista->inicio;
        
        while (temp->prox != lista->inicio) {
            temp = temp->prox; // Encontra o ultimo elemento
        }
        
        temp->prox = novo; // Atualiza o ultimo elemento para apontar para o novo
        novo->prox = lista->inicio; 
        lista->inicio = novo;
	}
}


/* Nome: InserirElementoPosicao
 * Descricao: Insere um novo livro em uma posicao especifica da lista. Se a posicao
 *            for 0, o livro sera inserido no inicio. Caso contririo, ele sera 
 *            inserido na posicao desejada, ou sera exibida uma mensagem de erro 
 *            se a posicao for invalida.
 */
int InserirElementoPosicao(Lista *lista, Livro *novo, int posicao) {
    if (lista == NULL) {
        printf("A lista não foi criada\n");
        return 0;
    }

    if (novo == NULL) {
        printf("Informações inválidas\n");
        return 0;
    }

    if (posicao == 0) { 
        // Insere no início da lista
        InserirElementoInicio(lista, novo);
        return 1;
    } else {
        Livro *temp = lista->inicio;
        int i;

        // Avança até a posição desejada ou até o final da lista circular
        for (i = 0; i < posicao - 1 && temp->prox != lista->inicio; i++) {
            temp = temp->prox;
        }

        if (i == posicao - 1) {
            // Aloca memória para o novo elemento
            Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
            if (novoLivro == NULL) {
                printf("Erro ao alocar memória para o novo livro\n");
                return 0;
            }

            // Copia os dados do livro para o novo elemento alocado
            novoLivro->codigoLivro = novo->codigoLivro;
            strcpy(novoLivro->nomeAutor, novo->nomeAutor);
            strcpy(novoLivro->nomeLivro, novo->nomeLivro);
            novoLivro->anoLancamento = novo->anoLancamento;
            novoLivro->numeroDePaginas = novo->numeroDePaginas;
            strcpy(novoLivro->editora, novo->editora);
            novoLivro->quantidade = novo->quantidade;
            strcpy(novoLivro->edicao, novo->edicao);
            strcpy(novoLivro->descricao, novo->descricao);

            // Ajusta os ponteiros para inserir o novo elemento
            novoLivro->prox = temp->prox; // Novo elemento aponta para o próximo
            temp->prox = novoLivro;      // Elemento atual aponta para o novo

            return 1;
        } else {
            printf("\nPosição inválida!\n");
            return 0;
        }
    }
}


/* Nome: IniciarLista
 * Descricao: Inicializa a lista de livros, definindo o ponteiro de inicio
 *            como NULL, indicando que a lista esta vazia.
 */
Lista* IniciarLista(){
	/*solicitando espaco para a lista*/
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    
    /*Verificando se o espaco foi resevado*/
    if(nova == NULL){
        printf("Sem espaco\n");
        return NULL;
    }
	
	nova->inicio = NULL;   //Define o inicio da lista como NULL (vazia)
	
	return nova;
}


/* Nome: ListarElementos
 * Descricao: Percorre a lista e exibe as informacoes de cada livro 
 *            
 */
void ListarElementos(Lista *lista) {
	if(lista == NULL){
        printf("A lista nao foi criada\n");
        return;
    }
	
    if(lista->inicio == NULL){
		printf("Lista Vazia!\n");
		return;
	}
	
	Livro *temp = lista->inicio;
	
	do{
		printf("Código do Livro: %d\n"
       "Nome do Autor: %s\n"
       "Nome do Livro: %s\n"
       "Ano de Lançamento: %d\n"
       "Número de Páginas: %d\n"
       "Editora: %s\n"
       "Quantidade: %d\n"
       "Preço: %.2f\n"
       "Edição: %s\n"
       "Descrição: %s\n"
       "Disponível: %c\n\n",
       temp->codigoLivro, temp->nomeAutor, temp->nomeLivro, temp->anoLancamento, temp->numeroDePaginas, temp->editora, 
       temp->quantidade, temp->preco, temp->edicao, temp->descricao, temp->disponivel);
       temp = temp->prox;
	}while(temp != lista->inicio);
}





/* Nome: TamanhoLista
 * Retorno: retorna quantos elementos a lista possui
 * Descricao: Funcao criada para saber quantos elementos a lista possui
 */
int TamanhoLista(Lista *lista){
	if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
	
	if(lista->inicio == NULL){
		return 0;
	}
	
	int tamanho = 0;
	Livro *temp = lista->inicio; //Ponteiro temporario para percorrer a lista
	
	do{
		tamanho++;
		temp = temp->prox;
	}while(temp != lista->inicio); //percorre a lista, ata que o proximo elemento seja o primeiro. e incrementa no contador os elementos da lista
	
	return tamanho;
}


int main() {
	Lista *lista;
	lista = IniciarLista();
	char nomeArquivo[] = "livro.txt";
	int escolha, posicao;
	
	//variaveis e definicao de linguagem
	int codigoLivro, anoLancamento, numeroDePaginas, quantidade;
	float preco;
    char nomeAutor[100], nomeLivro[50], editora[50], edicao[50], descricao[500], disponivel;
    
    
    setlocale(LC_ALL, "Portuguese");
    carregarDados(lista, nomeArquivo);
    //inicio do menu com o do while
	
	do{
		printf("\n========================= Menu =========================");
        printf("\n\n1. Inserir elemento no final\n");
        printf("2. Inserir livro no inicio\n");
        printf("3. Inserir livro em uma posicao especifica\n");
        printf("4. Listar todos os livros\n");
        printf("5. Atualizar livro\n");
        printf("6. Buscar livro\n");
        printf("7. Tamanho da lista\n");
        printf("8. Excluir todos os livros\n");
        printf("9. Remover livros Especifico\n");
        printf("10. Sair\n");
        
		printf("\nEscolha uma opcao: ");
        scanf("%d", &escolha);
        
        switch(escolha){
			 case 1:
                // Preenchendo os dados do livro
			    printf("Digite o codigo do livro: ");
			    scanf("%d", &codigoLivro);
			    printf("Digite o nome do autor: ");
			    scanf(" %[^\n]", nomeAutor);
			    printf("Digite o nome do livro: ");
			    scanf(" %[^\n]", nomeLivro);
			    printf("Digite o ano de lançamento: ");
			    scanf("%d", &anoLancamento);
			    printf("Digite o numero de paginas: ");
			    scanf("%d", &numeroDePaginas);
			    printf("Digite a editora: ");
			    scanf(" %[^\n]", editora);
			    printf("Digite a quantidade: ");
			    scanf("%d", &quantidade);
			    printf("Digite o preco: ");
			    scanf("%f", &preco);
			    printf("Digite a edicao: ");
			    scanf(" %[^\n]", edicao);
			    printf("Digite a descricao: ");
			    scanf(" %[^\n]", descricao);
			    printf("Disponivel (S/N): ");
			    scanf(" %c", &disponivel);
                InserirElemento(lista, criarLivro( codigoLivro, nomeAutor, nomeLivro, anoLancamento, numeroDePaginas, editora,  quantidade,  preco, edicao, descricao, disponivel)); //insere elemnto na fila
                salvarDados(lista, nomeArquivo);
                break;
            
            case 2:
                printf("Digite o codigo do livro: ");
			    scanf("%d", &codigoLivro);
			    printf("Digite o nome do autor: ");
			    scanf(" %[^\n]", nomeAutor);
			    printf("Digite o nome do livro: ");
			    scanf(" %[^\n]", nomeLivro);
			    printf("Digite o ano de lançamento: ");
			    scanf("%d", &anoLancamento);
			    printf("Digite o numero de paginas: ");
			    scanf("%d", &numeroDePaginas);
			    printf("Digite a editora: ");
			    scanf(" %[^\n]", editora);
			    printf("Digite a quantidade: ");
			    scanf("%d", &quantidade);
			    printf("Digite o preco: ");
			    scanf("%f", &preco);
			    printf("Digite a edicao: ");
			    scanf(" %[^\n]", edicao);
			    printf("Digite a descricao: ");
			    scanf(" %[^\n]", descricao);
			    printf("Disponivel (S/N): ");
			    scanf(" %c", &disponivel);
                InserirElementoInicio(lista, criarLivro( codigoLivro, nomeAutor, nomeLivro, anoLancamento, numeroDePaginas, editora,  quantidade,  preco, edicao, descricao, disponivel)); //insere elemnto na fila
                salvarDados(lista, nomeArquivo);
                break;
            
            case 3:
                printf("\nPosicao: ");
                scanf("%d", &posicao);
                
                printf("Digite o codigo do livro: ");
			    scanf("%d", &codigoLivro);
			    printf("Digite o nome do autor: ");
			    scanf(" %[^\n]", nomeAutor);
			    printf("Digite o nome do livro: ");
			    scanf(" %[^\n]", nomeLivro);
			    printf("Digite o ano de lançamento: ");
			    scanf("%d", &anoLancamento);
			    printf("Digite o numero de paginas: ");
			    scanf("%d", &numeroDePaginas);
			    printf("Digite a editora: ");
			    scanf(" %[^\n]", editora);
			    printf("Digite a quantidade: ");
			    scanf("%d", &quantidade);
			    printf("Digite o preco: ");
			    scanf("%f", &preco);
			    printf("Digite a edicao: ");
			    scanf(" %[^\n]", edicao);
			    printf("Digite a descricao: ");
			    scanf(" %[^\n]", descricao);
			    printf("Disponivel (S/N): ");
			    scanf(" %c", &disponivel);
                InserirElementoPosicao(lista, criarLivro( codigoLivro, nomeAutor, nomeLivro, anoLancamento, numeroDePaginas, editora,  quantidade,  preco, edicao, descricao, disponivel), posicao); //insere elemnto na fila
                salvarDados(lista, nomeArquivo);
                break;
            
            case 4:
            	printf("\n");
                ListarElementos(lista); //Lista todos os elementos
                break;
            
            case 5:
                printf("\nID do produto a ser atualizado: ");
                scanf("%d", &codigoLivro);
                AtualizarLivro(lista, codigoLivro); //atualiza o elemento
                break;
            
            case 6:
                printf("\ncodigo do livro a ser buscado: ");
                scanf("%d", &codigoLivro);
                Livro *livro = BuscarElemento(lista, codigoLivro); //busca o livro
                if (livro != NULL) {
                    printf("Código do Livro: %d\n"
				       "Nome do Autor: %s\n"
				       "Nome do Livro: %s\n"
				       "Ano de Lançamento: %d\n"
				       "Número de Páginas: %d\n"
				       "Editora: %s\n"
				       "Quantidade: %d\n"
				       "Preço: %.2f\n"
				       "Edição: %s\n"
				       "Descrição: %s\n"
				       "Disponível: %c\n\n",
				       livro->codigoLivro, livro->nomeAutor, livro->nomeLivro, livro->anoLancamento, livro->numeroDePaginas, livro->editora, 
				       livro->quantidade, livro->preco, livro->edicao, livro->descricao, livro->disponivel);
                } else {
                    printf("\nlivro nao encontrado encontrado!\n");
                }
                break;
            
            case 7:
                printf("\nTamanho da lista: %d\n", TamanhoLista(lista)); //verifica quantos elementos tem a lista
                break;
            
            case 8:
                ExcluirLista(lista); //exclui a lista
                printf("\nLista exclu?da!\n");
                break;
            
            case 9:
            	printf("\nID do produto a ser removido: "); //captura o codigo do livro que vai ser excluido
    			scanf("%d", &codigoLivro);
            	RemoverElemento(lista, codigoLivro);
            	break;
            
            case 10:
                ExcluirLista(lista); //exclui todos os elementos 
                printf("\nSaindo...\n");
                break;
            
            default:
                printf("Op??o inv?lida!\n");
                continue;
		}
	}while(escolha != 10);
	
	return 0;
}