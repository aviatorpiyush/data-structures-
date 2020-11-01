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
void rearrnge(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)Swap(&arr->A[i],&arr->A[j]);

    }
}
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

    rearrnge(&arr);
    display(arr);

    return 0;
}
