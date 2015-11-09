/* Name: Joshua Smith
 * Date: 11/5/2015
 */
/* Midterm CIS 17C
 * 1)  Vector - Fill a vector with random inputs.  Write a function
             vector *top(vector x,int p) that returns in a
             vector the top p elements of the x input vector.

2)  Vector - Fill a vector with random inputs.  Write a function
             vector *mode(vector x) that returns a vector that
             represents the mode of vector x.  Note:  Make sure
             there is more than one mode.

3)  Vector - Fill a vector with random inputs.  Write a function
             statClass *stat(vector x) that returns a class that
             contains the min,max and average of the x vector but
             also uses a map to solve the mode problem and returns
             the important elements for the mode.

4)  List -   Try using a list that does 1)

5)  List -   Try using a list that implements 2)

6)  List -   Try using a list that implements 3)

7)  List -   A self-organizing list is a list that moves each element
             to the front of the list whenever it is accessed.  This
             modification improves the efficiency of the standard
             implementation if the list is used mostly for look-up.
             Use inheritance to define a SelfOrganizingList class
             template.  Add a single function that tests if the list
             contains the element by returning a boolean then putting
             the element at the front of the list.

8)  Recursion - Implement the tangent function recursively using the
                formulas

                              tan(2x)=(2 tan(x))/(1-(tan(x))^2)


                              |tan(x) ~ x + x^3/3| < epsilon

                Accuracy to 2 decimal places is good enough.

9)  Recursion - Use mutual recursion to implement the following
                functions

                              h(2x)=2h(x)g(x)
                              g(2x)=1+2(h(x)^2)

                      h(x) ~ x + x^3/6 just test if |x| < epsilon
                      g(x) ~ 1 + x^2/2 just test if |x| < epsilon

        Epsilon -> accuracy to 6 decimal places is good enough.
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <cmath>

using namespace std;

void sort(vector<int> &x);
vector<int> top(vector<int> x,int p);
vector<int> mode(vector<int> x);
float tang(float x);
float h(float x);
float g(float x);

int main()
{
    srand(time(NULL));

    int option = 1;
    while(option != 0)
    {
        //Menu
        cout << "\nChoose a Test: " << endl;
        cout << "1) Vector - Top" << endl
             << "2) Vector - Mode" << endl
             << "3) Vector - Stat" << endl
             << "4) List - Top" << endl
             << "5) List - Mode" << endl
             << "6) List - Stat" << endl
             << "7) List - Organizing" << endl
             << "8) Recursion - Tan" << endl
             << "9) Recursion - h&g" << endl
             << "0) Exit" << endl
             << "Select: ";
        cin >> option;
        cout << endl;
        if(option == 1)
        {
            //Create first vector with random integers
            vector<int> test1;
            for(int i = 0; i < 10; i++)
            {
                test1.push_back(rand() % 100);
            }

            //Test sort function
            //sort(test1);
            cout << "Vector Test 1: " << endl;
            for(unsigned int i = 0; i < test1.size(); i++)
            {
                cout << test1[i] << endl;
            }

            //Test 1
            cout << "Top Test: " << endl;
            vector<int> topT1 = top(test1,3);
            for(unsigned int i = 0; i < topT1.size(); i++)
            {
                cout << topT1[i] << endl;
            }
        }

        else if(option == 2)
        {
            //Create second vector with random ints
            vector<int> test2;
            for(int i = 0; i < 10; i++)
            {
                test2.push_back(rand() % 10);
            }

            cout << "Vector Test 2: " << endl;
            for(unsigned int i = 0; i < test2.size(); i++)
            {
                cout << test2[i] << ",";
            }

            //Test 2
            cout << "\nMode Test: " << endl;
            vector<int> modeT1 = mode(test2);
            for(unsigned int i = 0; i < modeT1.size(); i++)
            {
                cout << modeT1[i] << endl;
            }
        }

        else if(option == 3)
        {
            cout << "You find nothing but monkeys." << endl;
        }

        else if(option == 4)
        {
            cout << "Nothing but monkeys here." << endl;
        }

        else if(option == 5)
        {
            cout << "You wish to see the monkeys." << endl;
        }

        else if(option == 6)
        {
            cout << "This only leads to monkeys." << endl;
        }

        else if(option == 7)
        {
            cout << "Where did all these monkeys come from?" << endl;
        }

        else if(option == 8)
        {
            //Test 8
            int n;
            cout << "Select a number: ";
            cin >> n;
            cout << tang(n) << endl;
        }

        else if(option == 9)
        {
            //Test 9
            int n;
            cout << "Select a number: ";
            cin >> n;
            cout << h(n) << endl;
        }
        else if(option == 0)
        {
            return 0;
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }

    return 0;
}

void sort(vector<int> &x)
{
    int temp;
    for(unsigned int i = 0; i < x.size(); i++)
    {
        for(unsigned int j = 0; j < x.size(); j++)
        {
            if(x[j] > x[j+1])
            {
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
}



//1)  Vector - Fill a vector with random inputs.  Write a function
//vector *top(vector x,int p) that returns in a
//vector the top p elements of the x input vector.
vector<int> top(vector<int> x,int p)
{
    vector<int> temp;
    sort(x);
    for(unsigned int i = x.size() - p; i < x.size(); i++)
    {
        temp.push_back(x[i]);
        /*
        if(i < p)
        {
            temp.push_back(x[i]);
        }
        else
        {
            for(int j = 0; j < temp.size(); j++)
            {
                if(x[i] > temp[j])
                {
                    temp[0] = x[i];
                }
            }
        }
        sort(x);
        sort(temp);
        */
    }
    return temp;
}

//2)returns a vector that
//represents the mode of vector x
vector<int> mode(vector<int> x)
{
    vector<int> mv;
    int mCount = 0;
    int cCount = 0;

    for(unsigned int i = 0; i < x.size(); i++)
    {
        cCount = 0;
        for(unsigned int j = 0; j < x.size(); j++)
        {
            if(x[j] == x[i])
            {
                cCount++;
            }
        }
        if(cCount == mCount)
        {
            if(!x.empty())
            {
                bool check = false;
                for(unsigned int k = 0; k < mv.size(); k++)
                {
                    if(x[i] == mv[k])
                    {
                        check = true;
                    }
                }
                if(!check)
                {
                    mv.push_back(x[i]);
                }
            }
            else
            {
                mv.push_back(x[i]);
            }
        }
        else if(cCount > mCount)
        {
            mv.clear();
            mv.push_back(x[i]);
            mCount = cCount;
        }
    }
    return mv;
}

//8)tan(2x)=(2 tan(x))/(1-(tan(x))^2)
//|tan(x) ~ x + x^3/3| < epsilon
float tang(float x)
{
    if(abs(x+(x*x*x)/3) < 0.01)
    {
        return abs(x+(x*x*x)/3);
    }
    else
    {
        return (2*tang(x/2))/(1-(tang(x/2)*tang(x/2)));
    }
}

//9)
//h(2x)=2h(x)g(x)
//g(2x)=1+2(h(x)^2)

//h(x) ~ x + x^3/6 just test if |x| < epsilon
//g(x) ~ 1 + x^2/2 just test if |x| < epsilon
float h(float x)
{
    if(abs(x)<0.000001)
    {
        return (x+pow(x,3)/6);
    }
    else
    {
        return (2*h(x/2)*g(x/2));
    }
}

float g(float x)
{
    if(abs(x)<0.000001)
    {
        return (1+pow(x,2)/2);
    }
    else
    {
        return (1+2*(pow(h(x/2),2)));
    }
}

