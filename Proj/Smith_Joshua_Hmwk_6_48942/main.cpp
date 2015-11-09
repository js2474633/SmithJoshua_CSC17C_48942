/*
 * Name: Joshua Smith
 * Due: 10/14/2015
 *
 * Create a stack/queue from your linked list.
 * Create a doubly linked list.
 * Create a circularly linked list.
 * Create a priority linked list -> priority queue.
 * Create a sorted linked list.
 */

#include <cstdlib>
#include <iostream>
#include "llvector.h"
#include "doublyll.h"

using namespace std;

int main()
{
    //BEGIN LLVECTOR TEST
    try
    {
        cout << "BEGIN LLVECTOR TEST" << endl;
        cout << "Creating chain beginning with '1'" << endl;
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

    //BEGIN DOUBLYLL TEST
    try
    {
        cout << "BEGIN DOUBLYLL TEST" << endl;
        cout << "Creating chain beginning with '1'" << endl;
        DoublyLL<int> testChain(1);
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

        DoublyLL<int> copyChain(testChain);
        cout << "Copy of Vector: \n" << copyChain.toString() << endl;

        cout << "Fifth value: " << testChain[4] << endl;
    }
    catch (exception const ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        return 0;
    }
}

