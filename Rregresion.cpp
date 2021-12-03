#include<stdlib.h>
#include<stdio.h>
#include<cmath>

void resolver_ecuacion(float &valor1,float matriz[],int m,int nA){
	float aux[m];
	float aux2=0;
	float aux3=0;

	for(int i=0;i<m;i++){
		aux3=matriz[i];
		aux[i]=aux3;
	}
	
	for(int j=0;j<m;j++){
		aux2=aux2+pow(aux[j],nA);
	}
	
	valor1=aux2;
}

void resolver_ecuacion2(float &valor2,float matriz[],float matriz2[],int m,int nA){
	float aux[m];
	float aux4[m];
	float aux2=0;
	float aux3=0;
	float aux5=0;
	float aux6=0;

	for(int i=0;i<m;i++){
		aux3=matriz[i];
		aux[i]=aux3;
		
	}
	
	for(int j=0;j<m;j++){
		aux5=matriz2[j];
		aux4[j]=aux5;
	}
	
	for(int k=0;k<m;k++){
		aux2=aux2+(pow(aux[k],nA)*aux4[k]);
		
	}
	
	valor2=aux2;
}

FILE *datos_Matlab;

int main(){
printf("\t\t\t\t ----INSTITUTO POLITECNICO NACIONAL---- \t\t\t\t");
printf("\n\t\t\t\t --PRACTICA NUMERO 8: MINIMOS CUADRADOS POLINOMIALES-- \n\t\t\t\t");
printf("\tVarela Murillo Leonardo 4EM1\t");
int n,m;
printf("\nIngrese el grado del polinomio y el numero de valores requeridos (n,m)");
printf("\ngrado polinomio= ");
scanf("%d",&n);
printf("numero de datos a ingresar= ");
scanf("%d",&m);
float x[m];
float y[m];
float matriz[n][n+1];
float matrizb[n];
float an=0;
float bn=0;
float *dire;
float *dire2;
dire=&an;
dire2=&bn;
int najustado=0;
printf("\ningrese los valores de x\n");
for(int i=0;i<m;i++){
	printf("\tx%d=  ",i+1);
	scanf("%f",&x[i]);
	
}

printf("ingrese los valores de y\n");
for(int j=0;j<m;j++){
	printf("\ty%d= ",j+1);
	scanf("%f",&y[j]);
	
}

printf("|------------------------------------|\n");
printf("|  i  |\t|    yi      |\t|    xi      |\n");
for(int k=0;k<m;k++){
	printf("|  %d  |\t|  %f  |\t|  %f  |\n",k+1,y[k],x[k]);
}

if((datos_Matlab=fopen("DatosMatlab.txt","w"))!=NULL){
	fprintf(datos_Matlab,"x=[");
	for(int ab=0;ab<m;ab++){
		fprintf(datos_Matlab,"\t%f,",x[ab]);
	}
	fprintf(datos_Matlab,"]");
	
	fprintf(datos_Matlab,"\ny=[");
	for(int ac=0;ac<m;ac++){
		fprintf(datos_Matlab,"\t%f,",y[ac]);
	}
	fprintf(datos_Matlab,"]");
}




for(int z=0;z<=n;z++){
	resolver_ecuacion2(*dire2,x,y,m,z);
	matrizb[z]=bn;
	bn=0;
	}

for(int l=0;l<=n;l++){
	for(int r=0;r<=n;r++){
		najustado=n+l-r;
		resolver_ecuacion(*dire,x,m,najustado);
		matriz[l][n-r]=an;
		an=0;
		
		if(l==r){
			najustado=2*n;
			resolver_ecuacion(*dire,x,m,najustado);
			matriz[n][n]=an;
			an=0;
		}
	}
}

for(int o=0;o<=n;o++){
	printf("\n");
	for(int p=0;p<=n;p++){
		printf("\t[%f]",matriz[o][p]);
	}
}

printf("\ncoeficientes B");
for(int v=0;v<=n;v++){
	printf("\n[%f]",matrizb[v]);
}

if((datos_Matlab=fopen("DatosMatlab.txt","a"))!=NULL){
	fprintf(datos_Matlab,"\na=[");
	for(int ad=0;ad<=n;ad++){
		fprintf(datos_Matlab,";");
	for(int ae=0;ae<=n;ae++){
		fprintf(datos_Matlab,"\t%f",matriz[ad][ae]);
	}
  }
fprintf(datos_Matlab,"]");
	
	fprintf(datos_Matlab,"\nb=[");
for(int af=0;af<=n;af++){
	fprintf(datos_Matlab,"\t%f",matrizb[af]);
  }
 	fprintf(datos_Matlab,"]");
 	fprintf(datos_Matlab,"\nregrMatriz(a,b,x,y)");
}

printf("\nDESPUES DE LA EJECUCION DEL PROGRAMA ENCONTRARA UN DOCUMENTO .TXT CON LOS DATOS A INGRESAR EN EL COMMAND WINDOW DE MATLAB SOLO COPIE, PEGUE Y PRESIONE ENTER");

	return 0;
}
