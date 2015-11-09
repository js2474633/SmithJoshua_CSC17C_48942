#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
 
void quickSort(int [], int, int, int&);
int pivot(int [], int, int, int&);
void swap(int&, int&, int&);
void print(int [], const int&);
void merge(int*,int,const int, const int, int&);
void merge_sort(int*, const int, const int, int&);
void heapsort(int [], int, int&);
void buildheap(int [], int, int&);
void heapify(int [], int, int, int&);
 
int main(){
    srand(time(NULL));

    int size = 10000;
    int test[size];
    for(int i = 0; i < size; i++)
    {
        test[i] = rand();
    }
    int N = sizeof(test)/sizeof(int);
 
    //cout << "Size of test array :"  << N << endl;
 
    //cout << "Before sorting : " << endl;
    //print(test, N);
 
    int opCount = 0;

    quickSort(test, 0, N-1, opCount); cout << "\nQuick Sort: ";
    //merge_sort(test, 0, N-1, opCount); cout << "\nMerge Sort: ";
    //heapsort(test, N, opCount); cout << "\nHeap Sort: ";
 
    //cout << endl << "After sorting : " << endl;
    //print(test, N);
    cout << "Number of Operations Performed: " << opCount << endl;
     
    return 0;
}
 
/**
 * Quicksort.
 * @param a - The array to be sorted.
 * @param first - The start of the sequence to be sorted.
 * @param last - The end of the sequence to be sorted.
*/
void quickSort( int a[], int first, int last, int& count ) {
    int pivotElement;
    count++;
 
    if(first < last)
    {
        count++;
        pivotElement = pivot(a, first, last, count);
        quickSort(a, first, pivotElement-1, count);
        quickSort(a, pivotElement+1, last, count);
    }
}
 
/**
 * Find and return the index of pivot element.
 * @param a - The array.
 * @param first - The start of the sequence.
 * @param last - The end of the sequence.
 * @return - the pivot element
*/
int pivot(int a[], int first, int last, int& count) {
    int  p = first;
    int pivotElement = a[first];
    count+=2;
 
    for(int i = first+1 ; i <= last ; i++)
    {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivotElement)
        {
            p++;
            swap(a[i], a[p], count);
            count+=2;
        }
    }
 
    swap(a[p], a[first], count);
 
    return p;
}
 
 
/**
 * Swap the parameters.
 * @param a - The first parameter.
 * @param b - The second parameter.
*/
void swap(int& a, int& b, int& count){
    int temp = a;
    a = b;
    b = temp;
    count+=3;
}
 
/**
 * Print an array.
 * @param a - The array.
 * @param N - The size of the array.
*/
void print(int a[], const int& N){
    for(int i = 0 ; i < N ; i++)
        cout << "array[" << i << "] = " << a[i] << endl;
} 

void merge(int* A,int p,const int q, const int r, int& count){
    const int n_1=q-p+1;
    count+=3;
    const int n_2=r-q;
    count+=2;
    int* L = new int [n_1+1];
    count +=2;
    int* R = new int [n_2+1];
    count +=2;
    L[n_1]=0;
    R[n_2]=0;
    count +=3;
    for(int i = 0; i < n_1; i++) 
    {
        L[i] = A[p+i];
        count +=4;
    }
    count++;
    for (int j = 0; j < n_2; j++)
    {
        R[j] = A[q+j+1];
        count += 5;
    }

    int i=0;
    int j=0;
    count +=2;
    // for(int k = p; k <= r; p++)   broken code
    int k;
    count+=2;
    for(k=p; k <= r && i < n_1 && j < n_2; ++k)
    {
        count+=4;
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
            count +=2;
        }
        else
        {
            A[k] = R[j];
            j++;
            count+=2;
        }
    }
    // Added the following two loop.
    // Note only zero or one loop will actually activate.
    while (i < n_1)
    {
        A[k++] = L[i++];
        count+=4;
    }
    while (j < n_2)
    {
        A[k++] = R[j++];
        count+=4;
    }
}     

void merge_sort(int* A, const int p, const int r, int& count){
    count++;
    if (p < r)
    {
        int q = (p+r)/2;
        count+=3;
        merge_sort(A, p,q,count);
        merge_sort(A,q+1,r,count);
        merge(A,p,q,r,count);
    }
}

void heapsort(int A[], int length, int& count)//	       (takes O(n lg n) time)
{
	int heapsize = length;
    count++;
	
    buildheap(A, length, count);	//Take the unsorted list and make it a heap
    count++;
	for (int i = length-1; i >=1; i--)
	{
		swap(A[0], A[i]);
		heapsize--;
        heapify(A, heapsize, 0, count);
        count+=5;
	}
}

void buildheap(int A[], int length, int& count)	//     (takes O(n) time)
{	
    count++;
	for (int i = floor((length)/2); i >= 0 ; i--)
    {
        heapify(A, length, i, count);
        count+=3;
    }
}

void heapify(int A[], int heapsize, int root, int& count) //(takes O(h) h is the height of root
{
	int left = 2*root+1, 
		right = 2*root +2,
		largest;
    count+=7;
	
    count+=2;
	if ( (left < heapsize) && (A[left] > A[root]))
    {
		largest = left;
        count++;
    }
	else 
    {
		largest = root;
        count++;
    }
	
    count+=2;
	if ( (right < heapsize) && (A[right] > A[largest]))
    {
		largest = right;
        count++;
    }
		
    count++;
	if (largest != root)
	{
		swap(A[root], A[largest]);
        heapify(A, heapsize, largest, count);
        count+=2;
	}
}
