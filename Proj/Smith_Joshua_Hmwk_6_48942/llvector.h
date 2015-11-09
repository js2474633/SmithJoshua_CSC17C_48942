#ifndef LLVECTOR_H
#define LLVECTOR_H

#include <cstddef>
#include <sstream>
using namespace std;

template <class T>
class LLVector
{
private:
    struct Link
    {
        T data;
        Link *next;
    };
    Link *head;
    Link *current;
    int size;
public:
    LLVector(T);
    LLVector(LLVector<T>&);
    void append(T);
    void prepend(T);
    T first();
    T last();
    void extract(T);
    void insertBefore(T,T);
    void insertAfter(T,T);
    string toString();
    T &operator[](const int &);
    virtual ~LLVector();
    int getSize();
};

template <class T>
LLVector<T>::LLVector(T d)
{
    Link *block = new Link;
    block->data = d;
    block->next=NULL;
    head = block;
    size = 1;
}

template <class T>
LLVector<T>::LLVector(LLVector<T>& copy)
{
    Link *prev;
    Link *block;
    for(int i = 0; i < copy.getSize(); i++)
    {
        block = new Link;
        block->data = copy[i];
        block->next = NULL;
        if(i == 0)
        {
            head = block;
        }
        else
        {
            prev->next = block;
        }
        prev = block;
    }
}

template <class T>
void LLVector<T>::append(T d)
{
    Link *prev;
    //If at the beginning of the chain
    if(head)
    {
        //Set beginning to workable
        current = head;
        //Progress to end
        do{
            prev = current;
        }while(current = current->next);
        //Insert new Link
        Link *block = new Link;
        block->data = d;
        block->next = NULL;
        //Set previous Link pointer to new Link
        prev->next = block;
        size++;
    }
    //If already at the end(?)
    else
    {
        //Insert new Link
        Link *block = new Link;
        block->data = d;
        block->next = NULL;
        //Set previous Link pointer to new Link
        prev->next = block;
        size++;
    }
}

template <class T>
void LLVector<T>::prepend(T d)
{
    //Insert new Link
    Link *block = new Link;
    block->data = d;
    block->next = head;
    head = block;
    size++;
}

//Returns first data value
template <class T>
T LLVector<T>::first()
{
    return head->data;
}

//Returns last data value
template <class T>
T LLVector<T>::last()
{
    Link *prev;
    current = head;
    do{
        prev = current;
    }while(current = current->next);
    return prev->data;
}

//Deletes selected data value
template <class T>
void LLVector<T>::extract(T find)
{
    Link *prev;
    Link *found;
    if(head->data != find)
    {
        current = head;
        do{
            if(current->data == find)
            {
                prev->next = current->next;
                found = current;
                size--;
            }
            else
                prev = current;
        }while(current = current->next);
    }
    else if(head->data == find)
    {
        current = head;
        head = current->next;
        found = current;
        size--;
    }
    else
    {
        //Nothing found to be extracted
    }
    if(found)
    {
        delete found;
    }
}

//Creates new Link before selected data value
template <class T>
void LLVector<T>::insertBefore(T create, T find)
{
    Link *prev;
    if(head->data != find)
    {
        current = head;
        do{
            if(current->data == find)
            {
                //Create link before
                Link *block = new Link;
                block->data = create;
                block->next = prev->next;
                prev->next = block;
                size++;
            }
            else
                prev = current;
        }while(current = current->next);

    }
    else if(head->data == find)
    {
        Link *block = new Link;
        block->data = create;
        block->next = head;
        head = block;
        size++;
    }
    else
    {
        //ERROR: Nothing found
    }
}

//Creates new Link after selected data value
template <class T>
void LLVector<T>::insertAfter(T create, T find)
{
    Link *prev;
    if(head->data != find)
    {
        current = head;
        do{
            if(current->data == find)
            {
                Link *block = new Link;
                block->data = create;
                block->next = current->next;
                current->next = block;
                size++;
            }
            else
                prev = current;
        }while(current = current->next);

    }
    else if(head->data == find)
    {
        Link *block = new Link;
        block->data = create;
        block->next = head->next;
        //Set previous Link pointer to new Link
        head->next = block;
        size++;
    }
    else
    {
        //ERROR: Nothing found
    }
}

//Copied for testing
template <class T>
string LLVector<T>::toString(){
    string build="";
    char counter=48;
    if(head){
        current=head;
        do{
             build+=("Data element in the list ->");
             stringstream ss;
             ss<<current->data;
             string data;
             ss>>data;
             build+=data;
             build+="\n";
        }while(current=current->next);
    }
    return build;
}

template <class T>
T &LLVector<T>::operator[](const int &sub)
{
    current = head;
    for(int i = 0; i < sub; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <class T>
LLVector<T>::~LLVector()
{
    if(head)
    {
        //Progress through and delete current
        do
        {
            current = head;
            head = head->next;
            delete current;
        }while(head);
    }
}

template <class T>
int LLVector<T>::getSize()
{
    return size;
}

#endif // LLVECTOR_H
