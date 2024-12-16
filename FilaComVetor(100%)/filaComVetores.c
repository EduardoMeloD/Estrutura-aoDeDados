/******************************************************************
 * Nome: Fila com Vetores                                         *
 * Descricao: Implementacao de uma fila com vetores para          *
 *            manipulacao de livros. Este codigo inclui as        *
 *            principais operacoes da fila, como:                 *
 *            dequeue                                             *
 *            enqueue                                             *
 *                                                                *      
 *                                                                *
 * Autor: Eduardo de Melo Domingos                                *
 * ultima alteracao: 14/12/2024                                   *
 ******************************************************************/


/*Include das bibliotecas*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 5

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
	Livro livro[TAM];
	int inicio;
	int fim;
	int tamanho;     
	    
}Fila;




/* Nome: iniciarFila
 * Descricao: Inicializa a fila de livros, definindo o ponteiro de inicio e de fim
 *            como NULL, indicando que a fila estaa vazia.
 */
Fila* iniciarFila(){
	Fila *fila = (Fila*)malloc(sizeof(Fila));
	
	if(fila == NULL){
		printf("\n Fila nao foi criada!\n");
		return NULL;
	}
	
	fila->inicio = 0;   //Define o inicio da fila como NULL (vazia)
	fila->fim = -1;   //Define o fim da fila como NULL (vazia)
	fila->tamanho = 0;	
	return fila;
}

int filaCheia(Fila *fila){
	return fila->tamanho == TAM;
}

int filaVazia(Fila *fila){
	return fila->tamanho == 0;
}


/* Nome: enqueue
 * Descricao: Enfileira os elementos, sempre os colocando no fim da fila
 */
int enqueue(Fila *fila, Livro novo){
	
	if(fila == NULL){
		printf("\n Fila nao foi criada!\n");
		return 0;
	}
	
	if(filaCheia(fila)){
		printf("a fila ta cheia");
		return 0;
	}
	
	fila->fim = (fila->fim +1)%TAM;
	fila->livro[fila->fim] = novo;
	fila->tamanho++;
	
	
	return 1;
}


/* Nome: dequeue
 * Descricao: remove o primeiro elemento da fila, avacando o proximo elemento para a primeira posisao
 */
int dequeue(Fila *fila){
	if(fila == NULL){
		printf("\n Fila nao foi criada!\n");
		return 0;
	}
	
	if(filaCheia(fila)){
		printf("a fila ta cheia");
		return 0;
	}
	
	fila->inicio = (fila->fim +1)%TAM;
	fila->tamanho--;
	
    printf("\n livro removido da fila com sucesso!\n");
    
    return 1;
}




/* Nome: excluirFila
 * Descricao: remove todos os elementos da fila, liberando memoria no caminho. 
              o ponteiro temp pega o primeiro elemento, e vai avancando pra os proximos.
 */
int excluirFila(Fila *fila){
	if (fila == NULL) {
        printf("\n filha nao foi criada!\n");
        return 0;
    }
	
	if(filaVazia(fila)){
		printf("a fila esta vazia");
		return 0;
	}
	
	iniciarFila(fila);
	printf("a fila foi excluida");
	
	return 1;
	
}


/* Nome: carregarDados
 * Descricao: Carrega os dados do livro armazenados em um arquivo
 *            que abre assim que o programa e iniciado.
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
 * Descricao: Salva os dados do livro inserido dentro um txt
 */
void salvarDados(Fila* fila, const char* arquivo) {
    if (fila == NULL || filaVazia(fila)) {
        printf("A fila está vazia ou não foi inicializada.\n");
        return;
    }

    FILE* file = fopen(arquivo, "w"); // Abre o arquivo no modo de escrita
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Itera sobre os elementos da fila considerando a circularidade
    int i, pos;
    for (i = 0; i < fila->tamanho; i++) {
        pos = (fila->inicio + i) % TAM; // Calcula a posição no vetor circular
        Livro* livro = &fila->livro[pos];

        // Salva os dados no arquivo
        fprintf(file, "%d\n%s\n%s\n%d\n%d\n%s\n%d\n%.2f\n%s\n%s\n%c\n",
                livro->codigoLivro, livro->nomeAutor, livro->nomeLivro,
                livro->anoLancamento, livro->numeroDePaginas, livro->editora,
                livro->quantidade, livro->preco, livro->edicao, livro->descricao, livro->disponivel);
    }

    fclose(file); // Fecha o arquivo
    printf("Dados salvos com sucesso em %s.\n", arquivo);
}

int main() {
	Fila *fila;
	fila = iniciarFila();
	char nomeArquivo[] = "livro.txt";
	int escolha;
	
	//variaveis e defini??o de linguagem
	int codigoLivro, anoLancamento, numeroDePaginas, quantidade;
	float preco;
    char nomeAutor[100], nomeLivro[50], editora[50], edicao[50], descricao[500], disponivel;
    
    
    setlocale(LC_ALL, "Portuguese");
    carregarDados(fila, nomeArquivo);
    //inicio do menu com o do while
    
	 Livro livro; // Objeto temporário para armazenar os dados do livro
	do{
		printf("\menu\n");
        printf("1. Inserir elemento na Fila\n");
        printf("2. Excluir Elemento do Inicio\n");
        printf("3. Excluir Fila\n");
        printf("4. Sair\n");
        
		printf("\n Escolha uma opcao: ");
        scanf("%d", &escolha);
        
        switch(escolha){
			 case 1:
              

			    // Preenchendo os dados do livro
			    printf("Digite o codigo do livro: ");
			    scanf("%d", &livro.codigoLivro);
			    printf("Digite o nome do autor: ");
			    scanf(" %[^\n]", livro.nomeAutor);
			    printf("Digite o nome do livro: ");
			    scanf(" %[^\n]", livro.nomeLivro);
			    printf("Digite o ano de lancamento: ");
			    scanf("%d", &livro.anoLancamento);
			    printf("Digite o numero de paginas: ");
			    scanf("%d", &livro.numeroDePaginas);
			    printf("Digite a editora: ");
			    scanf(" %[^\n]", livro.editora);
			    printf("Digite a quantidade: ");
			    scanf("%d", &livro.quantidade);
			    printf("Digite o preco: ");
			    scanf("%f", &livro.preco);
			    printf("Digite a edicao: ");
			    scanf(" %[^\n]", livro.edicao);
			    printf("Digite a descricao: ");
			    scanf(" %[^\n]", livro.descricao);
			    printf("Disponivel (S/N): ");
			    scanf(" %c", &livro.disponivel);
			
			    // Adicionando o livro na fila
			    if (enqueue(fila, livro)) {
			        printf("Livro inserido na fila com sucesso!\n");
			    } else {
			        printf("Erro: a fila está cheia. Não foi possível inserir o livro.\n");
			    }
			
			    // Salva os dados da fila no arquivo após a inserção
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
                printf("\nSaindo...\n");
                break;
            
            default:
                printf("Opcao inv?lida!\n");
                continue;
		}
	}while(escolha != 4);
	
	return 0;
}


