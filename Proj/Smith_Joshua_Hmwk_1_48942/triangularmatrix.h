#ifndef TRIANGULARMATRIX_H
#define TRIANGULARMATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class TriangularMatrix
{
private:
    int col;
    int *d1ary;
    int **d2ary;
public:
    TriangularMatrix();

    int *filAray(int);
    int **filAray(int*,int);
    void prntAry(int *,int);
    void prntAry(int **,int *,int);
    void destroy(int **,int *,int);
};

#endif // TRIANGULARMATRIX_H
