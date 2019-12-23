/*Solving an equation with the bisection method*/
#include <stdio.h>
#include <math.h>

float f(float x){
	return (2*x+1)*(2*x+1)-4*cos(M_PI*x);
}

int main(){
	int i=0;
	float a,b,eps,mp;
	FILE* fp;
	
	/*Input parameters*/
	printf("Insert the ends of the interval [a,b]:\n");
	scanf("%f %f",&a,&b);
	/*First control of existence via mean value theorem*/
	if(f(a)*f(b)>0){
		printf("No solution in this interval!\n");
		return 1;
	}else if(f(a)==0){
		printf("The exact solution is %.6f\n",f(a));
		return 2;
	}else if(f(b)==0){
		printf("The exact solution is %.6f\n",f(b));
		return 3;
	}
	
	printf("Insert the requested number of significative digits:\n");
	do{
		printf(">");
		scanf("%f",&eps);
		if((eps!=(int)eps || eps<=0)) printf("Insert a positive integer!\n");
	}while((eps!=(int)eps) || eps<=0);
	eps= pow(10,-1*eps);
	
	fp=fopen("calculation.dat","w");
	/*Computation of the solution*/
	while(0.5*fabs(b-a)>eps){
		mp=0.5*(b+a);
		fprintf(fp,"%d\t%10.6f\n",++i,mp);
		if(f(mp)==0){
			printf("The exact solution is %.6f\n",f(mp));
			return 4;
		}
		else if(f(a)*f(mp)<0) b=mp;
		else a=mp;
	}
	fclose(fp);
	
	printf("The found solution is %.6f within an error of %.6f\n",0.5*(b+a),0.5*fabs(b-a));
	
	return 0;
}
