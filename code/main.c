/**
*  @file main.c
 * @author Gabriel Melo
 * @date March, 2023
 * @brief Jogo "NIM" usuário vs computador
 *
 * 
 *  
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include "header.h"
#include <unistd.h>

void main(void){
    
    setlocale(LC_ALL,"Portuguese");
    
    int n_max = -1;
    int n = 1;
    int m, escolha, x;
    int menu = 10;
    char winner = 'O';
    int test = 0;

  
    // Loop para Menu interativo
    while (menu != 4)
    {
        // Escolha da quantidade de peças
        while(n_max < 2){
            printf("\n\nBem vindo à incrível jogativa de NIM!!\n");
            printf("Estabeleça um número máximo de peças maior ou igual a 2\n");
            printf("Relembrando que este número será o teto, o número de peças será menor ou igual a este máximo pré-estabelecido\n");
            printf("Número de peças: ");
            test = scanf("%d", &n_max);

            // Caso o input estja errado
            if(n_max < 2 || test != 1){
                scanf("%*[^\n]");
                printf("\nEssa não é uma escolha possível");
                sleep(1);
                printf("\nResetando");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
            }
            // Se o input estiver certo, define 'n' e 'm'
            else{
                n = Define_N(n_max);
                m = Define_M(n);
            }
        }

        // Escolha de modos
        while(menu!=4)
        {
            printf("\n\nSelecione o modo de jogo\n");
            printf("Digite 1 para começar jogando contra o computador\n");
            printf("Digite 2 para deixar o computador começar\n");
            printf("Digite 3 para jogar contra um outro jogador local\n");
            printf("Digite 4 para sair\n");
            printf("Escolha: ");
            test = scanf("%d", &menu);
            
            // Caso o input esteja errado
            if(menu < 1 || menu > 4 || test != 1){
                printf("\nEssa não é uma escolha possível");
                scanf("%*[^\n]");
                sleep(1);
                printf("\nVoltando");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
            }
            else{
                switch (menu)
                {
                // Jogador Começa
                case 1:
                    while(n > 0){
                        printf("\nO total de peçaas é %d. O máximo de peças possíveis q pode-se retirar é %d\n", n, m);
                        printf("Número de peças a se retirar: ");
                        test = scanf("%d", &escolha);
                        // Caso a escolha seja maior que o número permitido de peças, ou menor ou igual a zero
                        if(escolha > m || escolha <= 0 || test != 1){
                            printf("\nSua escolha não atende as regras\n");
                            scanf("%*[^\n]");
                        } 
                        else {
                            Player_Move(&n, escolha, &winner);
                            if(n > 0){
                                x = Computer_Move(&n, m, &winner);
                                sleep(1);
                                printf("\nO computador retirou %d peças, ficando assim, %d peças restando\n", x, n);
                            }
                        }
                    }
                    break;

                // Computador Começa (Funcionando :emojidasmaozinhasjuntas:)
                case 2:
                    printf("\nO total de peçaas é %d. O máximo de peças possíveis q pode-se retirar é %d\n", n, m);
                    while(n > 0){
                        x = Computer_Move(&n, m, &winner);
                        sleep(1);
                        printf("\nO computador retirou %d peças, ficando assim, %d peças restando\n", x, n);
                        if(n > 0){
                            printf("\nO total de peças é %d. O máximo de peças possíveis q pode-se retirar é %d\n", n, m);
                            printf("Número de peças a se retirar: ");
                            test = scanf("%d", &escolha);
                            
                            // Caso a escolha seja maior que o número permitido de peças, ou menor ou igual a zero
                            if(escolha > m || escolha <= 0 || test != 1){
                                printf("\nSua escolha não atende as regras\n");
                                scanf("%*[^\n]");
                            }
                            else Player_Move(&n, escolha, &winner);
                        }
                    }
                    break;
                
                // Jogador contra outro Jogador
                case 3:
                    while(n > 0){
                        printf("\n\nO total de peçaas é %d. O máximo de peças possíveis q pode-se retirar é %d\n", n, m);
                        printf("Vez do JOGADOR 1\n");
                        printf("Número de peças a se retirar: ");
                        // Escolha do JOGADOR 1
                        test = scanf("%d", &escolha);
                        // Caso a escolha seja maior que o número permitido de peças, ou menor ou igual a zero
                        if(escolha > m || escolha <= 0 || test != 1){
                            printf("\nSua escolha não atende as regras\n");
                            scanf("%*[^\n]");
                        }
                        else {
                            Player_Move(&n, escolha, &winner);
                            if(n > 0){
                                escolha = -1;
                                while(escolha > m || escolha <= 0 || test != 1){
                                    printf("\n\nO total de peçaas é %d. O máximo de peças possíveis q pode-se retirar é %d\n", n, m);
                                    printf("Vez do JOGADOR 2\n");
                                    printf("Número de peças a se retirar: ");
                                    // Escolha do JOGADOR 2
                                    test = scanf("%d", &escolha);
                                    if(escolha > m || escolha <= 0 || test != 1){
                                        printf("\nSua escolha não atende as regras\n");
                                        sleep(1);
                                        scanf("%*[^\n]");
                                    }
                                    else{
                                        Player_Move(&n, escolha, &winner);
                                        if(n == 0) winner = 'B';
                                    }
                                }
                            }
                            else winner = 'A';
                        }
                    }
                    break;
                case 4:
                return;
                }
                // Fim do Loop e resultados finais
                if(winner == 'A') printf("\n\nParabéns, jogador 1! Você derrotou o seu oponente\n");
                else if(winner == 'B') printf("\n\nParabéns, jogador 2! Você derrotou o seu oponente\n");
                else if(winner == 'C') printf("\n\nInfelizmente, o computador te venceu nessa :(\n");
                else if(winner = 'P') ("\n\nParabéns, você derrotou o computador!\n");
                else printf("\n\nERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRO!!!!!!!!!!\n\n");
                menu = 4;
                }            
            }
    }
}