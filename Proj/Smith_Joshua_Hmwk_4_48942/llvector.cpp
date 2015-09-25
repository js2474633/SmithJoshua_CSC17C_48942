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

