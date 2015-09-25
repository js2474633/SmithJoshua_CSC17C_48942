#ifndef LLVECTOR_H
#define LLVECTOR_H

#include <cstddef>
using namespace std;

class LLVector
{
private:
    struct Link
    {
        int data;
        Link *next;
    };
    Link *head;
    Link *current;
public:
    LLVector(int);
    void append(int);
    void prepend(int);
    virtual ~LLVector();
};

#endif // LLVECTOR_H
