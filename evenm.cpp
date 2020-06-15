#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    ll array[n][n];
    int k=1;
    ll i,j;
    if(n%2!=0)
    {
        for( i=0;i<n;i++)
        {
            for( j=0;j<n;j++)
            {
                array[i][j]=k++;
            }
        }
    }
    else
    {
        for( i=0;i<n;i++)
        {
            for( j=0;j<n;j++)
            {
                array[i][j]=k++;
            }
        }
        for( i=0;i<n;i++)
        {
            if(i%2!=0)
            {
                for( j=0;j<n/2;j++)
                {
                    swap(array[i][j], array[i][n-1-j]);
                }
            }
        }
        
        
        
        
    }
    for( i=0;i<n;i++)
        {
            for( j=0;j<n;j++)
            {
                cout<<array[i][j]<<" ";
            }
            cout<<endl;
        }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}