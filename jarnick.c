#include<stdio.h>
#include<stdlib.h>

void main(){
int i,j,k;           
int n;			   
int respaldo1,respaldo2; 			        
int menor;   
int *V;			 
int **adya,**peso;	    
//------------------------------------------------
//RESERVA DE MEMORIA:

printf("Ingrese el numero de Vertices:\n");
scanf("%d",&n);
adya = (int **) malloc (n * sizeof(int *));
for (k=0 ; k < n ; k++) {
    adya[k] = (int *) malloc (n * sizeof(int));
}
peso = (int **) malloc (n * sizeof(int *));
for (k=0 ; k < n ; k++) {
    peso[k] = (int *) malloc (n * sizeof(int));
}
V = (int *) malloc (n * sizeof(int));

//--------------------------------------------------
// INICIALIZAVION DEL CONJUNTO V: 

V[0]=1;
for (k=1 ; k < n ; k++) V[k]=0;

//----------------------------------------------------
// LECTURA DE LAS MATRICES:
printf("Ingrese elementos de la matriz adyacencia:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)scanf("%d",&adya[i][j]);
getchar();
printf("Ingrese elementos de la matriz de pesos:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)scanf("%d",&peso[i][j]);

//-----------------------------------------------------
// ALGORITMO:
printf("\n\nResultado del Algoritmo:\n");

for(k=0;k<n-1;k++){
	printf("Estado N° %d:\n\n",k+1);
	menor=10000;
	for(i=0;i<n;i++){
	    if(V[i]==1){
 	       for(j=0;j<n;j++){  
	           if (peso[i][j]< menor && adya[i][j]==1 && V[i]!=V[j]){
					 menor=peso[i][j];
					 respaldo1=i;
				         respaldo2=j;
                   }
	       }
 
	    }

        }
adya[respaldo1][respaldo2]=adya[respaldo2][respaldo1]=2;
V[respaldo2]=1;

// MOSTRAMOS EL CONJUNTO DE ARISTAS Y DE VERTICES SELECCIONADOS
// HASTA LA K-ESIMA ITERACION DEL ALGORITMO:
printf("E={");
for(i=0;i<n;i++){
  for(j=i;j<n;j++) if(adya[i][j]==2) printf("{%d,%d}",i+1,j+1);
}
printf("}\nV={");
for(i=0;i<n;i++)  if(V[i]==1)  printf("%d,",i+1);
  printf("}\n\n");
}  

// FIN DE ALGORITMO.
//-----------------------------------------------------------
      		 
} // FIN DE PROGRAMA.
