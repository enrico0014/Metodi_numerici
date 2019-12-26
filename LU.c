/*Solve a linear system with LU Decomposition Method*/
#include <stdio.h>
#include <stdlib.h>

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
/*Allocation of a half-matrix*/
float** M_h_alloca(float** Mat,int LEN){
	Mat = malloc(LEN*sizeof(*Mat));
	for(int i=0;i<LEN;++i)
		Mat[i] = calloc(i+1,sizeof(Mat[i]));
	
	return Mat;
}
/*Backward substitution*/
float* backsos(float** A, float* B, int N){
	float* X=calloc(N,sizeof(*X));
	for(int i=N-1;i>=0;--i){
		X[i] = B[i];
		for(int j=i+1;j<N;++j)
			X[i] -= A[i][j]*X[j];
            
		X[i] /= A[i][i];
	}
	
	return X;
}
/*Forward substituion*/
float* forsos(float** A, float* B, int N){
	float* X=calloc(N,sizeof(*X));
	for(int i=0;i<N;++i){
		X[i] = B[i];
		for(int j=0;j<i;++j)
			X[i] -= A[i][j]*X[j];
		
		X[i] /= A[i][i];
	}
	
	return X;
}

int main(){
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
	
	float** L=M_h_alloca(L,N);
	float** U=M_h_alloca(U,N);
	
	/*First row of U and first coloumn of L*/
	U[0][0]=A[0][0];
	for(int i=1;i<N;++i){
		U[0][i]=A[0][i];
		L[i][0]=A[i][0]/U[0][0];
	}
	/*Diagonal of L (Doolittle's Method)*/
	for(int i=0;i<N;++i) L[i][i]=1.;
	
	for(int i=1;i<N;++i){
		U[i][i] = A[i][i];
		for(int k=0;k<i;++k){
			U[i][i] -= L[i][k]*U[k][i];
		}
		
		for(int j=i+1;j<N;++j){
			U[i][j] = A[i][j];
			L[j][i] = A[j][i];
			for(int k=0;k<i;++k){
				U[i][j] -= L[i][k]*U[k][j];
				L[j][i] -= L[j][k]*U[k][i];
			}
			L[j][i] /= U[i][i];
		}
	}
	printf("The result of the LU Decomposition is the following:\n");
	printf("L matrix:\n");
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			printf("%.6f\t",L[i][j]);
		}
		printf("\n");
	}
	printf("\nU matrix:\n");
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			printf("%f\t",U[i][j]);
		}
		printf("\n");
	}
	
	float* Z=forsos(L,B,N);
	float* X=backsos(U,Z,N);
    
    printf("\nThe solution of the system is:\n");
	for(int i=0;i<N;++i) printf("X[%d] = %f\n",i,X[i]);
	
	free(A);
	free(B);
	free(L);
	free(U);
	free(X);
	free(Z);
	
	return 0;
}
