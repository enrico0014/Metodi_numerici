/*Solving an initial-value problem via fourth-order Runge-Kutta*/
#include <stdio.h>
#include <math.h>

float f(float x, float y){

	return x*x+y/x;;
}

/*RK4 Method*/
float RK4(float x0, float y0, float h,int n){
	float k0,k1,k2,k3;
	for(int i=0;i<n;++i){
		k0=h*f(x0,y0);
		k1=h*f(x0+0.5*h,y0+0.5*k0);
		k2=h*f(x0+0.5*h,y0+0.5*k1);
		k3=h*f(x0+h,y0+k2);
		y0+=(k0+2*k1+2*k2+k3)/6.;
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

	printf("y(%f)=%f\n",x0+n*h,RK4(x0,y0,h,n));

	return 0;
}
