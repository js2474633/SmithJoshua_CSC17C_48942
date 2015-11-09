/* 
    Dr. Mark E. Lehr
    March 25th, 2015
    Purpose:  Recursion Examples
 */


//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants

//User Libraries

//Function Prototypes
void towers(int,int,int,int);
double rSin(double);
double rCos(double);
int max(int *a,int beg,int end);
int gcd(int m,int n);
int bcoeff(int n,int k);

//Execution Begins Here
int main(int argc, char** argv) {
    
           //Test out the Recursive Binomial Coefficient
       //function
       int nLim=5;
       for(int n=0;n<=nLim;n++){
           for(int k=0;k<=n;k++){
               cout<<bcoeff(n,k)<<" ";
           }
           cout<<endl;
       }
       //Test out the Greatest Common Denominator
       cout<<"\n460/69 gcd = "<<gcd(460,69)<<endl;
       cout<<"\n35/17 gcd = "<<gcd(35,17)<<endl;
       cout<<"\n52/7 gcd = "<<gcd(52,7)<<endl;
       int num=460, den=69, snum, sden;
       int gcdval=gcd(num,den);
       snum=num/gcdval;sden=den/gcdval;
       cout<<"\n"<<num<<"/"<<den<<"="<<snum<<"/"<<sden<<endl;
       //Test out the max function
       int a1[]={5,4,3,2,1};
       int a2[]={2,3,5,4,1};
       int a3[]={1,2,3,4,5};
       cout<<"\nMax value in the array = "<<max(a1,0,sizeof(a1)/sizeof(int))<<endl;
       cout<<"\nMax value in the array = "<<max(a2,0,sizeof(a2)/sizeof(int))<<endl;
       cout<<"\nMax value in the array = "<<max(a3,0,sizeof(a3)/sizeof(int))<<endl;
       //Mutual Recursion
       double angle=30*atan(1)/45;
       cout<<"\nSystem sin("<<angle<<")="<<sin(angle)<<endl;
       cout<<"\nMy sin("<<angle<<")="<<rSin(angle)<<endl;
       cout<<"\nSystem cos("<<angle<<")="<<cos(angle)<<endl;
       cout<<"\nMy cos("<<angle<<")="<<rCos(angle)<<endl;
       //Output the process for solving the towers of hanoi
       cout<<"The Towers of Hanoi"<<endl;
       towers(2,1,2,3);

    return 0;
}

    
void towers(int nDisk,int src,int spare,int dest){
    if(nDisk>1)towers(nDisk-1,src,dest,spare);
    cout<<"Move -> "<<src<<" to -> "<<dest<<endl;
    if(nDisk>1)towers(nDisk-1,spare,src,dest);
}
    
double rSin(double angle){
    double tol=1e-8;
    if(angle>-tol&&angle<tol)return angle-angle*angle*angle/6;
    return 2*rSin(angle/2)*rCos(angle/2);
}
    
double rCos(double angle){
    double tol=1e-8;
    if(angle>-tol&&angle<tol)return 1-angle*angle/2+angle*angle*angle*angle/24;
    double cosv=rCos(angle/2);
    double sinv=rSin(angle/2);
    return cosv*cosv-sinv*sinv;
}
    
int max(int *a,int beg,int end){
    if(end-beg<=1)return a[beg];
    int half=(beg+end)/2;
    int m1=max(a,beg,half);
    int m2=max(a,half,end);
    return(m1>m2?m1:m2);
}
    
int gcd(int m,int n){
    if(m==0)return n;
    if(m>=n)return gcd(m%n,n);
    return gcd(n%m,m);
}
    
int bcoeff(int n,int k){
    if(k==0)return 1;
    if(k==n)return 1;
    return bcoeff(n-1,k-1)+bcoeff(n-1,k);
}