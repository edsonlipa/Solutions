#include <bits/stdc++.h>
using namespace std;
#define LSO(i) i&(-i)
#define S(x,r) update(x,r-A[x],N);
#define M(i,j) rsq(j)-rsq(i-1)
int A[200005];
long long FT[200005];
long long rsq(int i){
  long long sum=0;
  for (; i; i-=LSO(i)) {
    sum+=FT[i];
  }
  return sum;
}
void update(int k,int v,int N){
  for (; k <= N; k+=LSO(k)) {
    FT[k]+=v;
  }
}

int main(int argc, char const *argv[]) {
  int N,number,ncase=1;
  // cin>>N;
  scanf("%d",&N );
  while (N) {
    // std::cout << "N "<<N << '\n';
    for (size_t i = 1; i <= N; i++) {
      scanf("%d",&number );

      A[i]=number;
      update(i,number,N);
    }
    char action[4];
    int a,b;
    if(ncase>1)printf("\n");
    printf("Case %d:\n",ncase);
    // printf("%d\n",number );
    scanf("%s",action);
    while(strcmp(action,"END")!=0){
      scanf("%i",&a);
      scanf("%i",&b);
      if (strcmp(action,"S")==0) {
        S(a,b);
        A[a]=b;

      }else if(strcmp(action,"M")==0){
        long long suma=M(a,b);
        printf("%llu\n",suma );
        // std::cout << suma << '\n';
      }
      scanf("%s",action);
    }
    for(int i=1;i<=N;i++)FT[i]=0;
    scanf("%d",&N );
    // cin>>N;
    ncase++;

  }
  return 0;
}
