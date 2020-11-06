
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
int isloop(struct node *f)
{
    struct node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=p->next;
        q=p?q->next:q;
        }while(p &&q && p!=q);
    if(p==q)
        return 1;
    else
        return -1;

}

int main()
{
    struct node *t1,*t2;
    int A[]={10,20,30,40,50};
    create(A,5);
    t1=first->next->next; // shifting first to 3rd node

    t2=first->next->next->next->next;// shifting or making point t2 to last element
    t2->next=t1; // making t2 points on t1 i.e. creating a null
    cout<<isloop(first);
    return 0;
}
