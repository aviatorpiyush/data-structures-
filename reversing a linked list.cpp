#include<iostream>
using namespace std;

struct node
{

    int data;
    struct node *next;
}*first;
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
void display(struct node*r)
{
    while(r!=nullptr)
    {
        cout<<r->data<<" ";
        r=r->next;

    }
}
int count(struct node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

void reverseusingarray(struct node *p)
{
    int *A;
    int i=0;
    struct node *q=p;
    A= new int [sizeof(int)*count(p)];
    while(q!=nullptr)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=nullptr)
    {
        q->data =A[i];
        q=q->next;
        i--;
    }
}
void reverseusingsliding(struct node *p)
{
    p=first;
    struct node *q=nullptr;
    struct node *r=nullptr;
    while(p!=nullptr)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first =q;

}

void reverseusingrecursion(struct node *q,struct node *p)
{
    if(p!=nullptr)
    {
        reverseusingrecursion(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

int main()
{
    int A[]={10,20,30,40,50,60};
    create(A,6);
    display(first);
    cout<<"\n";
    reverseusingarray(first);
    display(first);
    cout<<"\n";
    reverseusingsliding(first);
    display(first);
    cout<<"\n";
    reverseusingrecursion(nullptr,first);
    display(first);
    return 0;
}
