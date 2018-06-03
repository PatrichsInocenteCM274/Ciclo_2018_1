#include<stdio.h>
#include<stdlib.h>

void main(){
int i,j,k,l,t;           
int n,sum=0;			   
int x,y; 			        
int menor;   
int *V,*Va,*registro;			 
int **adya,**peso,**Arbol;	

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
Arbol = (int **) malloc (n * sizeof(int *));
for (k=0 ; k < n ; k++) {
    Arbol[k] = (int *) malloc (n * sizeof(int));
}
V = (int *) malloc (n * sizeof(int));// GUARDA EL ESTADO ANTERIOR DE LAS ETIQUETAS
registro = (int *) malloc (n * sizeof(int));
Va = (int *) malloc (n * sizeof(int));// GUARDA EL ESTADO ACTUAL DE LAS ETIQUETAS

// INICIALIZAVION DEL CONJUNTO V y de registro: 

for (k=0 ; k < n ; k++) V[k]=k;
for (k=0 ; k < n ; k++) Va[k]=k;
for (k=0 ; k < n ; k++) registro[k]=0;
for (i=0 ; i < n ; i++)
 for (j=0 ; j < n ; j++)
  Arbol[i][j]=0;

// LECTURA DE LAS MATRICES:
printf("Ingrese elementos de la matriz adyacencia:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)scanf("%d",&adya[i][j]);
getchar();
printf("Ingrese elementos de la matriz de pesos:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)scanf("%d",&peso[i][j]);


//-----------------------------------------------------------------------------------------------------------------------------------------
// ALGORITMO:
printf("\n\nResultado del Algoritmo:\n");

while(sum<n){
for (k=0 ; k < n ; k++){  // RECORRE TODAS LAS COMPONENTES QUE EXISTEN CON ETIQUETA K.
	menor=10000;
   for (i=0 ; i < n ; i++){
		if(V[i]==k){// EVALUA SOLO LOS VERTICES QUE PERTENECEN A LA COMPONENTE CON ETIQUETA K
			   
    	                   for(j=0;j<n;j++){
			   //CALCULANDO LA ARISTA CON MENOR PESO DE LA COMPONENTE CON ETIQUETA K-------------
	                        if (adya[i][j]==1 && menor>peso[i][j] && V[i]!=V[j]){
 					 
					 menor=peso[i][j];
					 x=i; // SE SALVAGUARDA LA POSICION DE LA ARISTA ELEGIDA
				         y=j;
			        }
		          //------------------------------------------------------------------------------------------------------
			  }
                //registro[i]=1; // SE DEJA RASTRO DE QUE PASAMOS POR AQUI.
                } 
   }
   // LUEGO DE TENER UNA ARISTA NUEVA, DOS COMPONENTES SE VUELVEN UNA SOLA, Va[] GUARDARA LA
   // NUEVA CONFIGURACION DE ETIQUETAS:
   //registro[x]=1;
   //if(registro[y]==1)//SIGNIFICA QUE YA SE LE ASIGNO UNA ETIQUETA ANTES.
 if(registro[y]==1){
  for(t=0;t<n;t++)if(Va[t]==V[x])Va[t]=Va[y];
}                                    // POR LO TANTO SOLO PINTAMOS LA ETIQUETA NO PINTADA.
 else {
for(t=0;t<n;t++){if(Va[t]==V[y]){Va[t]=Va[x];}}
 registro[y]=1;
  }
Arbol[x][y]=Arbol[y][x]=1; // LA ARISTA ELEGIDA SE ESCRIBE EN EL GRAFO DE ADYACENCIA DEL ARBOL BUSCADO.
}
printf("E={");
for(i=0;i<n;i++){
  for(j=i;j<n;j++) if(Arbol[i][j]==1) printf("{%d,%d}",i+1,j+1);
}printf("}\n");
for (k=0 ; k < n ; k++)V[k]=Va[k];
for (k=0 ; k < n ; k++)registro[k]=0;
for(k=0;k<n;k++) if(V[k]==0) sum++;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------



}		






