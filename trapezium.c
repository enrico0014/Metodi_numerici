/*Integration via Trapezium Rule*/
#include <stdio.h>
#include <math.h>


float f(float x){
	
	return exp(-1*x*x);
}

float trap(float f(float),float a,float b,int N){
	float h=(float)(b-a)/N; //incremento
	
	float sum=0.;
	sum = 0.5*(f(a)+f(b));
	for(int i=1;i<N;++i) sum += f(a+i*h);
	
	return h*sum;
}

int main(){
	float a,b;
	printf("Insert the integration bound:\n");
	scanf("%f %f",&a,&b);
	
	int N;
	printf("How many subparts of the interval?\n");
	scanf("%d",&N);
	
	printf("The value computed is %f\n",trap(f,a,b,N));
	


	return 0;
}
