#ifndef GAUSSTRIDIAG_H
#define GUASSTRIDIAG_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class GaussTridiag{
    public:
        GaussTridiag(string filename);
        ~GaussTridiag();

        void deserializeMatrix();
        void systemResolution();
        void displayVector(double *vector);
        void displayMatrix(double **matrix);
        double** transpose(double **matrix, int row, int col);    
        
        //getter
        double **getMatrix();
        double *getAa();
        double *getBb();
        double *getCc();
        double *getYy();
        double *getXx();
        int getNn();

        //setter
        void setMatrix(double** matrix);
        void setAa(double* a);
        void setBb(double* b);
        void setCc(double* c);
        void setYy(double* y);
        void setNn(int n);

    private:
        double **matrix;
        double *a;
        double *b;
        double *c;
        double *y;
        double *x;
        int n;
        ifstream inputFile;
        double* gamma;
        double* beta;
};
#endif