/*Integration via Simson's Rule*/
#include <stdio.h>
#include <math.h>

float f(float x){
	
	return pow(2*M_PI,-0.5)*exp(-0.5*x*x);
}

float simp(float f(float),float a,float b,int N){
	float h=(float)(b-a)/N; 
	
	float sum=0.;
	sum = f(a)+f(b)+4*f(a+h);
	for(int i=1;i<N/2;++i) sum += 2*f(a+2*i*h)+4*f(a+(2*i+1)*h);
	
	return h*sum/3.;
}

int main(){
	float a,b;
	printf("Insert the integration bound:\n");
	scanf("%f %f",&a,&b);
	
	int N;
	printf("How many subparts of the interval?\n");
	do{
		scanf("%d",&N);
		if((N%2)!=0) printf("Insert an even number!\n");
	}while((N%2)!=0);
	
	printf("The value computed is %f\n",simp(f,a,b,N));
	


	return 0;
}
