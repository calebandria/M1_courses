#include "GaussTridiag.hpp"

using namespace std;

int main(){
    GaussTridiag essai("input1.txt");
    essai.deserializeMatrix();
    essai.displayMatrix(essai.getMatrix());
    essai.displayMatrix(essai.transpose(essai.getMatrix(), essai.getNn(), essai.getNn()));
    essai.displayMatrix(essai.getMatrix());
}