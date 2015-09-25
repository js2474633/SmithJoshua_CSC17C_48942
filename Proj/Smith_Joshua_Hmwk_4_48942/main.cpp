/*
 * Name: Joshua Smith
 * Due: 9/25/2015
 *
 * Create a simple vector class utilizing
 * a singly link-list class that has push,
 * etc...  behaviors.
 * Compare to the array implementation.
 */

#include <cstdlib>
#include <iostream>
#include "llvector.h"

using namespace std;

int main()
{
    cout << "Creating chain beginning with '1'" << endl;
    LLVector testChain(1);
    for(int i = 2; i < 10; i++)
    {
        cout << "Appending '" << i << "'" << endl;
        testChain.append(i);
    }
    cout << "Prepending '0'" << endl;
    testChain.prepend(0);
    return 0;
}

