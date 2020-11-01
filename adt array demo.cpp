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
// program for appending an element

void append(struct Array *arr,int x)
{
    if(arr->length < arr->Size)
        arr->A[arr->length++]=x;

}

// program to insert a element at position x

void Insert(struct Array *arr,int index ,int x)
{
    if(index>=0 && index<=arr->length)
    {
        for(int i=arr->length;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];

        }
        arr->A[index]=x;
        arr->length++;

    }
}

// delete operation in an array
int Delete(struct Array *arr,int index)
{
    int x=0;
    if(index>=0 && index<=arr->length)
    {
        x=arr->A[index];
        for(int i=index;i<arr->length;i++)
        {
            arr->A[i]=arr->A[i+1];

        }
        arr->length--;
        return x;

    }
    else
        return -1;

}

// program to find an element in an array
void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int LinearSearch(struct Array arr,int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
        return i;
    }
    return -1;
}

//methods to improve linear search

int LinearSearchTransposition(struct Array *arr,int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
            Swap(&arr->A[i],&arr->A[i-1]);
            return i;
    }
    return -1;
}

int LinearSearchMoveToFront(struct Array *arr,int key)
{
     for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
            Swap(&arr->A[0],&arr->A[i]);
            return 0;
    }
    return -1;
}


int Binarysearchiterative(struct Array arr,int key)
{
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=int((l+h)/2);
        if(key==arr.A[mid])
        return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;


    }
    return -1;
}

//int BinarySearchRecursive(int arr.A[],int l,int h,int key)
//{
//    int mid;
//    while(l<=h)
//    {
//        mid=int((l+h)/2);
//        if(key==arr.A[mid])
//            return mid;
//        else if(key<arr.A[mid])
//            return BinarySearchRecursive(arr.A[],l,mid-1,key)
//        else
//            return BinarySearchRecursive(arr.A[],mid+1,h-,key)
//    }
//    return -1;
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
    cout<<"output of append \n";
    append(&arr,7);
    display(arr);
    cout<<"\n";
    cout<<"output of insert \n ";
    Insert(&arr,2,3);
    display(arr);
    cout<<"\n";
    cout<<"output of deletion \n ";
    cout<<Delete(&arr,4);
    cout<<"\n";
    display(arr);
    cout<<"\n";
    cout<<"final array after appending insertion and deletion \n";
    display(arr);
    cout<<"\n";
    cout<<"output for linear search \n";
    cout<<LinearSearch(arr,5);
    cout<<"\n";
//    cout<<"linear search transposition output \n";
//    cout<<LinearSearchTransposition(&arr,5);
//    cout<<"\n";
//    cout<<"linear search move to front output \n";
//    cout<<LinearSearchMoveToFront(&arr,5);
//    cout<<"\n";
    cout<<"binary search output \n";
    cout<<Binarysearchiterative(arr,5);
    cout<<"\n";
    display(arr);

    return 0;
}
