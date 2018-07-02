// Accepted
#include <stdio.h>
#include <iostream>
using namespace std;
int banknotes[] ={100,50,20,10,5,2,1};
int main() {
  long a;
  std::cin >> a;
  std::cout << a << '\n';
  for (size_t i = 0; i < 7; i++) {
    long b= a/banknotes[i];
    printf("%ld nota(s) de R$ %d,00\n",b,banknotes[i] );
    a= a-b*banknotes[i];
  }

  return 0;
}
