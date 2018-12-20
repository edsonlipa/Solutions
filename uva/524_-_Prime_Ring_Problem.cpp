#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max 35
ll sieve_size;
// bitset<10000010> bs;
bitset<max> bs;
vector<int> primes;
int caso=0;
void sieve(ll ceiling) {
  sieve_size=ceiling+1;
  bs.set();
  bs[0]=bs[1]=0;
  for(int i =2;i<=sieve_size;i++){
    if(bs[i]){
      for(int j=i*i;j<=sieve_size;j+=i){
        bs[j]=0;}
      primes.push_back((int)i);
    }
  }
}
bool isPrime(ll N){
  if (N<sieve_size)  return bs[N];
  for (int i = 0; i < primes.size(); i++) {
    if(N%primes[i]==0)return false;
  }
  return true;
}
bool is_valid(int candidate,int pos,int sizering,vector<int> &S){
  if(!isPrime(S[pos-1]+candidate))return false;
  return true;
}
void backT(int pos,int sizering,vector<int> &S,vector<bool> U,int c){
  U[c]=true;S[pos-1]=c;

  if (pos==sizering&&isPrime(1+c)) {
    for (int i = 0; i < sizering-1; i++) {
      std::cout << S[i] << ' ';
    }std::cout <<c << '\n';
    return;
  }

  for (int i = 1; i <= sizering; i++) {
    if (!U[i]&&is_valid(i,pos,sizering,S)) {
      backT(pos+1,sizering,S,U,i);
    }
  }
}
int main(){
 sieve(max);
 int n;
 while (cin>>n) {
  if (caso!=0)std::cout   << '\n';
  printf("Case %i:\n", ++caso);
 vector<int> Sol(16,0);
 vector<bool> Used(17,false);
 Sol[0]=1;Used[1]=true;
 backT(1,n,Sol,Used,1);

 }
  return 0;
}
