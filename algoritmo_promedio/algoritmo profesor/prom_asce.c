
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main(){
  int n,i,j,k;
  int *X;
  float *A,a,tiempo;
  for(k=1;k<10000;k=k+100){
  n=k;
  X=(int*)malloc(n*sizeof(int));
  A=(float*)malloc(n*sizeof(float));
  
  for(i=0;i<n;i++) X[i]=i;
  
  tiempo=clock();
  for(i=0;i<n;i++){
     a=0;
     for(j=0;j<=i;j++) a=a+X[j];
     A[i]=a/(i+1);	
  }
  tiempo=clock()-tiempo;
  printf("%d %f\n",n,tiempo/1000);
  }
  /*Muestra de los valores obtenidos
  for(i=0;i<n;i++) printf("%d ",X[i]);
  printf("\n");
  for(i=0;i<n;i++) printf("%.3f ",A[i]);*/
}
