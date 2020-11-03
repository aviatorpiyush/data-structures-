#include<iostream>
using namespace std;

struct node
{

    int data;
    struct node *next;
}*first;
void display(struct node*r)
{
    while(r!=nullptr)
    {
        cout<<r->data<<" ";
        r=r->next;

    }
}
void create(int A[],int n)
{
    first=nullptr;
    int i;
    struct node *p;
    struct node *last;
    first =new node;
    first->data =A[0];
    first->next=nullptr;
    last=first;
    for(int i=1;i<n;i++)
    {
        p=new node;
        p->data=A[i];
        p->next=nullptr;
        last->next=p;
        last=p;
    }
}
void sortedinsert(struct node *p,int x)
{
    struct node *t,*q=nullptr;
    t=new node;
    t->data =x;
    t->next=nullptr;
    if(first==nullptr)
    {
        first =t;
    }
    else{
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;

        }
        else{
            t->next=q->next;
            q->next=t;

        }
    }
}
int main()
{
    int A[]={2,4,6,8,10};
    create(A,5);
    display(first);
    cout<<"\n";

    sortedinsert(first,9);
    sortedinsert(first,10);
    display(first);
    return 0;
}
