// Accepted
#include <bits/stdc++.h>
using namespace std;

bool isprime(int val){
  if (val==0||val==1) {
    return false;
  }
  int count=0;
  for (int i = 1; i <= val; i++) {
    if (val%i==0) {
      if (count<2) {
        count++;
      }else return false;
    }
  }
  return true;
}
string is_S_prime(int val){
  if (isprime(val)) {
    while (val>0) {
      // std::cout << "digit "<<val%10 << '\n';
        if (!isprime(val%10)) {
          return "Primo";
        }
        val=val/10;
    }
    return "Super";
  }else return "Nada";
}
int main(int argc, char const *argv[]) {
    int value;
    while (std::cin >> value) {
      std::cout << is_S_prime(value) << '\n';
    }
  return 0;
}
