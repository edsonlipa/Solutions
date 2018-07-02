// Accepted
#include <iostream>
using namespace std;
int main() {
  int degree;
  while (std::cin >> degree) {

    if (degree<90||degree==360) {
      std::cout << "Bom Dia!!" << '\n';
    }else if(degree<180){
      std::cout << "Boa Tarde!!" << '\n';
    }else if(degree<270){
      std::cout << "Boa Noite!!" << '\n';
    }else if(degree<360)
      std::cout << "De Madrugada!!" << '\n';
  }
  return 0;
}
