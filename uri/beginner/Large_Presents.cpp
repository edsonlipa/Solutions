// runtime error  -> i dont understand the problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool changer(vector<pair<long unsigned,long>> &p,long unsigned a,long b){
  for (auto &i:p ) {
    if (i.second==b&&i.first>a) {
        i=make_pair(a,b);
        return true;
    }
    if(i.first==a&&i.second<b){
        i=make_pair(a,b);
        return true;
    }
  }
  return false;
}
bool longer (pair<long unsigned ,long> i,pair<long unsigned,long> j) { return (i.second>j.second);}
bool lesser (pair<long unsigned ,long> i,pair<long unsigned,long> j) { return (i.first<j.first);}
int main() {

  // std::map<long unsigned,long unsigned> presents;
  // std::map<long unsigned,long unsigned > print;
  vector<pair<long unsigned ,long>> presents;
  long T,N,K;
  cin>>T;
  for (int i = 0; i < T; i++) {
    std::cin >> N >> K;
    long unsigned I;
    long H,W,L;
    for (long j = 0; j < N; j++) {
      std::cin >>I>>H>>W>>L;
      if(!changer(presents,I,H*W*L)){
        presents.push_back(make_pair(I,H*W*L));
      }
    }
    sort(presents.begin(),presents.end(),longer);
    // for (long j = K-1; j < N; j++) {
    //   presents.pop_back();
    //   std::cout << "  " << presents[j].first;
    // }std::cout << " " << '\n';
    presents.erase(presents.begin()+K,presents.end());
    sort(presents.begin(),presents.end(),lesser);
    for (size_t l = 0; l < presents.size(); l++) {
      std::cout << presents[l].first ;
      if (i!=T-1) {
        std::cout << " ";
      }
    }
    if (i!=T-1) {
      std::cout  << '\n';

    }
    presents.clear();
    // print.clear();
  }
  return 0;
}
