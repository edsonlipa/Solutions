#include <bits/stdc++.h>
using namespace std;

// #define dos(i) 1<<i
vector<int> A;
map<int,map<int,int> > spt;
void create_spt(int N) {
  for (size_t i = 1; 1<<i < N; i++) {
    int s= 1<<(i-1);
    for (size_t j = 0; j+(s<<1)-1 < N; j++) {
      if(A[spt[i-1][j]]<A[spt[i-1][j+s]]){
        spt[i][j]=spt[i-1][j];
      }else{
        spt[i][j]=spt[i-1][j+s];
      }
    }
  }
}
int rmq(int a,int b){
  int s=b-a+1;
  int k=log2(s);
  return min(A[spt[k][a]],A[spt[k][b-(1<<k)-1]]);
}
int main(int argc, char const *argv[]) {
  int T,N,Q;
  cin>>T;
  for (size_t t = 1; t <= T; t++) {
    std::cout << "Scenario #"<<t<<":" << '\n';
    cin>>N;
    cin>>Q;
    int n,a,b;

    for (size_t i = 0; i < N; i++) {
      cin>>n;
      A.push_back(n);
      spt[0][i]=i;
    }
    create_spt(N);
    for (size_t i = 0; i < Q; i++) {
      cin>>a>>b;
      std::cout << rmq(a,b) << '\n';
    }
    A.clear();
    // for (auto i:spt) {
    //   for (auto j:i.second) {
    //     std::cout << j.second << ' ';
    //   }
    //   std::cout << '\n';
    // }
    // for (auto i: A) {
    //   std::cout <<i<< " " ;
    // }
    // std::cout << '\n';

  }
  return 0;
}
