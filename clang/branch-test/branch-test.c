#include<stdio.h>
#include<stdlib.h>

void main() {
  int *p;
  int i, np,nn;
  const int N=100000000;
  p=(int *)malloc(sizeof(int)*N);
  //Most of them are positive
  for (i=0;i<N;i++) {
    *(p+i)=3;
  }
  *(p+300)=-3;
  *(p+301)=-3;
  *(p+302)=-3;
  *(p+303)=-3;
  *(p+304)=-3;
  *(p+3002)=-3;
  //Most of them are negative
  /*
  for (i=0;i<N;i++) {
    *(p+i)=-3;
  }
  *(p+300)=3;
  *(p+301)=3;
  *(p+302)=3;
  *(p+303)=3;
  *(p+304)=3;
  *(p+3002)=3;
  */

  np=0;
  nn=0;
//#pragma omp parallel for default(shared)
//#pragma reduction(+:np,nn)
  for (i=0;i<N;i++) {
    if (*(p+i) == 3) 
      np++;
    else
      nn++;
  }
  printf("Postive number %d and negative number %d\n",np,nn);
}
