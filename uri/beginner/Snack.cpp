// Accepted
#include <stdio.h>
#include <iostream>
using namespace std;
float table[] ={4.0,4.5,5,2,1.5};
int main() {
  int a;
  float b;
  std::cin >> a >> b;
  float c=b*table[a-1];
  printf("Total: R$ %.2f\n",c );
  return 0;
}
