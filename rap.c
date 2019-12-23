/*Solving an equation with the Newton-Raphson method
Replace each time the formula in f,df properly*/
#include <stdio.h>
#include <math.h>

float f(float x){
	
	return x*x*x +2.*x+1;
}

float df(float x){
	
	return 3.*x*x+2;
}

int main(){
	FILE* fp;
	float xj,x,eps;
	int i=0;
	
	printf("Insert the starting value\n>");
	scanf("%f",&xj);
	
	printf("Insert the number of significative digits\n>");
	do{
		scanf("%f",&eps);
		if((eps!=(int)eps)) printf("Insert a positive integer!\n");
	}while((eps!=(int)eps));
	eps= pow(10,-1*eps);
	
	x=xj;
	fp=fopen("calculation.dat","w");
	do{
		xj=x;
		x=(float)xj-(f(xj)/df(xj));
		fprintf(fp,"%d\t%7.6f\n",++i,x);
	}while(fabs(x-xj)>eps);
	fclose(fp);
	
	printf("The found solution is %.6f within an error of %.6f\n",x,fabs(x-xj));

	return 0;
}
