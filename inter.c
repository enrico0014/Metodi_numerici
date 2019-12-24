/*Gregory-Newton interpolation*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Finding the nearest point of the array*/
int near(float* x, float xi,float h){
	int j;
	float m;
	
	m=(float) (xi-(*x))/h;
	if((m-(int)m)<0.5) j=(int)m;
	else j=(int)m+1;
	
	return j;
}
/*Forward Gregory-Newton formula*/
float* forward(float* f,float* x, float xi,float h,int j,int len, int k){
	float b=1.;
	float fj=f[j];
	float* results=calloc(2,sizeof(*results));

	float r=(float) (xi-*(x+j))/h;
	for(int m=1;m<=k;++m){
		b*=(float)(r-(m-1))/m;
		for(int i=j;i<len-m;++i){
			*(f+i)=*(f+i+1)-*(f+i);
		}
		fj+=b*f[j];
	}

	results[0]=fj;
	results[1]=fabs(b*f[j]);
	
	return results; 
}
/*Backward Gregory-Newton formula*/
float* backward(float* f,float* x, float xi,float h,int j,int len, int k){
	float b=1.;
	float fj=f[j];
	float* results=calloc(2,sizeof(*results));
	
	float r=(float) (xi-*(x+j))/h;

	b=1.;
	for(int m=1;m<=k;++m){
		b*=(float)(r+(m-1))/m;
		for(int i=j;i>m;--i){
			*(f+i)=*(f+i)-*(f+i-1);
		}
		fj+=b*f[j];
	
	}
	
	results[0]=fj;
	results[1]=fabs(b*f[j]);
	
	return results; 
}

int main(){
	int len,k,m;
	float h,xi,fj,r,b;
	
	printf("Insert the amount of data:\n");
	scanf("%d",&len);
	
	float* x=calloc(len,sizeof(x));
	float* f=calloc(len,sizeof(f));
	
	printf("Insert the maximum grade of the polynomial:\n");
	scanf("%d",&k);
	
	printf("Insert x[0]:\n");
	scanf("%f",x);
	
	printf("Insert the finite increment h:\n");
	scanf("%f",&h);
	
	for(int i=1;i<len;++i) *(x+i)=*(x+i-1)+h;
	
	/*Input data*/
	for(int i=0;i<len;++i){
		printf("Insert f[%d]:\n",i);
		scanf("%f",f+i);
	}
	
	printf("Insert the interpolating point:\n");
	scanf("%f",&xi);

	int j=near(x,xi,h);
	if(j<len-j){
		if(j>=(len-k)){
			printf("Error: not enough values\n");
			return 1;
		}
	
        float* results = forward(f,x,xi,h,j,len,k);
		
		printf("The result is %f whithin an error of ",*results);
		printf("%f\n",*(results+1));
		
	}else{
		if(j<k-1){
        		printf("Error: not enough values\n");
            	return 1;
        	}
       
        float* results = backward(f,x,xi,h,j,len,k);
        
		printf("The result is %f whithin an error of ",*results);
		printf("%f\n",*(results+1));
       
	}
	
	free(x);
	free(f);
	
    return 0;
}
