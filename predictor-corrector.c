/*Solving an ODE with a fourth-order predictor-corrector
method with iterative improvement of the solution*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x, float y){
	return x+y*y;
}

int main(){
	float x0;
	printf("Insert the initial point:\n>");
	scanf("%f",&x0);
	
	float w[5];
	printf("Insert the initial value:\n>");	
	scanf("%f",&w[0]);
	for(int i=1;i<4;++i){
		printf("Insert the starting value w[%d]:\n>",i);
		scanf("%f",&w[i]);
	}
	
	float h;
	printf("Insert the lenght of spacing:\n>");
	scanf("%f",&h);
	
	int n;
	printf("Insert how many times has to be integrate:\n>");
	scanf("%d",&n);
	
	float eps;
	printf("Insert the prescribed tolerance:\n>");
	scanf("%f",&eps);
	
	float fi[5];
	for(int i=0;i<4;++i) fi[i] = f(x0+i*h,w[i]);
	/*Iterative improvement of the starting values*/
	float* wi = calloc(4,sizeof(*wi));
	do{
		for(int i=1;i<4;++i) wi[i] = w[i];
		
		w[1] = w[0] + h*(9.*fi[0]+19.*fi[1]-5.*fi[2]+fi[3])/24.;
		fi[1] = f(x0+h,w[1]);
		
		w[2] = w[0] + h*(fi[0]+4.*fi[1]+fi[2])/3.;
		fi[2] = f(x0+2.*h,w[2]);
		
		w[3] = w[0] + 3*h*(fi[0]+3.*fi[1]+3.*fi[2]+fi[3])/8.;
		fi[3] = f(x0+3.*h,w[3]);
	}while(fabs(wi[1]-w[1])>eps || fabs(wi[2]-w[2])>eps || fabs(wi[3]-w[3])>eps);
	free(wi);
	
	printf("\nx\t\ty\n");
	
	float w4,x4;
	x4 = x0+4.*h;
	/*Predictor-corrector routine*/
	for(int j=0;j<n;++j){
		/*Fourth-order predictor formula*/
		w[4] = w[3] + h*(55.*fi[3]-59.*fi[2]+37.*fi[1]-9.*fi[0]);
		do{
			/*Fourth-order corrector formula*/
			fi[4] = f(x4,w[4]);
			w4 = w[4];
			w[4] = w[3] + h*(9.*fi[4]+19.*fi[3]-5.*fi[2]+fi[1])/24.;
		}while(fabs(w4-w[4])>eps);
		/*Output*/
		printf("%7.6f\t%7.6f\n",x4,w[4]);
		/*Updating paramethers*/
		x4 += h;
		w[3] = w[4];
		fi[4] = f(x4,w[4]);
		for(int i=0;i<4;++i) fi[i] = fi[i+1];
	}
	
	return 0;
}
 
