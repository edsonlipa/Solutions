#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int new_num;
  int maior=0;
  for (int i = 0; i < 3; i++) {
    std::cin >> new_num;
    maior=(maior+new_num+abs(maior-new_num))/2;
  }
  std::cout <<maior<< " eh o maior"<<endl;
  return 0;
}
