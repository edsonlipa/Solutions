#include <bits/stdc++.h>
using namespace std;
#define INF (1<<30)-1
#define L(i) (i<<1)+1
#define R(i) (i+1)<<1
#define P(i)  (i-1)>>1
#define create() create_st(0,0,n_pirates-1)
// #define RMQ(a,b) rmq(0,0,n_pirates-1,a,b)
#define F(a,b) update(0,0,n_pirates-1,a,b,1)
#define E(a,b) update(0,0,n_pirates-1,a,b,0)
#define I(a,b) update(0,0,n_pirates-1,a,b,-1)
#define S(a,b) rmq(0,0,n_pirates-1,a,b)

int st[4*1024000];
string A;
// int leaves[1024000];
int lazy[4*1024000];
void lazy_update(int i,int a,int b,int m);

void create_st(int i,int a,int b){
  // std::cout << "create ("<<a<<" : "<<b <<")"<< '\n';
  lazy[i]=0;
  if(a==b){
    st[i]=A[a]-'0';

    // leaves[a]=i;
    return;
  }

  int m =(a+b)/2;
  // if(lazy[i]) lazy_update(i,a,b,m);
  create_st(L(i),a,m);
  create_st(R(i),m +1,b);
  st[i]=st[L(i)]+st[R(i)];
}
void lazy_reverse(int &l) {

  switch (l) {
    case 1: l=2; break;
    case 2: l=1; break;
    case 3:l=0; break;
  }
  // std::cout << "/**///////////////entre reverse/***************** */ "<<l << '\n';
}
void lazy_merge(int i) {

  switch (lazy[i]) {
    case 1: lazy[i]=2; break;
    case 2: lazy[i]=1; break;
    case 3:lazy[i]=0; break;
  }
  // std::cout << "/**///////////////entre reverse/***************** */ "<<l << '\n';
}
void lazy_update(int i,int a,int b,int m){
  if(a==b){lazy[i]=0;return ;}

  // if(lazy[L(i)]) lazy_update(L(i),a,m,(m+a)/2);
  // if(lazy[R(i)]) lazy_update(R(i),m+1,b,(b+m+1)/2);
  if ( lazy[i]!=3) {
    // if(lazy[L(i)])lazy[L(i)]=lazy[i]);
    // if(lazy[R(i)])lazy[R(i)]=lazy[i]);
    st[L(i)]= (lazy[i]==1)?0:m-a+1;
    st[R(i)]= (lazy[i]==1)?0:b-m;

    lazy[L(i)]= lazy[i];
    lazy[R(i)]= lazy[i];
  }else{
    if(lazy[L(i)])lazy_merge(L(i));else lazy[L(i)]= lazy[i];
    if(lazy[R(i)])lazy_merge(R(i));else lazy[R(i)]= lazy[i];
    st[L(i)]= (m-a+1)-st[L(i)];
    st[R(i)]= (b-(m+1)+1)-st[R(i)];
  }
  // std::cout << "actualizar lazy " <<lazy[i]<<" -> "<<st[L(i)]<<" "<<st[R(i)]<<" / " <<a<<" "<<b<<" m:"<<m<< '\n';
  lazy[i]= 0;
}
int update(int i,int a,int b,int qa,int qb,int v){
  // std::cout << "break " << v<<" "<<a<<" "<<b<<"/ "<<qa<<" "<<qb<< '\n';

  int m=(a+b)/2;
  if(qb<a||b<qa){
    // std::cout << "\tfuera" << '\n';
    return st[i];}
  if(qa<=a&&b<=qb){
      switch (v) {
        case 1: lazy[i]=2; //plantar marcador lazy F
                st[i]=b-a+1;
                // std::cout << "update " <<" "<<a<<" "<<b<<"/ "<<st[i]<< '\n';
              break;
        case 0: lazy[i]=1; //plantar marcador lazy E
                st[i]=0;
              break;
        case -1:
                if (lazy[i])lazy_merge(i);
                else lazy[i]=3; //plantar marcador lazy I
                st[i]=(b-a+1)-st[i];

                // std::cout << "update " <<" :"<<a<<" "<<b<<"/ "<<st[i]<< '\n';
              break;
            }
            // std::cout << "marcador lazy "<< lazy[i]<<" en "<<a<<" "<<b << '\n';
      return st[i];
  }
  if(lazy[i]) lazy_update(i,a,b,m);
  int sl = update(L(i),a,m,qa,qb,v);
  int sr = update(R(i),m+1,b,qa,qb,v);
  st[i]=sl+sr;
  // std::cout << "update " <<" "<<a<<" "<<b<<"/ "<<sl<<" "<<sr<< '\n';
  return st[i];
}
int rmq(int i,int a,int b,int qa,int qb){
  // std::cout << "break rmq " <<" "<<a<<" "<<b<<"/ "<<qa<<" "<<qb<< '\n';

  int m=(a+b)/2;
  if(qb<a||b<qa) return 0;
  if(qa<=a&&b<=qb) {
    return st[i];}
  if(lazy[i]) lazy_update(i,a,b,m);
  int sl = rmq(L(i),a,m,qa,qb);
  int sr = rmq(R(i),m+1,b,qa,qb);
  // std::cout << "rmq " <<" "<<a<<" "<<b<<"/ "<<sl+sr<< '\n';

  return sl+sr;
}
int main(int argc, char const *argv[]) {
  int ncases,M,T,Q;
  cin>>ncases;
  for (size_t t = 1; t <= ncases; t++) {
    std::cout << "Case "<<t<<":" << '\n';
    cin>>M;
    string str;
    A="";
    for (size_t i = 0; i < M; i++) {
      cin>>T;
      cin>>str;
      for (size_t j = 0; j < T; j++) {
        A+=str;
      }
    }
    // std::cout << pirates << '\n';
    int n_pirates=A.length();

    // E(0,n_pirates);
    create();
    cin>>Q;
    char q;int a,b,count=1;
    for (size_t i = 0; i < Q; i++) {
      cin>>q;
      cin>>a>>b;
      switch (q) {
        case 'F':F(a,b);
                break;
        case 'I':I(a,b);
                break;
        case 'E':E(a,b);
                break;
        case 'S':std::cout << "Q"<<count<<": "<<S(a,b) << '\n';
                count++;
                break;
      }
    }


  }
  return 0;
}
