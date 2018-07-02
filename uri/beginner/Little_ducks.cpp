// Accepted
#include <iostream>
using namespace std;
int main() {
  unsigned long long int a;
  cin>>a;
  while (a!=-1) {
    if (a==0) {
      std::cout << 0 << '\n';
    }else
    std::cout << a-1 << '\n';

    cin>>a;
  }
  return 0;
}
