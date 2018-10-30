#include<bits/stdc++.h>
#include <limits.h>
using namespace std;
#define inf (1<<31)
// #define inf 10
typedef long long int tiempo;
typedef int number;
number n;
tiempo x,y;
// priority_queue<number,vector<number>,greater<number> > pila;
// tiempo minimo = pow(2,63);
// bool validate(number acc,tiempo tm){
//   if (acc<n&&tm<minimo) {
//     return true;
//   }
//   return false;
// }
// void backtraking(number acc,tiempo tm){//acc = accumulated
//   if (acc==n) {
//     // std::cout << "posible cnadidato " <<tm<< '\n';
//     // pila.push(tm);
//     if(tm < minimo)minimo=tm;
//     return ;
//   }
//   if (validate(acc,tm)) {
//     backtraking(acc*2,tm+y);
//     backtraking(acc+1,tm+x);
//   }
//
// }
int main(){
  cin>>n>>x>>y;
  // std::cout << minimo << '\n';
  tiempo path[n];
  path[0]=x;
  for (number i = 1; i < n; i++) {
    int s=0;
    if (i%2==0)s=x;
    // std::cout <<path[i-1]+x <<" "<<(path[(i/2)]+y+s) << '\n';
    path[i]=min((path[i-1]+x),(path[(i/2)]+y+s));
  }
  // backtraking(1,x);
  std::cout << path[n-1] << '\n';
  // // printf("%uld\n",minimo );
  return 0;
}
