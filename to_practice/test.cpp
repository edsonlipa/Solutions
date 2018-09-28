#include<bits/stdc++.h>
using namespace std;

int gdc(int a,int b){
  if (b==0) {
    return a;
  }
  return gdc(a,b%a);
}
int main(int argc, char const *argv[]) {
  std::cout << "gdc "<<gdc(4,8) << '\n';
  return 0;
}
