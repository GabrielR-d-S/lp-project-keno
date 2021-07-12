#ifndef KENOBET_H
#define KENOBET_H

#include <vector>
#include <array>

class KenoBet
{

  std::vector<short int> spots;   /* Vector de spots do jogador */
  float credits;                  /* Créditos do jogador */

  /* Tabela de retorno */
  const std::vector<std::vector<float>>
  payoffTable = { {0},
                  {0,   3},
                  {0,   1,   9},
                  {0,   1,   2,  16},
                  {0, 0.5,   2,   6,  12},
                  {0, 0.5,   1,   3,  15, 50},
                  {0, 0.5,   1,   2,   3, 30, 75},
                  {0, 0.5, 0.5,   1,   6, 12, 36, 100},
                  {0, 0.5, 0.5,   1,   3,  6, 19,  90, 720},
                  {0, 0.5, 0.5,   1,   2,  4,  8,  20,  80, 1200},
                  {0,   0, 0.5,   1,   2,  3,  5,  10,  30,  600, 1800},
                  {0,   0, 0.5,   1,   1,  2,  6,  15,  25,  180, 1000, 3000},
                  {0,   0,   0, 0.5,   1,  2,  4,  24,  72,  250,  500, 2000, 4000},
                  {0,   0,   0, 0.5, 0.5,  3,  4,   5,  20,   80,  240,  500, 3000, 6000},
                  {0,   0,   0, 0.5, 0.5,  2,  3,   5,  12,   50,  150,  500, 1000, 2000, 7500},
                  {0,   0,   0, 0.5, 0.5,  1,  2,   5,  15,   50,  150,  300,  600, 1200, 2500, 10000}
                };

public:

  /*!
   * Constrói uma aposta Keno vazia. */
  KenoBet();

  /*!
   * Copia os spots de um vector extermo para o vector atributo da classe.
   * @param vec Vector externo contendo os spots da aposta. */
  void add_spots(std::vector<short int> vec);

  /*!
   * Retorna o vector de spots.
   * @return Vector de spots. */
  std::vector<short int> get_spots(void);

  /*!
   * Adiciona uma quantidade à carteira de créditos do jogador.
   * @param quantity Quantidade de créditos à ser adicionada à carteira do jogador. */
  void add_credits(float quantity);

  /*!
   * Retorna a quantidade atual de créditos do jogador
   * @return Float que representa a quantidade de créditos do jogador. */
  float get_credits(void);

  /*!
   * Determina o número de hits obtido pelo jogador na rodada.
   * @param Array estática de 20 inteiros representando os 20 números sorteados.
   * @return Número de hits do jogador na rodada. */
  short int get_hits(std::array<short int, 20> drawn_nums);

  /*!
   * Retorna o vector de spots vencedores na rodada atual.
   * @param Array estática de 20 inteiros representando os 20 números sorteados.
   * @return Vector de spots vencedores da rodada. */
  std::vector<short int> get_winning_spots(std::array<short int, 20> drawn_nums);

  /*!
   * Determina o fator de lucro do jogador baseado no número de hits e spots.
   * @param hits Número de hits do jogador na rodada.
   * @return Fator de lucro do jogador determinado pela payoffTable. */
  float get_payoff(short int hits);

};

#endif
