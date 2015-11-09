/*
 * Name: Joshua Smith
 * Due: 9/30/2015
 *
 * First and Last Functions
 * Prepend
 * Append
 * Copy Constructor and Assignment Operator
 * Extract
 * InsertAfter and InsertBefore
 *
 * Now template and make it work for Objects!
 */

#include <cstdlib>
#include <iostream>
#include "llvector.h"

using namespace std;

int main()
{
    cout << "Creating chain beginning with '1'" << endl;
    try
    {
        LLVector<int> testChain(1);
        for(int i = 2; i < 10; i++)
        {
            cout << "Appending '" << i << "'" << endl;
            testChain.append(i);
        }
        cout << "Prepending '0'" << endl;
        testChain.prepend(0);

        cout << "First: " << testChain.first() << endl;
        cout << "Last: " << testChain.last() << endl;

        testChain.extract(0);
        cout << "Extract 0: \n" << testChain.toString() << endl;
        testChain.extract(4);
        cout << "Extract 4: \n" << testChain.toString() << endl;
        testChain.extract(6);
        cout << "Extract 6: \n" << testChain.toString() << endl;

        testChain.insertBefore(4,5);
        cout << "Insert 4: \n" << testChain.toString() << endl;

        testChain.insertAfter(6,5);
        cout << "Insert 6: \n" << testChain.toString() << endl;

        LLVector<int> copyChain(testChain);
        cout << "Copy of Vector: \n" << copyChain.toString() << endl;

        cout << "Fifth value: " << testChain[4] << endl;
    }
    catch (exception const ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        return 0;
    }
}

