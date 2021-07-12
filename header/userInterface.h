#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <array>
#include "kenoBet.h"

/*!
 * Imprime no terminal o texto inicial, informando a quantidade de créditos do jogador,
 * o número de rounds à serem jogados, os créditos apostados em cada rodada e os spots escolhidos.
 * @param credits Número de créditos inicial do jogador.
 * @param rounds Número de rounds à serem jogados. */
void print_starting_message(KenoBet & bet, float credits, int rounds);

/*!
 * Imprime no terminal o resultado da rodada, com os números sorteados e os hits do jogador.
 * @param drawn_nums Array contendo os 20 números sorteados na rodada.
 * @param bet Aposta atual. */
void print_round_result(std::array<short int, 20> drawn_nums, KenoBet & bet, int round_num, float round_credits);

/*!
 * Imprime no terminal o resultado final da aposta, com o lucro final do jogador.
 * @param bet Aposta keno atual. */
void print_final_message(KenoBet & bet, float credits);


#endif
