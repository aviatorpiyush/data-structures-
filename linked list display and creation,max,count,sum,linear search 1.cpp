#include<iostream>
using namespace std;
struct node
{
    int *A;
    int size;
    int length;
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

// counting number of nodes in a linked list
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

//sum of all elements

int add(struct node *p)
{
   int s=0;
   while(p)
   {
       s=s+p->data;
       p=p->next;
   }

   return s;

}

// max elements in a linked list

int max(struct node *p)
{
    int m=INT_MIN;
    while(p)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;

    }
    return m;
}
// linear search in a linked list

int linearsearch(struct node *p,int key)
{
    while(p)
    {
        if(key==p->data)
        {
            return p->data;
            p=p->next;
        }
        else
            return -1;
    }
}

void insert(struct node *p ,int index,int x)
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
    int i,n,key,pos;
    struct node arr;
    arr.A=new int [arr.length*sizeof(int)];
    arr.length=0;
    cout<<"enter number of numbers";
    cin>>n;
    cout<<"enter all number of numbers";
    cout<<"enter the position where you want to insert the element"<<"\n";
    cin>>pos;
    cout<<"enter the elements"<<"\n";
    cin>>key;
    for(i=0;i<n;i++)
    {
        cin>>arr.A[i];

    }
    arr.length=n;
    create(arr.A,n);
    display(first);
    cout<<"\n";
    cout<<count(first);
    cout<<"\n";
    cout<<add(first);
    cout<<"\n";
    cout<<max(first);
    cout<<"\n";

    cout<<linearsearch(first,5);
    cout<<"\n";

    insert(first,pos,key);
    display(first);
    return 0;
}
