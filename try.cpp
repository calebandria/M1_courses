#include "ThomasTridiag.hpp"

using namespace std;

int main(){
    ThomasTridiag essai("input.txt");
    essai.deserializeMatrix();
    essai.displayMatrix(essai.getMatrix());
    essai.systemResolution();

    essai.displayVector(essai.getXx());

    return 0;

}