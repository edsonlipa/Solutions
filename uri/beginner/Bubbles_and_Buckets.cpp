//time limit exceeded
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<string> names={"Marcelo","Carlos"};
  long size,elemnt,moves=0;
  std::cin >> size;
  while (size!=0) {
    moves=0;
    std::vector<long> list;
    for (size_t i = 0; i < size; i++) {
      std::cin >> elemnt;
      list.push_back(elemnt);

    }
    int winner=1;
    for (int i = 1; i <= size; i++) {
        moves+=abs(i-list[i-1]);
    }
    // for (size_t i = 0; i < size; i++) {
    //   for (size_t j = i%2; j <size-1 ; j+=2) {
    //     if (list[j]>list[j+1]) {
    //       swap(list[j],list[j+1]);
    //       winner++;
    //     }
    //   }
    // }

    std::cout << names[moves%2]  <<" "<<moves<< '\n';

    std::cin >> size;
  }
  return 0;
}
