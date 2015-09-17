/*
 * Joshua Smith
 * Sept 7, 2015
 * Purpose:  Tranigular Matrix
 * Hmwk:  Create a templated Class implmented the Matrix
*/

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "triangularmatrix.h"
using namespace std;

template<class T>
class TriangularMatrix
{
private:
    T col;
    T *d1ary;
    T **d2ary;
public:
    TriangularMatrix();

    T *filAray(T);
    T **filAray(T*,T);
    void prntAry(T *,T);
    void prntAry(T **,T *,T);
    void destroy(T **,T *,T);
};


template<class T>
TriangularMatrix<T>::TriangularMatrix()
{
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    col = 10;
    //Fill the arrays
    d1ary = filAray(col);
    d2ary = filAray(d1ary,col);
    //Print the arrays
    prntAry(d1ary,col);
    prntAry(d2ary,d1ary,col);
    //Delete the dynamic arrays
    destroy(d2ary,d1ary,col);
}

//Fills a 1-Dim array with the number of
//Columns per row
template <class T>
T *TriangularMatrix<T>::filAray(T n)
{
    T *array=new T[n];
    for(int i=0;i<n;i++){
        //array[i]=rand()%10+1;
        array[i]=i+1;
    }
    return array;
}

//Fills a 1-Dim array with the number of
//Columns per row
template <class T>
T **TriangularMatrix<T>::filAray(T *cols,T nCols)
{
    //Allocates Memory
    T **array=new T*[nCols];
    for(int i=0;i<nCols;i++){
        array[i]=new T[cols[i]];
    }
    //Fill the allocated memory
    for(T row=0;row<nCols;row++){
        for(T col=0;col<cols[row];col++){
            array[row][col]=rand()%90+10;
        }
    }
    return array;
}

template <class T>
void TriangularMatrix<T>::prntAry(T *array,T n)
{
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

template <class T>
void TriangularMatrix<T>::prntAry(T **array,T *cols,T nCols)
{
    cout<<endl;
    //Print the allocated memory
    for(int row=0;row<nCols;row++){
        for(int col=0;col<cols[row];col++){
            cout<<array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template <class T>
void TriangularMatrix<T>::destroy(T **a,T *b,T c)
{
    delete []b;
    for(int i=0;i<c;i++){
        delete []a[i];
    }
    delete []a;
}


//Execution Begins Here
int main()
{
    try{
        TriangularMatrix<int> i;
    }

    catch (exception const ex) {
        cerr << "Exception: " << ex.what() <<endl;
        return 0;
    }
}








