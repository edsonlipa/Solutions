#include <bits/stdc++.h>
using namespace std;

long long funct(std::vector<int> poly,int degree,int n){
  long long ans=0;
  for (int i = 0; i <= degree; i++) {
    ans+=poly[i]*pow(n,i);
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  int ncases;
  cin>>ncases;
  for (int i = 0; i < ncases; i++) {
    std::vector<int> poly;
    int degree,c,d,k;
    std::cin >> degree;
    for (int j = 0; j <= degree; j++) {
      std::cin >> c;
      poly.push_back(c);
    }
    std::cin >> d;
    std::cin >> k;
    int countn=1;
    int countk=0;
    long long tempk=0;
    while (k>countk) {
      tempk=funct(poly,degree,countn);
      countk+=d*countn;
      countn++;
    }
    std::cout << tempk << '\n';

  }
  return 0;
}
