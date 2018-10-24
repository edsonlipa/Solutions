#include<bits/stdc++.h>
using namespace std;

bool is_valid(size_t i){
  if(i<=20||i==50){
    return true;
  }else if(i>20&&i<=40){
    if ((i%2==0||i%3==0)) {
      return true;
    }
  }else if(i>40&&i<=60){
    if (i%3==0) {
      return true;
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int score;
  cin>>score;
  while (score>0) {
    if (score>180) {
      std::cout << "THE SCORE OF "<<score<<" CANNOT BE MADE WITH THREE DARTS." << '\n';
    }else{
      int permutations=0;
      set<set<int>> combinations;
      for (size_t i = 0; i <= 60; i++)
      for (size_t j = 0; j <= 60; j++)
      for (size_t k = 0; k <= 60; k++)
      if ((i+j+k)==score) {
        if(is_valid(i)&&is_valid(j)&&is_valid(k)){
          set<int> current;
          current.insert(i);
          current.insert(j);
          current.insert(k);
          combinations.insert(current);
          permutations++;
        }
      }
      if (combinations.empty()) {
        std::cout << "THE SCORE OF "<<score<<" CANNOT BE MADE WITH THREE DARTS." << '\n';
      }else{
        std::cout << "NUMBER OF COMBINATIONS THAT SCORES "<<score<<" IS "<<combinations.size()<<"." << '\n';
        std::cout << "NUMBER OF PERMUTATIONS THAT SCORES "<<score<<" IS "<<permutations<<"." << '\n';
      }
    }
    cin>>score;
    std::cout << "**********************************************************************" << '\n';
  }
  std::cout << "END OF OUTPUT" << '\n';
  return 0;
}
