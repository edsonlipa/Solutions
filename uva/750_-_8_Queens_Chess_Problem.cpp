#include<bits/stdc++.h>
using namespace std;
#define n 8
int Solution[n],a,b,tc,counter=0;
bool aceptado(int r,int c){
  for (int i = 0; i < c; i++) {
    if(Solution[i]==r||(abs(Solution[i]-r)==abs(i-c)))
     {return false;}
  }
  return true;
}
void backtraking(int columna) {
  if(columna==8&&Solution[b-1]==a-1){
    // std::cout << " "<<++counter << "      "<<Solution[0]+1;
    printf("%2d      %d",++counter, Solution[0]+1);
    for (size_t i = 1; i < n; i++) {
      std::cout <<" "<< Solution[i]+1;
    } std::cout << '\n';
    return ;}
  for (size_t r = 0; r < n; r++) {
      if (aceptado(r,columna)) {
        Solution[columna]=r;backtraking(columna+1);
      }
    }
}
int main(int argc, char const *argv[]) {
  std::cin >> tc;
  for (size_t t = 0; t < tc; t++) {
    cin>>a>>b;
    counter=0;
    std::cout << "SOLN       COLUMN" << '\n';
    std::cout << " #      1 2 3 4 5 6 7 8\n" << '\n';
    backtraking(0);
    if (t<tc-1)std::cout  << '\n';
  }
  return 0;
}
