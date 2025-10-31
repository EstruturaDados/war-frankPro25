// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIOS 50
#define TAM_STRING 100

struct Territorio
{
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};
void LimparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main()
{
    struct Territorio Plants[MAX_TERRITORIOS];
    int totalLivros = 0;
    int opcao;

    do
    {
        printf("_______________________________________\n");
        printf("\t Plants - PARTE 1\t\n");
        printf("_______________________________________\n");
        printf("1 - Cadastrar novo Territorios\n");
        printf("2 - Listar todos os Territorios\n");
        printf("0 - Sair\n");
        printf("_______________________________________\n");
        printf("Escolha uma opçao: ");

        scanf("%d", &opcao);
        LimparBufferEntrada();

        switch (opcao)
        {
        case 1:
            if (totalLivros > MAX_TERRITORIOS)
            {
                printf("limite maximo de livros atingindo!");
            }
            else
            {
                printf("--- Cadastro de Livro --- \n\n");
                printf("Nome do Livro:");
                fgets(Plants[totalLivros].nome, TAM_STRING, stdin);
                printf("Nome do cor:");
                fgets(Plants[totalLivros].cor, TAM_STRING, stdin);
                printf("Numero de tropas:");
                scanf("%d", &Plants[totalLivros].tropas);

                totalLivros++;
                printf("Cadastro bem sucedido!");
            }

            break;
        case 2:
            printf("--- Lista de Territorios ---\n");
            if (totalLivros == 0)
            {
                printf("nao a Territorios\n");
            }
            else
            {
                for (size_t i = 0; i < totalLivros; i++)
                {
                    printf("Nome : %s\n", Plants[i].nome);
                    printf("Cor : %s\n", Plants[i].cor);
                    printf("Tropas : %d\n", Plants[i].tropas);
                }
            }

            break;
        case 0:
            printf("saindo");
            break;

        default:
            break;
        }
    } while (opcao != 0);
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
