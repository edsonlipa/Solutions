#include<bits/stdc++.h>
using namespace std;
void kill(int l, int r,vector<bool> &line){
  for (int i = l; i <= r; i++) {
    line[i]=0;
  }
  return;
}
int L_survivor(int i,vector<bool> line){
  while(i&&!line[i]){
    i--;
  }
  return i;
}
int R_survivor(int i,int B,vector<bool> line){
  while(i<=B&&!line[i]){
    i++;
  }
  return i;
}
int main(int argc, char const *argv[]) {
  int B,S,L,R;
  cin>>B>>S;
  while (B!=0) {
    vector<bool> line(B+1,1);
    int ls,rs;
    for (int i = 0; i < S; i++) {
      cin>>L>>R;
      ls=L_survivor(L-1,line);
      rs=R_survivor(R+1,B,line);
      kill(L,R,line);
      if (ls==0) {
        std::cout << '*';
      }else{
        std::cout << ls;
      }
      std::cout << ' ';
      if (rs>B) {
        std::cout << '*';
      }else{
        std::cout << rs;
      }
      std::cout << endl;

    }
    std::cout <<'-'<< endl;
    cin>>B>>S;
  }
  return 0;
}
