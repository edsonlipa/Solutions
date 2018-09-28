#include <bits/stdc++.h>
using namespace std;

int main (int argc , const char* argv[]){
    int T,N,n;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
      priority_queue<int> cola;
      std::cin >> N;
      for (int j = 0; j < N; j++) {
        std::cin >> n;
        cola.push(n);
      }
    std::cout << "Case "<<i+1<<": "<<cola.top() << '\n';
    }

    return 0;
}
