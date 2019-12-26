/*Solving a linear system with the SOR Method*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
/*Determine the dimension of the matrix*/
int file_lines(FILE *fp){
	int counter = 0;
	char a;
	while(!feof(fp)){
		fscanf(fp,"%c",&a);
		if(a == '\n')
			counter++;
	}
	
	return --counter;
}
/*Allocation of a whole matrix*/
float** M_alloca(float** Mat, int LEN){
	Mat=malloc(LEN*sizeof(*Mat));
	for(int i=0;i<LEN;++i)
		Mat[i] = calloc(LEN,sizeof(Mat[i]));
	
	return Mat;
}

float maxerr(float* X,float*X0,int N){
	float max = fabs(X[0]-X0[0]);
	for(int i=1;i<N;++i){
		if(fabs(X[i]-X0[i])>max)
			max=fabs(X[i]-X0[i]);
	}
	
	return max;
}

int main(){
	float eps;
	printf("Insert the prescribed tolerance:\n");
	scanf("%f",&eps);
	
	float omega;
	printf("Insert the relaxation factor:\n");
	scanf("%f",&omega);

	FILE *fp;
	/*Coefficients matrix*/
	fp=fopen("inputA.txt","r");
	int N=file_lines(fp);
	rewind(fp);
	
	float** A=M_alloca(A,N);
	float* B=calloc(N,sizeof(*B));
	
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			fscanf(fp,"%f",&A[i][j]);
			
	fclose(fp);
	/*Known-terms vector*/
	fp=fopen("inputB.txt","r");	
	for(int i=0;i<N;++i)
		fscanf(fp,"%f",&B[i]);
	fclose(fp);
	
	float* X=calloc(N,sizeof(*X));
	float* X0=calloc(N,sizeof(*X));//we take as an initial guess the null vector
	char c;
	do{	
		for(int i=0;i<N;++i) X0[i]=X[i];
		
		for(int i=0;i<N;++i){
			X[i]= B[i];
			for(int j=0;j<i;++j)
				X[i]-=A[i][j]*X[j];
			
            for(int j=i;j<N;++j)
				X[i]-=A[i][j]*X0[j];
			
            X[i] /= A[i][i];
			X[i] *= omega;
			X[i] += X0[i];	
		}
	}while(maxerr(X,X0,N)>=eps);
	
	for(int i=0;i<N;++i) printf("X[%d]= %f\n",i,X[i]);

	return 0;
}
