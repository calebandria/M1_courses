#include "GaussTridiag.hpp"

GaussTridiag::GaussTridiag(string filename){
    inputFile.open(filename);

    if(!inputFile.is_open()){
    cerr << "Error: Unable to open the file." << endl;
    }

    inputFile >> n;
    matrix = new double*[n];
    a = new double[n];
    b = new double[n];
    c = new double[n];
    y = new double[n]; //2nd member
    x = new double[n];  //solution

    //for resolution
    gamma = new double[n];
    beta = new double[n];

}

void GaussTridiag::deserializeMatrix(){
    
    double intermediateValue(0);
    // allocation of the values of the matrix
    for(int i=0; i<n; i++){
        matrix[i] = new double[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            inputFile >> intermediateValue;
            *(*(matrix+ i)+j)= intermediateValue;
        }
    }

    // allocation of the values of the vectors a, b, c, y
    for(int i=0; i<n; i++){
        b[i]= matrix[i][i];
    }

    for(int i=1; i<n ; i++){
        a[i-1] = matrix[i][i-1];
        c[i-1] = matrix[i-1][i];
    }
    a[n-1] = a[n-2];
    c[n-1] = c[n-2];

    for(int i=0; i<n; i++){
        inputFile >> intermediateValue;
        y[i] = intermediateValue;
    }

    inputFile.close();

}

void GaussTridiag::displayVector(double *vector){
    cout << "Vector: " << endl;
    for(int i=0; i<n; i++){
        cout << vector[i] << endl;
    }
}

void GaussTridiag::displayMatrix(double **matrix){
    cout << "Matrix:" << endl;
    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << setw(10);
        }
        cout << setw(-10) << endl;
    }
}

GaussTridiag::~GaussTridiag(){
    for(int i=0; i<n ; i++)
        delete [] matrix[i];
    delete [] matrix;
    delete [] a;
    delete [] b;
    delete [] c;
    delete [] y;
    delete [] x;
    delete [] gamma;
    delete [] beta;
}

//getter
double** GaussTridiag::getMatrix(){
    return matrix;
}
double* GaussTridiag::getAa(){
    return a;
}
double* GaussTridiag::getBb(){
    return b;
}
double* GaussTridiag::getCc(){
    return c;
}
double*  GaussTridiag::getYy(){
    return y;
}

double*  GaussTridiag::getXx(){
    return x;
}
int  GaussTridiag::getNn(){
    return n;
}

//setter
void GaussTridiag::setMatrix(double** newMatrix){
    matrix = newMatrix;
}
void GaussTridiag::setAa(double* newAa){
    a = newAa;
}
void GaussTridiag::setBb(double* newBb){
    b = newBb;
}
void GaussTridiag::setCc(double* newCc){
    c = newCc;
}
void GaussTridiag::setYy(double* newYy){
    y = newYy;
}
void GaussTridiag::setNn(int newNn){
    n = newNn;
}

void GaussTridiag::systemResolution(){
    for(int i=1; i<=n ; ++i){
        gamma[i] = -c[i - 1] / (a[i - 1] * gamma[i - 1] + b[i - 1]);
        beta[i] = (y[i - 1] - a[i - 1] * beta[i - 1]) / (a[i - 1] * gamma[i - 1] + b[i - 1]);
    }

     // Step 3: Set xn+1 = 0
    x[n] = 0.0;

    // Step 4: Find xi for i = n+1,...,2
    for (int i = n; i >= 1; --i) {
        x[i - 1] = gamma[i] * x[i] + beta[i];
    }
}