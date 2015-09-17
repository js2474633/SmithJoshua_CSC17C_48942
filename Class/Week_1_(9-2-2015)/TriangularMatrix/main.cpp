/*
 * Joshua Smith
 * Sept 2nd, 2015
 * Purpose: Triangluar MAtrix
 * Hmwk: Create a templated Class implemented the matrix
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *filAray(int);
int **filAray(int*, int);
void prntAry(int *, int );
void  prntAry(int**, int *, int);
void destroy(int **, int *, int);

//Execution Begins Here
int main()
{
    //Initialize the rng
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    int col=10;
    //Fill the arrays
    int *d1aray = filAray(col);
    int **d2aray = filAray(d1aray, col);
    //Print the arrays
    prntAry(d1aray,col);
    prntAry(d2aray, d1aray,col);
    //Delete the dynamic arrays
    destroy(d2aray, d1aray, col);
    return 0;
}

void destroy(int **a, int *b, int c)
{
    delete []b;
    for(int i=0; i < c; i++)
    {
        delete []a[i];
    }
    delete []a;
}

void prntAry(int *array, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void prntAry(int **array, int *cols, int nCols)
{
    cout << endl;
    //Print allocated memory
    for(int row = 0; row < nCols; row++)
    {
        for(int col = 0; col < cols[row]; col++)
        {
            cout << array[row][col] << " ";
        }
    }
    cout << endl;
}

//Fills a 1-D array with the number of
//Columns per row
int *filAray(int n)
{
    int *array = new int[n];
    for(int i=0; i < n; i++)
    {
        array[i]=i+1;
    }
    return array;
}

//Fills a 2-D array with the number of
//Columns per row
int **filAray(int *cols, int nCols)
{
    //Allocates Memory
    int **array = new int*[nCols];
    for(int i=0; i < nCols; i++)
    {
        array[i]= new int[cols[i]];
    }
    //Fill allocated memory
    for(int row = 0; row < nCols; row++)
    {
        for(int col = 0; col < cols[row]; col++)
        {
            array[row][col] = rand()%10+1;
        }
    }
    return array;
}

