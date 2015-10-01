/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 23, 2015, 8:27 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int coeff(int,int);
unsigned int fib(unsigned int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int nRows=20;
    //Loop on rows and columns
    for(int row=1;row<=nRows;row++){
        for(int col=1;col<=row;col++){
            cout<<coeff(row,col)<<" ";
        }
        cout<<endl;
    }
    //For the fibonacci
    unsigned int nFib=47;
    for(unsigned int i=47;i<=nFib;i++){
        cout<<fib(i)<<endl;
    }
    //Exit stage right
    return 0;
}

unsigned int fib(unsigned int n){
    if(n<=2)return 1;
    return fib(n-1)+fib(n-2);
}

int coeff(int r,int c){
    static int count;
    count++;
    if(r<1||c<1)return 0;
    if(c==1)return 1;
    if(r==c)return 1;
    //if(r==20)cout<<"r="<<r<<"c="<<c<<"count="<<count<<endl;
    return coeff(r-1,c-1)+coeff(r-1,c);
}