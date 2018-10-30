#include <bits/stdc++.h>
using namespace std;
#define max 1000000
// #define dos(i) 1<<i
int A[max];
// map<int,map<int,int> > spt;
// int spt[max][max];
std::vector<std::vector<int> > spt;
// std::vector<std::vector<int> > spt(1000000,std::vector<int> (1000000));
void create_spt(int N) {
  for (int i = 1; 1<<i <= N; i++) {
    int s= 1<<(i-1);
    std::vector<int> temp;
    spt.push_back(std::vector<int>(0));

    for (int j = 0; j+(s<<1)-1 < N; j++) {
      if(A[spt[i-1][j]]<A[spt[i-1][j+s]]){
        // spt[i][j]=spt[i-1][j];
        spt[i].push_back(spt[i-1][j]);
      }else{
        // spt[i][j]=spt[i-1][j+s];
        spt[i].push_back(spt[i-1][j+s]);
      }
    }
  }
}
int rmq(int a,int b){
  int s=b-a+1;
  int k=log2(s);
  // std::cout << "\tRMQ "<<a<<" "<<b << '\n';
  // std::cout << "S "<<s << '\n';
  // std::cout << "K "<<k << '\n';
  // std::cout << "\tmin "<<spt[k][a]<<" "<<spt[k][b-(1<<k)+1] << '\n';
  return min(A[spt[k][a]],A[spt[k][b-(1<<k)+1]]);
}
int main(int argc, char const *argv[]) {
  int T,N,Q;
  cin>>T;
  for (int t = 1; t <= T; t++) {
    std::cout << "Scenario #"<<t<<":" << '\n';
    cin>>N;
    cin>>Q;
    int n,a,b;
    std::vector<int> temp;
    for (int i = 0; i < N; i++) {
      cin>>n;
      A[i]=n;
      // spt[0][i]=i;
      temp.push_back(i);
    }
    spt.push_back(temp);
    create_spt(N);
    for (int i = 0; i < Q; i++) {
      cin>>a>>b;
      a--;b--;
      std::cout << rmq(a,b) << '\n';
    }
    spt.clear();
    // for (auto i:spt) {
    //   for (auto j:i.second) {
    //     std::cout << j.second << ' ';
    //   }
    //   std::cout << '\n';
    // }

  }
  return 0;
}
