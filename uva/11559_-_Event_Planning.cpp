#include <bits/stdc++.h>
using namespace std;

int main(int argc,const char *argv[]){
  int N,B,H,W,price;
  int a,inp,total,best;
  while (cin>>N) {
    cin>>B>>H>>W;
// std::cout << "N "<<N << '\n';
priority_queue<int,vector<int>,greater<int>> cola;
    for (int i = 0; i < H; i++) {
      cin>>price;
      a=0;
      priority_queue<int,vector<int>,greater<int>> cercano;
      for (int j = 0; j < W; j++) {
          cin>>inp;
          // std::cout << "inp " <<inp<< '\n';
          if (inp>=N) {
            cercano.push(inp);
          }
      }
      if (!cercano.empty()) {

        a=cercano.top();
        total=price*N;
        if(total<B) cola.push(total);
      }
    }
    if (cola.empty()) {
      std::cout << "stay home" << '\n';
    }else{
      std::cout << cola.top() << '\n';
    }
    // (total>B)?std::cout << "stay home" << '\n':std::cout << total << '\n';

  }
  return 0;
}
