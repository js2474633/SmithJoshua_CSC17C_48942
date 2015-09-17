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


int main()
{
    SimpleVector<int> test(5);
    cout << "Printing SimpleVector with size: " << test.size() << endl;
    test.print();

    cout << "Pushing back with element '1'" << endl;
    test.push_back(1);
    test.print();

    cout << "Pushing back with multiple elements" << endl;
    for(int i = 0; i < 3; i++)
    {
        test.push_back(i);
    }
    test.print();

    cout << "Popping back last element" << endl;
    test.pop_back();
    test.print();

    return 0;
}

