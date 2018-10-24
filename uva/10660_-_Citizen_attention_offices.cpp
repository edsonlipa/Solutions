#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int ncases,nareas;
  set<set<int> > vec;
  for (size_t i = 0; i < 5; i++) {
    for (size_t j = 0; j < 21; j++) {
      for (size_t k = j+1; k < 22; k++) {
        for (size_t l = k+1; l < 23; l++) {
          for (size_t m = l+1; m < 24; m++) {
            for (size_t n = m+1; n < 25; n++) {
              set<int> current;
              current.insert(j);
              current.insert(k);
              current.insert(l);
              current.insert(m);
              current.insert(n);
              vec.insert(current);
              // std::cout << "size ' "<<current.size() << '\n';
            }
          }
        }
      }
    }
  }
  for(auto i : vec){
    for(auto j : i)
      std::cout << j << ' ';
    std::cout << '\n';
  }
  std::cout << "vec " <<vec.size() << '\n';
  cin>>ncases;
  for (size_t t = 0; t < ncases; t++) {
    std::vector<tuple<int,int,int>> city;
    cin>>nareas;
    int a,b,c;
    for (size_t i = 0; i < nareas; i++) {
      cin>>a>>b>>c;
      city.push_back(make_tuple(a,b,c));
    }
    for(auto i:vec){
      multiset<int> answer;
      for(auto area:city){
        // set<int> closest_area;
        priority_queue<int,vector<int>,greater<int>> closest_area;
        for(auto j:i){
          int antenax = floor(j/5);
          int antenay = j%5;
          int score = abs(get<0>(area)-antenax)+abs(get<1>(area)-antenay);
          std::cout << "/* score */ "<<score*get<2>(area) << '\n';
          closest_area.push(score*get<2>(area));
        }
        std::cout << "/* top */ "<<closest_area.top() << '\n';
        answer.insert(closest_area.top());
      }
    }
  }
  return 0;
}
