/******************************************************************
 * Nome: Fila com Apontadores                                     *
 * Descricao: Implementacao de uma fila com apontadores para      *
 *            manipulacao de livros. Este codigo inclui as        *
 *            principais operacoes da fila, como:                 *
 *            dequeue                                             *
 *            enqueue                                             *
 *            verInicio                                           *      
 *                                                                *
 * Autor: Eduardo de Melo Domingos                                *
 * ultima alteracao: 14/12/2024                                   *
 ******************************************************************/


/*Include das bibliotecas*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


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
    struct Livro *prox;
} Livro;

/* Estrutura que representa a fila, com dois ponteiros, um para o inicio e um para o final*/
typedef struct {
	Livro *inicio;
   	Livro *fim;       
}Fila;





/* Nome: criarLivro
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


/* Nome: iniciarFila
 * Descricao: Inicializa a fila de livros, definindo o ponteiro de inicio e de fim
 *            como NULL, indicando que a fila esta? vazia.
 */
Fila* iniciarFila(){
	Fila *fila = (Fila*)malloc(sizeof(Fila));
	
	if(fila == NULL){
		printf("\n Fila nao foi criada!\n");
		return NULL;
	}
	
	fila->inicio = NULL;   //Define o inicio da fila como NULL (vazia)
	fila->fim = NULL;   //Define o fim da fila como NULL (vazia)
	
	return fila;
}


/* Nome: enqueue
 * Descricao: Enfileira os elementos, sempre os colocando no fim dda fila
 */
int enqueue(Fila *fila, Livro *novo){
	if(fila == NULL){
		printf("\n Fila nao foi criada!\n");
		return 0;
	}
	
	if(fila->fim == NULL){
		fila->inicio = novo;
		fila->fim = novo;
	}
	
	else{
		fila->fim->prox = novo;
		fila->fim = novo;
	}
	
	return 1;
}


/* Nome: dequeue
 * Descricao: remove o primeiro elemento da fila, avacando o proximo elemento para a primeira posicao
 */
int dequeue(Fila *fila){
	if(fila == NULL){
		printf("\n Fila nao foi criada!\n");
		return 0; 
	}
	
	if(fila->inicio == NULL){
		printf("\n A fila esta vazia!\n");
		return 0;
	}
	
	Livro *temp = fila->inicio;
	fila->inicio = fila->inicio->prox;
	
	if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    free(temp);
    printf("\n livro removido da fila com sucesso!\n");
    
    return 1;
}




/* Nome: excluirFila
 * Descricao: remove todos os elementos da fila, liberando memoria no caminho. 
              o ponteiro temp pega o primeiro elemento, e vai avancando pra os proximos.
 */
Fila* excluirFila(Fila *fila){
	if (fila == NULL) {
        printf("\n Pilha nao foi criada!\n");
        return NULL;
    }
	
	Livro *temp = fila->inicio;
	
	while(temp != NULL){
		Livro *prox = temp->prox;
		free(temp);
		temp = prox;
	}
	
	free(fila);
	fila->inicio = NULL;
	fila->fim = NULL;
	
	return NULL;
}


/* Nome: carregarDados
 * Descricao: Carrega os dados do livro armazenados em um arquivo
 *            que abre assim que o programa se inicia.
 */

void carregarDados(Fila* fila, const char* arquivo) {
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
        dequeue(fila);
    }
    fclose(file);
}


/* Nome: salvarDados
 * Descricao: Salva os dados do livro enseridos dentro de um txt
 */
void salvarDados(Fila* fila, const char* arquivo) {
    if (fila == NULL || fila->inicio == NULL) {
        printf("A fila está vazia ou não foi inicializada.\n");
        return;
    }

    FILE* file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Livro* temp = fila->inicio;
    while (temp != NULL) {
        fprintf(file, "%d %s %s %d %d %s %d %.2f %s %s %c\n",
                temp->codigoLivro, temp->nomeAutor, temp->nomeLivro,
                temp->anoLancamento, temp->numeroDePaginas, temp->editora,
                temp->quantidade, temp->preco, temp->edicao, temp->descricao, temp->disponivel);
        temp = temp->prox;
    }

    fclose(file);
    printf("Dados salvos com sucesso em %s.\n", arquivo);
}

int main() {
	Fila *fila;
	fila = iniciarFila();
	char nomeArquivo[] = "livro.txt";
	int escolha;
	
	//variaveis e definicao de linguagem
	int codigoLivro, anoLancamento, numeroDePaginas, quantidade;
	float preco;
    char nomeAutor[100], nomeLivro[50], editora[50], edicao[50], descricao[500], disponivel;
    
    
    setlocale(LC_ALL, "Portuguese");
    carregarDados(fila, nomeArquivo);
    //inicio do menu com o do while
	
	do{
		printf("\menu\n");
        printf("1. Inserir elemento na Fila\n");
        printf("2. Excluir Elemento do Inicio\n");
        printf("3. Excluir Fila\n");
        printf("4. Sair\n");
        
		printf("\nEscolha uma opcao: ");
        scanf("%d", &escolha);
        
        switch(escolha){
			 case 1:
               printf("Digite o codigo do livro: ");
                scanf("%d", &codigoLivro);
                printf("Digite o nome do autor: ");
                scanf(" %[^\n]", nomeAutor);
                printf("Digite o nome do livro: ");
                scanf(" %[^\n]", nomeLivro);
                printf("Digite o ano de lancamento: ");
                scanf("%d",  &anoLancamento);
                printf("Digite o numero de paginas: ");
                scanf("%d",  &numeroDePaginas);
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
                enqueue(fila, criarLivro( codigoLivro, nomeAutor, nomeLivro, anoLancamento, numeroDePaginas, editora,  quantidade,  preco, edicao, descricao, disponivel)); //insere elemnto na fila
                salvarDados(fila, nomeArquivo);
                break;
            
            case 2:
                dequeue(fila);
                break;
            
            case 3:
            	excluirFila(fila);
                break;
            
            case 4:
                excluirFila(fila); //exclui todos os elementos 
                printf("\n Saindo...\n");
                break;
            
            default:
                printf("Opcao invalida!\n");
                continue;
		}
	}while(escolha != 4);
	
	return 0;
}


