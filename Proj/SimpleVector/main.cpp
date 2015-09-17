/*Joshua Smith
 * Sept 17, 2015
 * Simple Vector
 *
 *Modify Simple Vector .h by adding 2
 * functions then test to make sure they are working properly.
 *1)  Add a push routine that will augment the array by 1
 * and double at the top to hold the new value pushed.
 *2)  Add a pull routine that takes one value off the top of
 * the array and decreases the size by 1.
 */

#include <iostream>
#include "simplevector.h"

using namespace std;

void testPrint(int* p)
{
    for(int i = 0; i < p.size(); i++)
    {
        cout << p[i];
    }
}

int main()
{
    int* test = new SimpleVector(5);
    testPrint(test);

    return 0;
}

