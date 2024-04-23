#include <stdio.h>
#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};

class SLL
{
private:
    node *head;

public:
    SLL();
    node *insertAtStart(int);
    node *insertAtLast(int);
    node *insertAfter(node *, int);
    node *search(int);
};

SLL::SLL()
{
    head = NULL;
}
node *SLL::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    n->next = head;

    head = n;
    return head;
    //(or)
    // return n;
}

node *SLL::insertAtLast(int data)
{
    node *t;
    node *n = new node;
    n->item = data;
    n->next = NULL;

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = n;
    }
    return head;
}

node *SLL::insertAfter(node *t, int data)
{
    if (t != NULL)
    {
        node *n = new node;
        n->item = data;
        n->next = t->next;
        t->next = n;
    }
    return head;
}
node *SLL::search(int data)
{
    node *t = head;
    while (t != NULL)
    {
        if (t->item == data)
            return t;
        t = t->next;
    }
    return NULL;
}

int main()
{

    return 0;
}