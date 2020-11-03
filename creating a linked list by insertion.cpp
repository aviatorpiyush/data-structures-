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
insert(first,0,5);
insert(first,1,10);
insert(first,2,15);
insert(first,3,45);
display(first);
return 0;
}
