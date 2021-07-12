#include "../header/kenoBet.h"
#include "../header/betFile.h"
#include "../header/userInterface.h"
#include <random>

/*!
 * Executa os comandos de leitura do arquivo para o objeto bet na ordem correta.
 * @param f Fstream contendo o arquivo de apostas aberto.
 * @param bet Objeto KenoBet utilizado.
 * @param rounds Referência para inteiro que armazenará o número de rounds jogados.
 * @param credits Referência para float que armazenará o crédito inicial da aposta. */
void file_to_bet(std::ifstream & f, KenoBet & bet, int & rounds, float & credits)
{
  validate(f);
  credits = read_credits(f);
  rounds = read_rounds(f);
  bet.add_spots(read_spots(f));
}

/*!
 * Função que gera 20 números aleatórios únicos entre 0 e 80 e armazena numa array.
 * @return Array estática de 20 posições contendo os 20 números sorteados. */
std::array<short int, 20> draw()
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(0.0, 80.0);

  std::vector<short int> vec;

  int i;
  bool uniqueValue;
  vec.push_back(dist(mt));
  while (vec.size() < 20)
  {
    i = dist(mt);
    uniqueValue = true;
    for (auto k : vec)
      if (k == i)
        uniqueValue = false;
    if (uniqueValue)
      vec.push_back(i);
  }

  std::array<short int, 20> arr;

  int itr = 0;
  for (auto k : vec)
  {
    arr[itr] = k;
    itr++;
  }

  return arr;
}

/*!
 * Função que executa os métodos da interface na ordem correta.
 * @param bet Objeto KenoBet da rodada.
 * @param rounds Inteiro representando o número de rounds jogados.
 * @param credits Float representando o crédito inicial do jogador. */
void start_game(KenoBet & bet, int rounds, float credits)
{
  print_starting_message(bet, credits, rounds);

  float payoff;
  short int hits;

  for (int i = 1; i <= rounds; i++)
  {
    std::array<short int, 20> drawn_nums = draw();

    hits = bet.get_hits(drawn_nums);
    payoff = bet.get_payoff(hits);
    bet.add_credits((credits / rounds) * payoff);

    print_round_result(drawn_nums, bet, i, credits / rounds);
  }
}

int main(int argc, char *argv[]) {
  std::ifstream file;
  file.open(argv[1]);

  KenoBet bet;
  int nr;
  float ic;

  file_to_bet(file, bet, nr, ic);
  file.close();

  start_game(bet, nr, ic);

  print_final_message(bet, ic);

  return 0;
}
