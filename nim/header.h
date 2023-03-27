/**
 * @file header.h
 * @author Gabriel Melo
 * @date March, 2023
 * @brief Definições Globais de funções para o jogo "NIM"
 *
 *	Structs, Constantes e Assinaturas de Funções
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>


// Função para gerar um número aleatório 'n'
int Define_N(int max_value);

// Função para gerar um número aleatório 'm'
int Define_M(int n);

// Função para calcular a jogada do computador
int Computer_Move(int *n, int m, char *winner);

// Função para executar a jogada do player
void Player_Move(int *n, int escolha, char *winner);

// Função para rodar o jogo com o computador começando
char Game_Computer_First(int n, int m);

// Função para rodar o jogo com o player começando
char Game_Player_First(int n, int m);

// Função para rodar o jogo com 2 players
char Game_PvP(int n, int m);