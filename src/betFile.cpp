#include "../header/betFile.h"
#include <cctype>
#include <string>
#include <sstream>
#include <vector>

void validate(std::ifstream & f)
{
  std::cout << ">> Abrindo arquivo fornecido..." << std::endl;

  /* checa se o arquivo existe */
  if (!f)
  {
    std::cerr << "!! Erro: arquivo fornecido não existe." << std::endl;
    exit(1);
  }
  std::cout << ">> Arquivo aberto com sucesso!" << std::endl;
  std::cout << ">> Checando por irregularidades..." << std::endl;

  /* checa por caracteres estranhos no arquivo */
  char c;
  while (f >> c)
  {
    if (!isdigit(c) && c != ' ' && c != '.')
    {
      std::cerr << "!! Erro: caractere estranho '" << c << "' detectado." << std::endl;
      exit(1);
    }
  }

  f.clear();
  f.seekg(0);

  /* checa se o IC é um número real diferente de zero */
  std::string str;
  std::getline(f, str);
  str.erase(str.find_last_not_of(" \n\r\t")+1); /* remove ws à direita */
  bool isFloat = false, whiteSpace = false, tooManyPoints = false, isZero = true;
  for (auto c : str)
  {
    if (isdigit(c) && c != '0')
      isZero = false;
    if (c == '.' && isFloat)
      tooManyPoints = true;
    if (c == '.')
      isFloat = true;
    if (c == ' ')
      whiteSpace = true;
  }
  if (!isFloat || whiteSpace || tooManyPoints || isZero)
  {
    std::cerr << "!! Erro: IC inválido." << std::endl;
    exit(1);
  }

  /* checa se o NR é um (único) inteiro diferente de zero */
  std::getline(f, str);
  str.erase(str.find_last_not_of(" \n\r\t")+1); /* remove ws à direita */
  bool isInt = true;
  isZero = true;
  for (auto c : str)
  {
    if (isdigit(c) && c != '0')
      isZero = false;
    if (c == ' ' || c == '.')
      isInt = false;
  }
  if (!isInt || isZero)
  {
    std::cerr << "!! Erro: NR inválido." << std::endl;
    exit(1);
  }

  /* checa se os spots são todos números inteiros */
  std::getline(f, str);
  str.erase(str.find_last_not_of(" \n\r\t")+1); /* remove ws à direita */
  bool noPoint = true;
  for (auto c : str)
    if (c == '.')
      noPoint = false;
  if (!noPoint)
  {
    std::cerr << "!! Erro: spots inválidos." << std::endl;
    exit(1);
  }

  /* checa se existem até 15 spots, se os spots são únicos e estão no intervalo [1, 80] */
  std::stringstream ss;
  ss << str;

  int i, count = 0;
  bool notInRange = false, tooManySpots = false, repeatedSpots = false;
  std::vector<int> vec;
  while (ss >> i)
  {
    for (auto k : vec)
      if (i == k)
        repeatedSpots = true;
    vec.push_back(i);

    if (i < 1 || i > 80)
      notInRange = true;
    count++;
  }

  if (count > 15)
    tooManySpots = true;

  if (tooManySpots)
  {
    std::cerr << "!! Erro: mais de 15 spots detectados." << std::endl;
    exit(1);
  }

  if (notInRange)
  {
    std::cerr << "!! Erro: spot fora do intervalo detectado." << std::endl;
    exit(1);
  }

  if (repeatedSpots)
  {
    std::cerr << "!! Erro: spots repetidos detectados." << std::endl;
    exit(1);
  }

  std::cout << ">> Arquivo validado com sucesso!" << std::endl;
  std::cout << "----------------------------------" << std::endl;

  f.clear();
  f.seekg(0);

}

float read_credits(std::ifstream & f)
{
  std::string str;
  std::getline(f, str);
  str.erase(str.find_last_not_of(" \n\r\t")+1); /* remove ws à direita */
  std::stringstream ss;
  ss << str;
  float c;
  ss >> c;
  return c;
}

int read_rounds(std::ifstream & f)
{
  std::string str;
  std::getline(f, str);
  str.erase(str.find_last_not_of(" \n\r\t")+1); /* remove ws à direita */
  std::stringstream ss;
  ss << str;
  int r;
  ss >> r;
  return r;
}

std::vector<short int> read_spots(std::ifstream & f)
{
  std::string str;
  std::getline(f, str);
  str.erase(str.find_last_not_of(" \n\r\t")+1); /* remove ws à direita */
  std::stringstream ss;
  ss << str;
  std::vector<short int> vec;
  int i;
  while (ss >> i)
    vec.push_back(i);
  return vec;
}
