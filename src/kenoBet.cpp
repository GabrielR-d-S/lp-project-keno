#include "../header/kenoBet.h"

KenoBet::KenoBet()
{
  credits = 0;
}

void KenoBet::add_spots(std::vector<short int> vec)
{
  spots = vec;
}

std::vector<short int> KenoBet::get_spots()
{
  return spots;
}

void KenoBet::add_credits(float quantity)
{
  credits += quantity;
}

float KenoBet::get_credits()
{
  return credits;
}

short int KenoBet::get_hits(std::array<short int, 20> drawn_nums)
{
  short int hits = 0;
  for (auto i = 0; i < spots.size(); i++)
  { for (auto j = 0; j < 20; j++)
    {
      if (spots[i] == drawn_nums[j])
      {
        hits++;
        break;
      }
    }
  }
  return hits;
}

std::vector<short int> KenoBet::get_winning_spots(std::array<short int, 20> drawn_nums)
{
  std::vector<short int> winning_spots;
  for (auto i = 0; i < spots.size(); i++)
  { for (auto j = 0; j < 20; j++)
    {
      if (spots[i] == drawn_nums[j])
      {
        winning_spots.push_back(spots[i]);
        break;
      }
    }
  }
  return winning_spots;
}

float KenoBet::get_payoff(short int hits)
{
  return payoffTable[spots.size()][hits];
}
