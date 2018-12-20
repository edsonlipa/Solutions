#include<bits/stdc++.h>
using namespace std;
set<string> strs;
int main(){
  int N;
  string S,bS;
  char c;
  cin>>N;
  for (int i = 0; i < N; i++) {
    S="";
    while (cin.get(c)&&c!='@') {
      if(c=='+'){while(c!='@')cin.get(c);break;}
      if(c!='.')S+=c;
    }
    cin>>bS;
    strs.insert(S+'@'+bS);
  }
  std::cout << strs.size() << '\n';
  return 0;
}
