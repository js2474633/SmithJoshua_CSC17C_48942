#ifndef DOUBLYLL
#define DOUBLYLL

#include <cstddef>
#include <sstream>
using namespace std;

template <class T>
class DoublyLL
{
private:
    struct Link
    {
        T data;
        Link *right;
        Link *left;
    };
    Link *head;
    Link *end;
    Link *cr;
    Link *cl;
    int size;
public:
    DoublyLL(T);
    DoublyLL(DoublyLL<T>&);
    void append(T);
    void prepend(T);
    T first();
    T last();
    void extract(T);
    void insertBefore(T,T);
    void insertAfter(T,T);
    string toString();
    T &operator[](const int &);
    virtual ~DoublyLL();
    int getSize();
};

template <class T>
DoublyLL<T>::DoublyLL(T d)
{
    Link *block = new Link;
    block->data = d;
    block->right=NULL;
    block->left=NULL;
    head = block;
    end = block;
    size = 1;
}

template <class T>
DoublyLL<T>::DoublyLL(DoublyLL<T>& copy)
{
    Link *block;
    for(int i = 0; i < copy.getSize(); i++)
    {
        block = new Link;
        block->data = copy[i];
        block->right = NULL;
        if(i == 0)
        {
            head = block;
            block->left=NULL;
        }
        else
        {
            cr->right = block;
            block->left = cr;
        }
        cr = block;
    }
    end = block;
}

template <class T>
void DoublyLL<T>::append(T d)
{
    //Insert new link at end
    Link *block = new Link;
    block->data = d;
    block->right = NULL;
    block->left = end;
    end = block;
    size++;
}

template <class T>
void DoublyLL<T>::prepend(T d)
{
    //Insert new Link
    Link *block = new Link;
    block->data = d;
    block->right = head;
    block->left = NULL;
    head = block;
    size++;
}

//Returns first data value
template <class T>
T DoublyLL<T>::first()
{
    return head->data;
}

//Returns last data value
template <class T>
T DoublyLL<T>::last()
{
    return end->data;
}

//Deletes selected data value
template <class T>
void DoublyLL<T>::extract(T find)
{
    Link *found;
    int it = 0;
    cr = head;
    cl = end;
    do{
        if(cr->data == find)
        {
            cr->left->right = cr->right;
            cr->right->left = cr->left;
            found = cr;
        }
        else if(cl->data == find)
        {
            cl->left->right = cl->right;
            cl->right->left = cl->left;
            found = cl;
        }
        else
        {
            cr = cr->right;
            cl = cl->left;
            it++;
        }
    }while(it <= size/2);
    if(found)
    {
        delete found;
        size--;
    }
}

//Creates new Link before selected data value
template <class T>
void DoublyLL<T>::insertBefore(T create, T find)
{
        cr = head;
        cl = end;
        int it = 0;
        do{
            if(cr->data == find)
            {
                //Create link before
                Link *block = new Link;
                block->data = create;
                block->right = cr;
                block->left = cr->left;
                cr->left = block;
                cr = block;
                size++;
            }
            //RESUME HERE
            else if(cl->data == find)
            {
                Link *block = new Link;
                block->data = create;
                block->right = cl;
                cl = block;
                size++;
            }
            cr = cr->right;
            cl = cl->left;
            it++;
        }while(it <= size/2);
    else
    {
        //ERROR: Nothing found
    }
}

//Creates new Link after selected data value
template <class T>
void DoublyLL<T>::insertAfter(T create, T find)
{
    Link *prev;
    if(head->data != find)
    {
        cr = head;
        do{
            if(cr->data == find)
            {
                Link *block = new Link;
                block->data = create;
                block->right = cr->right;
                cr->right = block;
                size++;
            }
            else
                prev = cr;
        }while(cr = cr->right);

    }
    else if(head->data == find)
    {
        Link *block = new Link;
        block->data = create;
        block->right = head->right;
        //Set previous Link pointer to new Link
        head->right = block;
        size++;
    }
    else
    {
        //ERROR: Nothing found
    }
}

//Copied for testing
template <class T>
string DoublyLL<T>::toString(){
    string build="";
    char counter=48;
    if(head){
        cr=head;
        do{
             build+=("Data element in the list ->");
             stringstream ss;
             ss<<cr->data;
             string data;
             ss>>data;
             build+=data;
             build+="\n";
        }while(cr=cr->right);
    }
    return build;
}

template <class T>
T &DoublyLL<T>::operator[](const int &sub)
{
    cr = head;
    for(int i = 0; i < sub; i++)
    {
        cr = cr->right;
    }
    return cr->data;
}

template <class T>
DoublyLL<T>::~DoublyLL()
{
    if(head)
    {
        //Progress through and delete cr
        do
        {
            cr = head;
            head = head->right;
            delete cr;
        }while(head);
    }
}

template <class T>
int DoublyLL<T>::getSize()
{
    return size;
}
#endif // DOUBLYLL

