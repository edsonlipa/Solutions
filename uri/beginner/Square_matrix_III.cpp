// Accepted
#include <iostream>
#include <vector>
using namespace std;
std::vector<int> v(1,1);
int digits(int a){
  int d=0;
  while (a) {
    a=a/10;
    d++;
  }
  return d;
}
void space(int a){
  for (size_t k = 0; k < a; k++) {
    std::cout << " " ;
  }
}
void matrix(int a){
  int sp=digits(v[a-1]*v[a-1])+1;

  for (size_t i = 0; i < a; i++) {
    for (size_t j = 0; j < a; j++) {

      int dt=digits(v[i]*v[j]);
      if (j==0) {

        space(sp-dt-1);
      }else{
        space(sp-dt);

      }
      std::cout <<v[i]*v[j];
    }

      std::cout  << '\n';

  }
  std::cout << '\n';
}
int main(int argc, char const *argv[]) {
  int a;
  cin>>a;
  while (a!=0) {
    for (size_t i = 1; i < a; i++) {
      v.push_back(v[i-1]*2);
    }
    matrix(a);
    v.clear();v.push_back(1);
    cin>>a;
  }
  return 0;
}
