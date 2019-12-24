/*Solvin an initial-value problem with Heun's method*/
#include <stdio.h>
#include <math.h>

float f(float x, float y){

	return -2*(x-1)*y;
}

/*Heun's method (RK2)*/
float heun(float x0, float y0, float h,int n){
	float k0,k1;
	for(int i=0;i<n;++i){
		k0=h*f(x0,y0);
		k1=h*f(x0+h,y0+k0);
		y0+=0.5*(k0+k1);
		x0+=h;	
	}
	
	return y0;
}

int main(){
	int n;
	float x0,h,y0;
	printf("Insert the initial-value in abscissa:\n");
	scanf("%f",&x0);
	
	printf("Insert the initial-value in ordinate:\n");
	scanf("%f",&y0);
	
	printf("Insert the lenght of the spacing:\n");
	scanf("%f",&h);
	
	printf("Insert how many value are ought to be computed:\n");
	scanf("%d",&n);
	


	printf("\ny(%f)=%f\n",x0+n*h,heun(x0,y0,h,n));
	
	return 0;
}
