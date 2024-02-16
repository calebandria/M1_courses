#include <cmath>
#include <iostream>
using namespace std;
/* f should be N-1 and M-1*/
void TFD1(int tridiagDimN, int bigSystemSizeM, double x_len, double y_len, double Dir_top, double Dir_bottom, double Dir_right, double Dir_left, double **f){
    double **S = new double*[tridiagDimN];

    double dx(0), dy(0), alpha(0), beta(0), gamma(0);
    double** q = new double*[bigSystemSizeM];
    double** etha = new double*[bigSystemSizeM];
    double *d, *delta;
    //rename system and tridiagonal matrix dimension
    int M(bigSystemSizeM), N(tridiagDimN);

    //steps definition
    dx = x_len/(N+1) ;
    dy = y_len/(M+1) ;

    //alpha and beta definition
    alpha = -pow(dx,2)/ pow(dy,2);
    beta = pow(dy,2) * ((2/pow(dx,2)) +(2/pow(dy,2)));
    gamma = 1/pow(dy,2);

    //eigenvectors
    for(int i=0; i< M; i++){
        q[i] = new double[i];
    }

    for(int j=0; j< M; j++){
        for(int l=0; l< M; l++){
            q[l][j] = sqrt(2/(M+1))* sin((M_PI*j*l)/(M+1));
        }
    }

    // eigenvalues
    d = new double[M];
    delta = new double[M];

    for(int j=0; j< M; j++){
        d[j] = 2 + 2*(pow(dx/dy,2)*(1-cos((M_PI*j)/(M+1))));
        delta[j] = -1;
    }

    // calculate the second member etha
    for(int i=0; i<M; i++){
        S[i] = new double[M];
    }

    for(int i =0; i<N;i++){
        if(i==0){ // first line second members
            S[i][0] = f[i][0] - gamma*Dir_right - alpha*Dir_bottom; //first col
            for(int j=1;j<M-1; j++){
                S[i][j] = f[i][j] - gamma*Dir_right;  //second colum to M-1 column
            }
            S[i][M-1] = f[i][M-1] - gamma*Dir_right - alpha*Dir_top; // M-th colummn
        }
        else if(i>0 && i<N-1){
            S[i][0] = f[i][0] - alpha*Dir_bottom;
            for(int j=1;j<M-1; j++){
                S[i][j] = f[i][j];
            }
            S[i][M-1] = f[i][M-1] - alpha*Dir_top;
        }
        else if(i==N-1){
            S[i][0] = f[i][0] - alpha*Dir_bottom - gamma*Dir_left;
            for(int j=1;j<M-1; j++){
                S[i][j] = f[i][j] - gamma*Dir_left;
            }
            S[i][M-1] = f[i][M-1] - alpha*Dir_top - gamma*Dir_left;
        }

    }
    for(int i=0; i< N; i++){
        etha[i] = new double[i];
    }
    etha = multiplication(transpose(q,M,M), S, M, M, M, M);
}

double** transpose(double **matrix, int row, int col){
    double** transposedMatrix = new double*[row];
    for (int i = 0; i < row; ++i) {
        transposedMatrix[i] = new double[col]; 
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
    return transposedMatrix;
    
    for(int i = 0; i< row ; i++)
            delete[] transposedMatrix[i];
    delete [] transposedMatrix;
}

double** multiplication(double **M1, double **M2, int row1, int row2, int col1, int col2){

    if(col1 != row2){
        cerr << "Impossible multiplication" << endl;
        return 0;
    }
    else{
        double **result = new double*[row1]();
        for(int i = 0; i< row1 ; i++){
            result[i] = new double[col2]();
        }
        
        for(int i = 0; i< row1; i++){
            for(int j=0; j< col2; j++){
                result[i][j] += M1[i][j] * M2[j][i];
            }
        }
        return result;

        for(int i = 0; i< row1 ; i++)
            delete[] result[i];
        delete [] result;
        
    }
}