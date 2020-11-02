#include<iostream>
using namespace std;
struct array
{
    int A[20];
    int size;
    int length;

};
void display(struct array arr)
{
    cout<<"elements are";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

void insert(struct array *arr ,int index,int x)
{
    if(index>=0 && index<=arr->length)
    for(int i=arr->length;i>index;i--)
    {
        arr->A[i]=arr->A[i-1];

    }
    arr->A[index]=x;
    arr->length++;
}

int Delete(struct array *arr,int index)
{
    int x=0;
    if(index>=0 && index<=arr->length)
    {
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;

    }

    else return 0;
}

int linearsearch(struct array arr,int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]==key)
        {
            cout<<"element found in linear search at index"<<i<<"\n";
            return key;
        }
    }

    return -1;

}

int binarysearch(struct array arr,int key)
{
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
        {
            cout<<"element found in binary search at index "<<mid<<"\n";
            return key;
        }
        else if(key<arr.A[mid])
                h=mid-1;
            else
                l=mid+1;
    }

    return -1;

}

int main()
{

    struct array arr={{2,4,6,8,10,12},10,6};
    display(arr);
    cout<<"\n";
    cout<<"inserting element 9 at index 4"<<"\n";
    insert(&arr,4,9);
    cout<<"\n";
    display(arr);
    cout<<"\n";
    cout<<"deleting elements 9 at index 4";
    cout<<"\n";
    cout<<Delete(&arr,4);
    cout<<"\n";
    display(arr);
    cout<<"\n";
    cout<<"searching for an element"<<"\n";
    cout<<linearsearch(arr,6);
    cout<<"\n";
    cout<<binarysearch(arr,6);

    return 0;
}
