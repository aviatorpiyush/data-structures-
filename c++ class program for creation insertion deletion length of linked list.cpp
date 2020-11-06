#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node*next;

};
class linkedlist{
private:
    node * first;
public:
    linkedlist()
    {
        first=nullptr;  // constructor
    }
    linkedlist(int A[],int n);   // constructor to create a linked list
    ~linkedlist();      // destructor
    void display();
    void insert(int index,int x);
    int Delete(int index);
    int length();

};

linkedlist:: linkedlist(int A[],int n)
{
    node *last,*t;
    int i=0;
    first=new node;
    first->data =A[0];
    first->next=nullptr;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new node;
        t->data= A[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }
}
linkedlist::~linkedlist()
{
    node *first,*p;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;


    }
}

void linkedlist:: display()
{
    node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;

    }
    cout<<endl;

}

int linkedlist::length()
{
    node *p;
    p=first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;

}
void linkedlist::insert(int index,int x)
{
    node *t,*p=first;
    if(index<0 || index>length())
        return;

    t=new node;
    t->data=x;
    t->next=nullptr;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

int linkedlist::Delete(int index)
{
    node *p,*q=nullptr;
    int x=-1;
    if(index<0 || index>length())
        return -1;
    if(index==1)
    {
        p=first;
        first=first->next;
        x=p->data;
        delete(p);
    }
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete(p);

    }
    return x;

}

int main()
{
    int A[]={1,2,3,4,5,6};
    linkedlist l(A,6);
    cout<<l.length()<<"\n";
    l.display();
    l.insert(4,10);
    cout<<"\n";
    l.display();
    l.Delete(5);
    cout<<"\n";
    l.display();
    return 0;
}
