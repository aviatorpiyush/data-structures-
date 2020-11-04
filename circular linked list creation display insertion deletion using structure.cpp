#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*Head;
void create(int A[],int n)
{
int i;
    struct Node *t,*last;
    Head = new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *h)
{
    do
    {
        cout<<h->data<<" ";
        h=h->next;
    }while(h!=Head);
}
void RDisplay(struct Node *h)
{
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag=1;
        cout<<h->data<<" ";
        RDisplay(h->next);
    }
    flag=0;
}

int count(struct Node *p)
{

    int c=0;
    do
    {
        c++;
        p=p->next;

    } while(p!=Head);
    return c;
}

void insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index==0)
    {
        t=new Node;
        t->data=x;
        if(Head==nullptr)
        {
            Head=t;
            Head->next=Head;

        }
        else
        {
         while(p->next!=nullptr)
         p=p->next;
         p->next=t;
         t->next=Head;
         Head=t;

        }
    }
    else
    {
        for(i=1;i<index;i++)
        {
            p=p->next;
        }
            t=new Node;
            t->data=x;
            t->next=p->next;
            p->next=t;

    }
}

int Delete(struct Node *p,int index)
{
    struct Node *q;
    int i,x;
    if(index <0 || index >count(Head))
    return -1;
    if(index==1)
    {
        while(p->next!=Head)p=p->next;
        x=Head->data;
        if(Head==p)
        {
            free(Head);
            Head=nullptr;
        }
        else
        {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
else
    {
        for(i=0;i<index-2;i++)
        p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete(q);
    }
    return x;
}
int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    Display(Head);
    cout<<"\n";
    RDisplay(Head);
    cout<<"\n";
    cout<<count(Head);
    cout<<"\n";
    insert(Head,4,10);
    Display(Head);
    Delete(Head,5);
    cout<<"\n";
    Display(Head);
     return 0;
}
