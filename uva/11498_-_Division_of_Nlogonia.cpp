#include <bits/stdc++.h>
using namespace std;
void get_location(int olat,int olng, int lat, int lng){
  if (olat<lat) {
    if (olng<lng) {
      std::cout << "NE" << '\n';
    }else if (olng>lng) {
      std::cout << "SE" << '\n';
    }else{
      std::cout << "divisa" << '\n';
    }
  }else if (olat>lat) {
    if (olng<lng) {
      std::cout << "NO" << '\n';
    }else if (olng>lng) {
      std::cout << "SO" << '\n';
    }else{
      std::cout << "divisa" << '\n';
    }
  }else{
    std::cout << "divisa" << '\n';
  }

}
int main(int argc, char const *argv[]) {
  int ncases,lat,lng;
  int olat,olng;

  cin>>ncases;
  cin>>olat>>olng;
  while (ncases) {
    for (int i = 0; i < ncases; i++) {
    cin>>lat>>lng;
    get_location(olat,olng,lat,lng);
    }
    cin>>ncases;
    cin>>olat>>olng;
  }
  return 0;
}
