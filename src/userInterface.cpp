#include "../header/userInterface.h"
#include <iostream>

void print_starting_message(KenoBet & bet, float credits, int rounds)
{
  std::cout << "Você está apostando $" << credits << " créditos em " << rounds << " rodada(s), um total de $" << credits / rounds << " créditos por rodada." << std::endl;
  std::cout << "Os spots escolhidos foram:" << std::endl;
  std::cout << "[ ";
  std::vector<short int> vec = bet.get_spots();
  for (auto i : vec)
    std::cout << i << " ";
  std::cout << "]\n" << std::endl;
  std::cout << "  Tabela de Retorno" << std::endl;
  std::cout << "----------+-----------" << std::endl;
  std::cout << "Hits      | Retorno" << std::endl;
  int maxHits = vec.size();
  for (int i = 0; i < maxHits; i++)
  {
    std::cout << i << "         | " << bet.get_payoff(i) << std::endl;
  }
  std::cout << "\n##################### INICIO DO JOGO #####################\n" << std::endl;
}

void print_round_result(std::array<short int, 20> drawn_nums, KenoBet & bet, int round_num, float round_credits)
{
  std::cout << "Rodada #" << round_num << ", os números sorteados foram:" << std::endl;
  std::cout << "[ ";
  for (auto i : drawn_nums)
    std::cout << i << " ";
  std::cout << "]" << std::endl;

  if (bet.get_hits(drawn_nums))
  {
    std::cout << "Parabéns! Você obteve " << bet.get_hits(drawn_nums) << " hit(s) nessa rodada. Foram eles:" << std::endl;
    std::cout << "[ ";
    std::vector<short int> vec = bet.get_winning_spots(drawn_nums);
    for (auto i : vec)
      std::cout << i << " ";
    std::cout << "]" << std::endl;
    std::cout << "Você faturou $" << bet.get_payoff(bet.get_hits(drawn_nums)) * round_credits << " créditos nessa rodada." << std::endl;
  } else
  {
    std::cout << "Você não obteve hits nessa rodada. Mais sorte na próxima!" << std::endl;
  }
  std::cout << "Seu balanço total é de $" << bet.get_credits() << " créditos." << std::endl;
  std::cout << "----------------------------------------------------------------" << std::endl;
}

void print_final_message(KenoBet & bet, float credits)
{
  std::cout << "\n##################### RESULTADO #####################\n" << std::endl;
  std::cout << "Você apostou um total de $" << credits << " créditos." << std::endl;
  std::cout << "Seu balanço final é de $" << bet.get_credits() << " créditos." << std::endl;

  if (bet.get_credits() > credits)
    std::cout << "Parabéns!!! Você teve um lucro de $" << bet.get_credits() - credits << " créditos!" << std::endl;
  if (bet.get_credits() == credits)
    std::cout << "Boa! Você manteve os créditos apostados." << std::endl;
  if (bet.get_credits() < credits)
    std::cout << "Uma pena! Você teve uma perda de $" << credits - bet.get_credits() << " créditos." << std::endl;
}
