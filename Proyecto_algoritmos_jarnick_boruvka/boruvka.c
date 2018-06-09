#include<stdio.h>
#include<stdlib.h>

void main(){
//----------------------------------------------------------------------------------

//VARIABLES A USAR:
FILE* fichero;
int i,j,k,l,t;           
int n,bandera,opcion;			   
int x,y; 			        
int menor;   
int *V,*Va;   // Los usaremos como vectores de etiquetas.
int *registro; // registará que vertices han sido pintados.			 
int **adya,**peso,**Arbol;	

//----------------------------------------------------------------------------------
do{
//MENU PARA ELEGIR GRAFO A EVALUAR:
do{
printf("Elige el grafo a evaluar:\n1. Grafo1\n2. Grafo2\n3. Grafo3\n4. Grafo4\n5. Grafo5\n6. No elegir y Salir\n");
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
bandera=1;
fscanf(fichero,"%d",&n);

adya = (int **) malloc (n * sizeof(int *));
for (k=0 ; k < n ; k++) adya[k] = (int *) malloc (n * sizeof(int));

peso = (int **) malloc (n * sizeof(int *));
for (k=0 ; k < n ; k++) peso[k] = (int *) malloc (n * sizeof(int));

Arbol = (int **) malloc (n * sizeof(int *));
for (k=0 ; k < n ; k++) Arbol[k] = (int *) malloc (n * sizeof(int));

V = (int *) malloc (n * sizeof(int));  

registro = (int *) malloc (n * sizeof(int));

Va = (int *) malloc (n * sizeof(int)); 
//-----------------------------------------------------------------------------------

// INICIALIZACION DE CONJUNTOS Y MATRICES: 

for (k=0 ; k < n ; k++) V[k]=k; 
for (k=0 ; k < n ; k++) Va[k]=k;
for (k=0 ; k < n ; k++) registro[k]=0;
for (i=0 ; i < n ; i++) for (j=0 ; j < n ; j++) Arbol[i][j]=0;
//-----------------------------------------------------------------------------------

// LECTURA DE LAS MATRICES:

for(i=0;i<n;i++) for(j=0;j<n;j++) fscanf (fichero, "%d",&adya[i][j]);

for(i=0;i<n;i++) for(j=0;j<n;j++) fscanf (fichero, "%d",&peso[i][j]);

//-----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// ALGORITMO:
printf("\n\nResultado del Algoritmo:\n");

while(bandera==1){
bandera=0;
for (k=0 ; k < n ; k++){   // Recorre todas las componentes con etiqueta k.
	menor=10000; 
    for (i=0 ; i < n ; i++){
        if(V[i]==k){   // Evalua solo los vertices "i" que tienen la etiqueta k.
			    
        // Calculamos la arista con menor peso,saliendo de cualquier vertice 
        // de la componente k,salvando la posicion con las variables x e y.
    	  for(j=0;j<n;j++){
	      if (adya[i][j]==1 && menor>peso[i][j] && V[i]!=V[j]){
		 menor=peso[i][j];
		 x=i; 
		 y=j;
	         }
              }
          } 
   }
// Luego de tener una arista nueva,dos componentes se vuelven una,y *Va 
// guarda la nueva configuracion de etiquetas:

 registro[x]=1; // Se deja registro de que pasamos por el vertice x.

//-> Si el vertice "y" ya ha sido pintado:
 if(registro[y]==1){ 
// Pintamos todas las etiquetas que tienen valor V[x] con Va[y]
 for(t=0;t<n;t++)if(Va[t]==V[x])Va[t]=Va[y]; 
 }         
           
//-> Si el vertice "y" aun no ha sido pintado:
 else {            
// Pintamos todas las etiquetas que tienen valor V[y] con Va[x]  
 for(t=0;t<n;t++)if(Va[t]==V[y])Va[t]=Va[x]; 
 registro[y]=1; // Registramos que estamos pintando el vertice y.
 }
 Arbol[x][y]=Arbol[y][x]=1; // La arista se registra en nuestro arbol.
}

// Se actualiza el vector de etiquetas con el vector de etiquetas modificado:
for (k=0;k<n;k++)V[k]=Va[k];  
// Los valores de registro vuelven a cero,listo para una nueva iteracion.  
for (k=0;k<n;k++)registro[k]=0;  

// Imprimimos todas las aristas de nuestroo arbol:
printf("\nE={");
for(i=0;i<n;i++) for(j=i;j<n;j++) if(Arbol[i][j]==1) printf("{%d,%d}",i+1,j+1);
printf("}\n");

for(k=0;k<n-1;k++) if(V[k]!=V[k+1]) bandera=1 ;
// Si no se logra entrar a  "if(V[k]!==V[k+1])" ni una sola vez,significara 
// que todas las etiquetas tienen un solo valor,por lo cual bandera seguira 
// con valor 0,terminando con el bucle while.
}

//----------------------------------------------------------------------------------
printf("\n\n");
}
}while(opcion!=6);
}// FIN DE PROGRAMA.		






