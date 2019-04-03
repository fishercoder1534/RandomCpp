// SimpleMath.cpp : Defines the entry point for the console application.
#include "SimpleMath.h"
#include <iostream>
#include <math.h>
using namespace std;
 
double squareRoot(const double a) {
    double b = sqrt(a);
    if(b != b) { // nan check
        return -1.0;
    }else{
        return sqrt(a);
    }
}

int main(int argc, char** argv) {
    cout << "program started.\n";
    cout << squareRoot(16.0) << endl;
    cout << "program finished.\n";
}
