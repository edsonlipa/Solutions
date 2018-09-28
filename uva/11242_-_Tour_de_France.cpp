#include <bits/stdc++.h>
using namespace std;
double round2dp ( double a)
{
  a=round(a*100);
  return (double)(a/100);
}
int main(int argc, char const *argv[]) {
  int nf,nr;
  std::cin >> nf;
  while (nf!=0) {
    std::cin >> nr;
    std::vector<int> ntf;
    std::vector<double> ds;
    priority_queue<double,std::vector<double>,greater<double>> pq_ds;
    for (int i = 0; i < nf; i++) {
      int a; cin>>a;
      ntf.push_back(a);
    }
    for (int i = 0; i < nr; i++) {
      int a; cin>>a;
      for (int j = 0; j < nf; j++) {
        pq_ds.push((double)a/ntf[j]);
      }
    }
    std::cin >> nf;
    float ans=-1;
    while (pq_ds.size()>1) {
      double left = pq_ds.top();
      pq_ds.pop();
      double sr=round2dp(pq_ds.top()/left);
      if (ans<sr) {
        ans=sr;
      }
    }
    printf("%.2f\n",ans );
  }

  return 0;
}
