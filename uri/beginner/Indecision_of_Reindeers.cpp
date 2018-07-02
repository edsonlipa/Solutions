// Accepted
#include <bits/stdc++.h>
using namespace std;

std::vector<string> reindeers={"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};
int total_sum=-1;
int main(int argc, char const *argv[]) {
  int snowballs;
  for (size_t i = 0; i < 9; i++) {
    std::cin >> snowballs;
    total_sum+=snowballs;
  }

  std::cout <<reindeers[total_sum%9] << '\n';
  return 0;
}
