/*
#include "llvector.h"

LLVector::LLVector(int d)
{
    Link *block = new Link;
    block->data = d;
    block->next=NULL;
    head = block;
}

void LLVector::append(int d)
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
    }
}

void LLVector::prepend(int d)
{
    //Insert new Link
    Link *block = new Link;
    block->data = d;
    block->next = head;
    head = block;
}

//Returns first data value
int LLVector::first()
{
    return head->data;
}

//Returns last data value
int LLVector::last()
{
    Link *prev;
    current = head;
    do{
        prev = current;
    }while(current = current->next);
    return prev->data;
}

//Deletes selected data value
void LLVector::extract(int find)
{
    Link *prev;
    if(head->data != find)
    {
        current = head;
        do{
            if(current->data == find)
            {
                prev = current->next;
                delete current;
            }
            else
                prev = current;
        }while(current = current->next);

    }
    else if(head->data == find)
    {
        current = head;
        head = current->next;
        delete current;
    }
    else
    {
        //Nothing found to be extracted
    }
}

//Creates new Link before selected data value
void LLVector::insertBefore(int create, int find)
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
    }
    else
    {
        //ERROR: Nothing found
    }
}

//Creates new Link after selected data value
void LLVector::insertAfter(int create, int find)
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
    }
    else
    {
        //ERROR: Nothing found
    }
}

//Copied for testing
string LLVector::toString(){
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

LLVector::~LLVector()
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
*/
