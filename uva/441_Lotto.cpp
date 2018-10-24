#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int k;
  cin>>k;
  while (k!=0) {
    std::vector<int> v(k);
    for (int i = 0; i < k; i++) {
      cin>>v[i];
    }
    for(int i=0;i<(k-5);i++)
    for(int j=i+1;j<=(k-4);j++)
    for(int l=j+1;l<=(k-3);l++)
    for(int m=l+1;m<=(k-2);m++)
    for(int n=m+1;n<=(k-1);n++)
    for(int o=n+1;o<k;o++)
    std::cout <<v[i]<<" "<<v[j]<<" "<<v[l]<<" "<<v[m]<<" "<<v[n]<<" "<<v[o] << '\n';
    cin>>k;
    if (k!=0) {
      std::cout  << '\n';
    }
  }

  return 0;
}
