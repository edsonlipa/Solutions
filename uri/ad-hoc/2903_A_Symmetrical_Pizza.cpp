#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){return (b==0)?a: gcd(b,a%b);}
int main(){
  float N;
  cin>>N;
  std::cout << 36000/gcd(36000,round(N*100)) << '\n';
  // int c=0;
  // for (float i = 0; i < 10; i=i+0.01) {
  //   // std::cout <<i<<" "<< (int)(i*100) << '\n';
  //   if (round(i*100)!=c) {
  //     std::cout <<(i*100)<< " error " << c<< '\n';
  //   }
  //   c++;
  //
  // }
  return 0;
}
