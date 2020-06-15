#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int m=t;
    vector<int> result;
    while(t--)
    {
        int n;
        int k;
        cin>>n>>k;
        vector<int> v;
        int sum=0;
        int dum=0;
        int temp;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            v.push_back(temp);
            sum+=v[i];
            if(v[i]>=k)
            v[i]=k;
            dum+=v[i];
        }
        result.push_back(sum-dum);
    }
    for(int i=0;i<m;i++)
    {
        cout<<result[i]<<endl;
    }
}