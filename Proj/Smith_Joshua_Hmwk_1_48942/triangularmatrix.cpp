#include "triangularmatrix.h"

TriangularMatrix::TriangularMatrix()
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
int *TriangularMatrix::filAray(int n)
{
    int *array=new int[n];
    for(int i=0;i<n;i++){
        //array[i]=rand()%10+1;
        array[i]=i+1;
    }
    return array;
}

//Fills a 1-Dim array with the number of
//Columns per row
int **TriangularMatrix::filAray(int *cols,int nCols)
{
    //Allocates Memory
    int **array=new int*[nCols];
    for(int i=0;i<nCols;i++){
        array[i]=new int[cols[i]];
    }
    //Fill the allocated memory
    for(int row=0;row<nCols;row++){
        for(int col=0;col<cols[row];col++){
            array[row][col]=rand()%90+10;
        }
    }
    return array;
}

void TriangularMatrix::prntAry(int *array,int n)
{
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void TriangularMatrix::prntAry(int **array,int *cols,int nCols)
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

void TriangularMatrix::destroy(int **a,int *b,int c)
{
    delete []b;
    for(int i=0;i<c;i++){
        delete []a[i];
    }
    delete []a;
}

