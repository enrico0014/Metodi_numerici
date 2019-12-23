/*Solving an equation with the sequence-generating function method
Replace each time the formula in g properly*/
#include <stdio.h>
#include <math.h>

float g(float x){
	
	return acos((x+0.5)*(x+0.5))/M_PI;
}

int main(){
	FILE* fp;
	float xj,x,eps=0.;
	int i=0;

	/*Input of requested values*/
	printf("Insert start value:\n>");
	scanf("%f",&xj);
	
	printf("Insert the requested number of significative digits:\n");
	do{
		printf(">");
		scanf("%f",&eps);
		if((eps!=(int)eps || eps<=0)) printf("Insert a positive integer!\n");
	}while((eps!=(int)eps) || eps<=0);
	eps= pow(10,-1*eps);

	fp=fopen("calculation.dat","w");
	/*Computation of the solution*/
	x=xj;
	do{
		xj=x;
		x=g(xj);
		fprintf(fp,"%d\t%7.6f\n",++i,x);
	}while(fabs((x-xj)/x)>5*eps);
	fclose(fp);
	
	printf("The found solution is %.6f within an error of %.6f\n",x,fabs(x-xj));

	return 0;
}
