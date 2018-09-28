#include<bits/stdc++.h>
using namespace std;
int closest(std::vector<int>sum,int n,int key){
  int left=0;
  int right=n-1;
  while ((right-left)>1) {
    int mid=left+(right-left)/2;
    // std::cout << "l "<<left<<" mid "<<mid <<" r "<<right << '\n';
    if (key==sum[mid]) {
      return key;
    }else if (key>sum[mid]) {
      left = mid;
    }else{
      right = mid;
    }
  }
  // std::cout << "retornar  l "<<left<<" r "<<right << '\n';

  if ((key-sum[left])<=(sum[right]-key)) {
    return sum[left];
  }else{
    return sum[right];
  }

}
int main(int argc, char const *argv[]) {

  int n,m,count=0;
  cin>>n;
  while (n!=0) {
    std::vector<int> values;
    std::set<int> sumset;
    std::vector<int> sums;
    for (int i = 0; i < n; i++) {
      int a;
      std::cin >> a;
      values.push_back(a);
    }
    for (int i = 0; i < n; i++) {
      for ( int j = i; j < n; j++) {
        // std::cout <<values[i]<< " " <<values[j]<< '\n';
        if (i!=j) {
          sumset.insert(values[i]+values[j]);
        }
      }
    }
    sums.assign(sumset.begin(),sumset.end());
    count++;
    cin>>m;
    printf("Case %i:\n",count );
    for (int i = 0; i < m; i++) {
      int a;
      std::cin >> a;
      std::cout << "Closest sum to "<<a<<" is " <<closest(sums,sums.size(),a) <<"."<< '\n';
    }
    // std::cout << " sumas " << '\n';
    // for(auto i:sums){
    //   std::cout << i << ' ' ;
    // }
    // std::cout  << '\n';
    cin>>n;
  }
  return 0;
}
