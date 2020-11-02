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
int insert(struct node *p ,int index,int x)
{
    int i;
    struct node *t;

    t=new node;
    t->data=x;

    if(index==0)
    {   t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;


        t->next=p->next;
        p->next=t;
    }
}
int main()
{
    int key=0,pos=0;
    int A[] = {2,4,3,7,9,11};
    create(A,6);
    cout<<"enter element to be inserted"<<"\n";
    cin>>key;
    cout<<"enter the position within"<<count(first)<<"\n";;
    cin>>pos;
    insert(first,pos,key);
    display(first);
    return 0;
}
