#include<bits/stdc++.h>
using namespace std;
 int main(int a ,char * s[]){
   float H,U,D,F;
   cin>>H;
   float tirefactor,stepsize,h;
   int day;

   while(H!=0){
     cin>>U>>D>>F;
     h=0;day=0;
     stepsize=U;
     tirefactor=F*U/100;
     // std::cout <<H<< " --- " <<U<< " --- " <<D<< " --- " <<F<<"  == "<<tirefactor << '\n';
     while(1){
       day++;
       // std::cout << "day "<<day <<" heith "<<h  << '\n';
       h+=stepsize;
        if (h>H) {
          std::cout << "success on day "<<day << '\n';
          break;
        }
        h=h-D;
        // std::cout << "    stepsize   "<<stepsize<<" menos "<<D<<"   heith  "<< h << '\n';
        if (stepsize>0)
          stepsize-=tirefactor;

        if (h<0) {
          std::cout << "failure on day " <<day<< '\n';
          break;

        }
     }
     cin>>H;
   }
   return 0;
 }
