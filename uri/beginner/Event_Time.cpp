// Accepted
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
  int t[4]={24*60*60,60*60,60,1};
  string str[4]={"dia","hora","minuto","segundo"};
  int start,end;
  long start_hour[3];
  long end_hour[3];
  scanf("Dia %d\n", &start);
  scanf("%ld : %ld : %ld\n", &start_hour[0], &start_hour[1], &start_hour[2]);
  scanf("Dia %d\n", &end);
  scanf("%ld : %ld : %ld", &end_hour[0], &end_hour[1], &end_hour[2]);
  long sfd=24*60*60;
  long sec1=start_hour[0]*60*60+start_hour[1]*60+start_hour[2];
  long sec2=end_hour[0]*60*60+end_hour[1]*60+end_hour[2];
  sec1=sfd-sec1;
  long total_time = (end-start-1)*sfd+sec1+sec2;
  for (size_t i = 0; i < 4; i++) {
    long segundos=total_time/t[i];
    // printf("%ld %s(s)\n",segundos,str[i]);
    std::cout <<segundos<< " " <<str[i]<<"(s)"<< '\n';
    total_time=total_time-(segundos*t[i]);
  }
  return 0;
}
