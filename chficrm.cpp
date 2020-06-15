#include<bits/stdc++.h>
using namespace std;

int isvalid(vector<int> v)
{
    int n=v.size();
    int fivecount=0;
        int tencount=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==5)
            fivecount++;
            else if(v[i]==10)
            {
                if(fivecount>0)
                {
                    fivecount--;
                    tencount++;
                }               
                else
                {
                    return 0;
                }
            }
            else
            {
                if(tencount>0)
                {
                    tencount--;
                }
                else if(fivecount>=2)
                {
                    fivecount-=2;
                }
                else
                {
                    return 0;
                }               
            }
        }
        return 1;
}
int main()
{
    int t;
    cin>>t;
    vector<string> result;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<int> v;
        int temp;
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            v.push_back(temp);
        }
        if(isvalid(v))
        result.push_back("YES");
        else
        {
            result.push_back("NO");
        }
        v.clear();
    }
    for(int i=0;i<t;i++)
    {
        cout<<result[i]<<endl;
    }
}