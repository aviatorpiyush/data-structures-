#include<iostream>
using namespace std;
struct Array
{
    int *A;
    int Size;
    int length;

};
void display(struct Array arr)
{

    int i;
    for(i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";

}
void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void reverse(struct Array *arr)
{
    int *b;
    int i,j;
    b=new int [(arr->Size)*sizeof(int)];
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        b[j]=arr->A[i];
    for(int k=0;k<arr->length;k++)
        arr->A[k]=b[k];

}
void reverse2(struct Array *arr)
{

    int i,j;
    for(i=0,j=arr->length-1;i>j;i++,j--)
        Swap(&arr->A[i],&arr->A[j]);

}

void leftshift(struct Array *arr)
{

    for(int i=0;i<arr->length-1;i++)
        arr->A[i]=arr->A[i+1];
    arr->A[arr->length-1]=0;

    }

//void leftrorate(struct Array *arr)
//{
//    int x=0;
//    x=arr->A[0];
//     for(int i=0;i<arr->length-1;i++)
//        arr->A[i]=arr->A[i+1];
//    arr->A[arr->length-1]=x;
//
//}
int main()
{
    int i,n;
    struct Array arr;
    cout<<"enter size of an array";
    cin>>arr.Size;
    arr.A=new int [arr.Size*sizeof(int)];
    arr.length=0;
    cout<<"enter number of numbers";
    cin>>n;
    cout<<"enter all number of numbers";
    for(i=0;i<n;i++)
    {
        cin>>arr.A[i];

    }
    arr.length=n;
    display(arr);
    cout<<"\n";
    reverse(&arr);
    cout<<"\n";
    display(arr);
    cout<<"\n";
    reverse2(&arr);
    cout<<"\n";
    display(arr);
    cout<<"\n";
    leftshift(&arr);
//    cout<<"\n";
//    display(arr);
//    cout<<"\n";
//    leftrorate(&arr);
//    cout<<"\n";
//    display(arr);
//    cout<<"\n";
    return 0;
}
