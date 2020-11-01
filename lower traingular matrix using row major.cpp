
#include<iostream>
using namespace std;
struct matrix
{
    int *A;
    int n;
};
void set(struct matrix *m,int i,int j,int x)
{
    if(i>=j)
        m->A[i*(i+1)/2+j]=x;

}

int get(struct matrix m,int i,int j)
{
    if(i>=j)
        return m.A[i*(i+1)/2+j];
    else
        return 0;

}

void display(struct matrix m)
{
    int i,j;
    for(i=0;i<m.n;i++)
    {
        for(j=0;j<m.n;j++)
        {
            if(i>=j)
                cout<<m.A[i*(i+1)/2+j];
            else
                cout<<"0";
        }
    cout<<endl;

    }
}

int main()
{
    int i,j,x;
    struct matrix m;
    cout<<"enter dimensions";
    cin>>m.n;
    m.A=new int [m.n*(m.n-1)/2*sizeof(int)];
    cout<<"enter all elements";
    for(i=0;i<m.n;i++)
    {
        for(j=0;j<m.n;j++)
        {
            cin>>x;
            set(&m,i,j,x);


        }
    }

    cout<<"\n\n";
    display(m);
    return 0;

    }
