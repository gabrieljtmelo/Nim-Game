/**
 * @file funcs.c
 * @author Gabriel Melo
 * @date March, 2023
 * @brief Funções para a main.c
 *
 *	Funções para o jogo "NIM"
*/

#include "header.h"


/**
*	@brief Gera um número aleatório 'n' de peças
*   
    Gera um número aleatório 'n' maior que 1 e menor ou igual ao max_value
*	
*	@param max_value número de peças totais máximo
*
*/
int Define_N(int max_value){
    int n = 0;
    while(n <= 1){
        srand(time(NULL));
        n = (rand() % max_value) + 1;
    }
    return n;
}



/**
*	@brief Gera um número aleatório 'm' de peças para se remover
*   
    A partir do número de peças totais pré-definido, gera um número aleatório menor
    de peças que podem ser removidas 'm'
*	
*	@param n número de peças totais pré-definido
*
*/
int Define_M(int n){
    if(n == 2 || n == 3) return 1;
    int m = 0;
        while(m < 1){
            srand(time(NULL));
        m = (rand() % n) - 1;
        }
    return m;
}


/**
*	@brief Calcula a jogada do computador
*   
    A partir do número de peças totais pré-definido, calcula a escolha
    do computador e muda o valor de 'n' na memória
*	
*	@param n número de peças totais pré-definido
*   @param m número de peças retiraveis pré-definido
*   @param winner vencedor do jogo
*
*/
int Computer_Move(int *n, int m, char *winner){
            // Caso o player já tenha ganho
            if(*winner == 'P') exit;
            
            // Calculo da jogada
            int pc_escolha = *n % (m+1);
            if(pc_escolha == 0) pc_escolha = m;
            *n -= pc_escolha;
            // Caso o computador tenha ganhado
            if(*n == 0) *winner = 'C';
            return pc_escolha;
}

/**
*	@brief Calcula a jogada do computador
*   
    A partir do número de peças totais pré-definido, calcula a escolha
    do computador e muda o valor de 'n' na memória
*	
*	@param n número de peças totais pré-definido
*   @param escolha número de peças que serão retiradas pelo jogador
*   @param winner vencedor do jogo
*
*/
void Player_Move(int *n, int escolha, char *winner){
        // Caso o computador já tenha ganhado
        if (*winner == 'C') return;
        *n -= escolha;
        // Caso o jogador tenha ganhado
        if(*n <= 0){
            *n = 0;
            *winner = 'P';
        }
}

