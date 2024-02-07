#include "GaussTridiag.hpp"

using namespace std;

int main(){
    GaussTridiag essai("input.txt");
    essai.deserializeMatrix();
    essai.displayMatrix(essai.getMatrix());
    essai.systemResolution();

    essai.displayVector(essai.getXx());

    return 0;

}