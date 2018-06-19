#include<stdio.h>
#include<stdlib.h>

void main(){
FILE* fichero;
int i,j,k;           
int n,opcion;			   
int respaldo1,respaldo2; 			        
int menor;   
int *V;			 
int **adya,**peso;	    
//------------------------------------------------
do{
//MENU PARA ELEGIR GRAFO A EVALUAR:
do{
printf("\n\nElige el grafo a evaluar:\n1. Grafo1\n2. Grafo2\n3. Grafo3\n4. Grafo4\n5. Grafo5\n6. No elegir y Salir\n\n");
scanf("%d",&opcion);
switch(opcion){
case 1  :fichero = fopen("Grafo1.txt", "rt");break;
case 2  :fichero = fopen("Grafo2.txt", "rt");break;
case 3  :fichero = fopen("Grafo3.txt", "rt");break;
case 4  :fichero = fopen("Grafo4.txt", "rt");break;
case 5  :fichero = fopen("Grafo5.txt", "rt");break;
case 6  :printf("ADIOS\n");break;
default :printf("Opcion incorrecta! VUELVA A INTENTARLO\n\n");break;
}
}while(opcion<1||opcion>6);
//RESERVA DE MEMORIA:
if(opcion!=6){
fscanf(fichero,"%d",&n);

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
for(i=0;i<n;i++)
for(j=0;j<n;j++)fscanf (fichero, "%d",&adya[i][j]);
for(i=0;i<n;i++)
for(j=0;j<n;j++)fscanf (fichero, "%d",&peso[i][j]);

//-----------------------------------------------------

// ALGORITMO:
printf("\n\nResultado del Algoritmo:\n");
printf("------------------------------------------------------------------\n\n");
printf("E0={}\n\nV0={1}\n\n");
for(k=0;k<n-1;k++){
	menor=10000;
	for(i=0;i<n;i++){
	    if(V[i]==1){
 	      for(j=0;j<n;j++){  
	        if (peso[i][j]< menor&&adya[i][j]==1&&V[i]!=V[j]){
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
printf("------------------------------------------------------------------\n\n");
printf("E%d={",k+1);
for(i=0;i<n;i++){
  for(j=i;j<n;j++) if(adya[i][j]==2) printf("{%d,%d},",i+1,j+1);
}
printf("\b}\n\nV%d={",k+1);
for(i=0;i<n;i++)  if(V[i]==1)  printf("%d,",i+1);
  printf("\b}\n\n");
} 
printf("\n");
// FIN DE ALGORITMO.
//-----------------------------------------------------------
}
printf("------------------------------------------------------------------\n\n");
}while(opcion!=6);
} // FIN DE PROGRAMA.
