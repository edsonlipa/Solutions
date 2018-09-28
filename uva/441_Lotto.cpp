#include <bits/stdc++.h>
using namespace std;
int npg(int k){
  int dif=k-6;
  int ans=1;
  for (int i = 0; i < dif; i++) {
    ans*=(k-i);
  }
  return ans/dif;
}
int main(int argc, char const *argv[]) {
  int k,pg;
  cin>>k;
  while (k!=0) {
    std::vector<int> v(k);
    pg=npg(k);
    // cout << "pg " <<pg<< '\n';
    for (int i = 0; i < k; i++) {
      cin>>v[i];
      // cout << v[i] << '\n';
    }

    // for (size_t q = 0; q < pg; q++) {
      int p=8;
      for (int i = 7; i >1; i--) {
        for (int j = 0; j < k; j++) {
          /* code */
        }
        std::cout << v[7-i] << ' ';
      }
      std::cout  << '\n';
    // }
    cin>>k;
  }

  return 0;
}
