#include<iostream>
using namespace std;
class diagonal
{
    private:
        int n;
        int *A;
    public:
        diagonal(int n)     // constructor to assign n and A

        {
            this->n=n;
            A=new int [n*sizeof(int)];

        }
        void set(int i,int j, int x);
        void get(int i,int j);
        void display();
        ~diagonal()
        {
            delete[]A;
        }        // destructor to delete th dynamically allocated Array A

};
void diagonal:: set(int i,int j,int x)
{
    if(i==j)
    {
        A[i]=x;
    }
}
void diagonal:: get(int i,int j)
{
    if(i==j)
    {
        cout<<A[i];
    }
    else
        cout<<0;
}

void diagonal::display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                cout<<A[i];

            else
                cout<<"0";
       }
    cout<<endl;
    }

}

int main()
{
    diagonal d(4);
    d.set(0,0,2);
    d.set(1,1,4);
    d.set(2,2,6);
    d.set(3,3,8);
    d.display();


    return 0;
}
