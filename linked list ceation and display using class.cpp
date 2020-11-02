#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    };
node *first=new node;
int insert(int A[] ,int index,int x)
{
    int i;
    node *t,*p;

    t=new node;
    t->data=x;

    if(index==0)
    {   t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            t=t->next;


        t->next=p->next;
        p->next=t;
    }

}
int main()
{
    int A[]={3,5,7,9,11,13};
    node* head =new node;
    node*temp;
    node*last;
    head->data=A[0];
    head->next=nullptr;
    last=head;
     for(int i=1;i<sizeof(A);i++)
     {
         temp=new node;
         temp->data=A[i];
         temp->next=nullptr;
         last->next=temp;
         last=temp;
     }
     node *p=head;

     insert(A,5,5);
     while(p!=nullptr)
     {
         cout<<p->data;
         p=p->next;

     }


     return 0;
}
