#include<iostream>
using namespace std;
void decimal(int x)
{
    if (x>1)
        decimal(x/2);
    cout<<x%2;
}

int main()
{
    int r,x;
    cin>>r;
    for(int i=0;i<r;i++)
    {
        cin>>x;
        decimal(x);
        cout<<"\n";
    }
    return 0;
}
