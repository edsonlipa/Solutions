#include <bits/stdc++.h>
using namespace std;
#define max 1000000
int A[max];
// int spt[max][max];
std::vector<std::vector<int> > spt;
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
  return min(A[spt[k][a]],A[spt[k][b-(1<<k)+1]]);
}
int main(int argc, char const *argv[]) {
  int T,N,Q;
  cin>>T;
  for (int t = 1; t <= T; t++) {
    //clear per case
    spt.clear();
  }
  return 0;
}
