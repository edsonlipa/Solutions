#include<bits/stdc++.h>
using namespace std;

int main(){
  int M;
  while (cin>>M) {

    std::vector<pair<int,int>> ones;
    std::vector<pair<int,int>> threes;
    for (size_t i = 0; i < M; i++) {
      string row; cin>>row;
      for (size_t j = 0; j < M; j++) {
        int item = stoi(row.substr(j,1));
        if (item==1) {
          ones.push_back(make_pair(i,j));
        }else if(item==3){
          threes.push_back(make_pair(i,j));
        }
      }
    }
    std::vector<priority_queue<int,vector<int>,greater<int>>> onesqueues(ones.size());
    for (size_t i = 0; i < ones.size(); i++) {
      for (size_t j = 0; j < threes.size(); j++) {
          onesqueues[i].push(abs(ones[i].first-threes[j].first)+abs(ones[i].second-threes[j].second));
      }
    }
    priority_queue<int> max;
    for (size_t i = 0; i < onesqueues.size(); i++) {
      max.push(onesqueues[i].top());
    }
    std::cout  <<max.top()<< '\n';
  }
  return 0;
}
