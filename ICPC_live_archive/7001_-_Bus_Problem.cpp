#include<bits/stdc++.h>
using namespace std;
class UnionFind{
private: vector<int> vi, p ,rank;
public:
  UnionFind(int N){rank.assign(N,0);
  p.assign(N,0); for(int i=0;i<N; i++) p[i]=i;}
  int findSet(int i){return (p[i]==i)?i:(p[i]=findSet(p[i])); }
  bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
  void unionSet(int i, int j){
    if(!isSameSet(i,j)){
      int x= findSet(i),y= findSet(j);
      if (rank[x]>rank[y]) p[y]=x;
      else {p[x]=y;
      if (rank[x]==rank[y])rank[y]++;}
    }
  }
};

int main() {
  vector<tuple<int,int,int>> routes;
  int ct,tc,n,a,b,c;
  cin>>tc;
  for(int t=0;t<tc;t++){
    int total=0;
    cin>>ct>>n;
    for (int i = 0; i < n; i++) {
      cin>>a>>b>>c;
      total+=c;
      routes.push_back(make_tuple(c,a,b));
    }
    sort(routes.begin(),routes.end());
    int mst_cost=0;
    UnionFind UF(ct);
    for (int i = 0; i < n; i++) {
      tuple<int,int,int> front=routes[i];
      if(!UF.isSameSet(get<1>(front),get<2>(front))){
        mst_cost+=get<0>(front);
        UF.unionSet(get<1>(front),get<2>(front));
      }
    }
    std::cout <<total- mst_cost << '\n';
    // for(auto i:routes)std::cout << get<0>(i)<<get<1>(i)<<get<2>(i) << '\n';
    routes.clear();
  }
  return 0;
}
