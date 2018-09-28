#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int k,x,y;
  while (cin>>k) {
    int counter=0;
    std::vector<pair<int,int> > v;
    for ( y = k+1; y <= 2*k; y++) {
      int a=y-k;
      int b=k*y;
      // std::cout << "new x "<<b/a <<" k "<<k  << '\n';
      if (b%a==0) {
          counter++;
          x=b/a;
          v.push_back(make_pair(x,y));
      }
    }
    std::cout << counter << '\n';
    for (size_t i = 0; i < counter; i++) {
      /* code */
      printf("1/%i = 1/%i + 1/%i\n",k,v[i].first,v[i].second);
    }
  }

  return 0;
}
