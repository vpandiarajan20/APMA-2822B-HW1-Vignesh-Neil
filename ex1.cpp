#include <stdio.h>

int main(){
  int i, j, k;
  double a,b,c;


  i = 1;
  j = 2;
  k = i+j;
  a = b = 3.5;
  c = a*a-b/a;
  fprintf(stdout,"i+j = %d\n",k);
  fprintf(stdout,"a*a-b/a = %g\n",c);
  return 0;
}




