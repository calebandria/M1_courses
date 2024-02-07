#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream inputFile("input.txt");
    
    if(!inputFile.is_open()){
        cerr << "Error: Unable to open the file." << endl;
        return 1;

    }

    double *(*values);
    double value;
    int n(0);
    double *a, *b, *c, *y;

    inputFile >> n;

    values = new double*[n];

    // allocating vectors in each line
    for(int i=0; i<n; i++){
        values[i] = new double[n];
    }

    a = new double[n];
    b = new double[n];
    c = new double[n];
    y = new double[n];

    // allocating the value in its place
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            inputFile >> value;
            *(*(values+ i)+j)= value;
        }
    }

    // allocating the values of the 2nd  member
    for(int i=0; i<n; i++){
        inputFile >> value;
        y[i] = value;
    }

    // building the value of the matrix
    for(int i=0; i<n; i++){
        b[i]= values[i][i];
    }

    for(int i=1; i<n ; i++){
        a[i-1] = values[i][i-1];
    }

    for(int i=1; i<n ; i++){
        c[i-1] = values[i-1][i];
    }

    inputFile.close();

    cout << "Values read from the file:" << endl;
    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            cout << values[i][j] << setw(10);
        }
        cout << setw(-10)<<endl;
    }

    // display the value of b vector
    cout << "Values of b: " << endl;
    for(int i=0; i<n; i++){
        cout << b[i] << endl;
    }

    cout << "Values of a: " << endl;
    for(int i=0; i<n; i++){
        cout << a[i] << endl;
    }

    cout << "Values of c: " << endl;
    for(int i=0; i<n; i++){
        cout << c[i] << endl;
    }

    cout << "Value of y: " << endl;
    for(int i=0; i<n; i++){
        cout << y[i] << endl;
    }

    delete [] *values;
    delete [] values;
    delete [] a;
    delete [] b;
    delete [] c;
    delete [] y;

    return 0;
}