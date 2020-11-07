/*Generating a sequence of normal-distributed numbers
 and check their distribution via an hystograms*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float max(int LEN, float *data){
	int i;	
	float max = *(data);
	for(i=1;i<LEN;i++)
		if(*(data+i)>max)
			max = *(data+i);
	
	return max;
}

float min(int LEN, float *data){
	int i;
	float min = *(data);
	for(i=1;i<LEN;i++)
		if(*(data+i)<min)
			min = *(data+i);
			
	return min;
}
//Media 0,varianza 1
float* boxmull(int N, float* x){
	x = calloc(N,sizeof(*x));
	float r1,r2;
	
	for(int i=0;i<N;i+=2){
		r1 = (float) rand()/RAND_MAX;
		r2 = (float) rand()/RAND_MAX;
		*(x+i)= sqrt(-2*log(r1))*cos(2*M_PI*r2);
		*(x+i+1)= sqrt(-2*log(r1))*sin(2*M_PI*r2);
	}
	
	return x;
}

int main(){

	int N,j;
	printf("How many numbers do you want to generate?\n>");
	scanf("%d",&N);

	float* x=boxmull(N,x); 
	
	int nbin;
    	printf("In how many bins do yo want to divide your hystogram?\n");
   	scanf("%d",&nbin);
    
	int* count = calloc(nbin,sizeof(*count));
	float minimum = min(N,x);
	float dx = (float) (max(N,x)-minimum)/nbin;
	for(int i=0;i<N;i++){
		j = (float) (*(x+i)-minimum)/dx;
		count[j]++;
	}
	
	FILE* fp;
	fp=fopen("results.txt","w");
   	float norm = (float) 1./(dx*N); //normalization factor
	for(int i=0;i<nbin;++i) fprintf(fp,"%f\n",*(count+i)*norm);
	fclose(fp);

	return 0;
}
