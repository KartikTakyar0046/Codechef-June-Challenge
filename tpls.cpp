#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll a[3], p[3];
int check(int same,int opts)
{
    int s1=(same+1)%3;
    int s2=(same+2)%3;
    if(p[s1]-a[s1]==p[s2]-a[s2])
    return opts;
    if(a[s1] && a[s2] && p[s1]%a[s1]==0 && p[s2]%a[s2]==0)
    {
        if(p[s1]/a[s1]==p[s2]/a[s2])
        return opts;
    }
    return opts+1;
}
void solve()
{
    cin>>a[0]>>a[1]>>a[2]>>p[0]>>p[1]>>p[2];
    int same=0;
    int sn;
    if(a[0]==p[0])
    {
        same++;
        sn=0;
    }
    if(a[1]==p[1])
    {
        same++;
        sn=1;
    }
    if(a[2]==p[2])
    {
        same++;
        sn=2;
    }
    if(same==3)
    {
        cout<<"0"<<endl;
        return;
    }
    if(same==2)
    {
        cout<<"1";
        return;
    }
    if(same==1)
    {
        int ans=check(sn,1);
        cout<<ans<<endl;
        return;
    }
    if(p[0]-a[0]==p[1]-a[1] && p[0]-a[0]==p[2]-a[2]) 
    {
        cout<<"1";
        return;
    }
    //teeno main relation satisfied toh ans=1
    if(a[1] && a[2] && a[0] && p[1]%a[1]==0 && p[2]%a[2]==0 && p[0]%a[0]==0) 
    {
        if(p[1]/a[1]==p[2]/a[2] &&p[1]/a[1]==p[0]/a[0]) 
        {
            cout<<"1";
            return;
        }
    }
    int flag=0;
    //kisi 2 mein koi relation satisfy hua toh ans=2  
    for(int i=0;i<3;i++)
    {
        int ans=check(i,2);
        if(ans==2)
        {
            cout<<"2";
            flag=1;
            break;
        }
    }
    if(flag)
    return;
    for(int i=0;i<3;i++)
    {
        int s1=(i+1)%3;
        int s2=(i+2)%3;
        if(a[s1]-a[s2]==0) continue;
      if((p[s2]-p[s1])%(a[s2]-a[s1])==0)  
      {
        ll m = (p[s2]-p[s1])/(a[s2]-a[s1]);
        ll c = p[s1] - a[s1]*m;
        if(m*a[i]+c==p[i]) 
        {
            cout<<"2"<<endl; 
            flag=1; 
            break;
        }    
        if(a[i]+c==p[i]) 
        {
            cout<<"2"<<endl; 
            flag=1; 
            break;
        } 
        if(m*a[i]==p[i]) 
        {
            cout<<"2"<<endl; 
            flag=1; 
            break;
        }

      }
    }
    if(flag)
    return;
    for(int i=0;i<3;i++)
    {   
        int s1=(i+1)%3;
        int s2=(i+2)%3;
        //++
        if(p[s1]-a[s1]+p[s2]-a[s2]==p[i]-a[i])
        {
            cout<<"2"<<endl;
            flag=1;
            break;
        }
        //+x
        if((a[i]+p[s1]-a[s1]) && a[s2] && p[i]%(a[i]+p[s1]-a[s1])==0 && p[s2]%a[s2]==0) 
        {
            if(p[i]/(a[i]+p[s1]-a[s1])==p[s2]/a[s2]) 
            {
                cout<<"2"<<endl; 
                flag=1; 
                break;
            }
        }
        if((a[i]+p[s2]-a[s2]) && a[s1] && p[i]%(a[i]+p[s2]-a[s2])==0 && p[s1]%a[s1]==0) 
        {
            if(p[i]/(a[i]+p[s2]-a[s2])==p[s1]/a[s1]) 
            {
                cout<<"2"<<endl;
                flag=1; 
                break;
            }
        }
      // x+
      if(a[s1] && p[s1]%a[s1]==0) 
    {
        if(((a[i]*p[s1]/a[s1]) + p[s2]-a[s2]) == p[i]) 
        {
            cout<<"2"<<endl; 
            flag=1; 
            break;
        }
    }
      if(a[s2] && p[s2]%a[s2]==0) 
      {
        if(((a[i]*p[s2]/a[s2]) + p[s1]-a[s1]) == p[i]) 
        {
            cout<<"2"<<endl; 
            flag=1;
            break;
        }
      }

      // xx
      if(a[0] && a[1] && a[2] && p[1]%a[1]==0 && p[2]%a[2]==0 && p[0]%a[0]==0) 
      {
        if(a[i] * p[s1] * p[s2] / (a[s1] * a[s2]) == p[i]) 
        {
            cout<<"2"<<endl; 
            flag=1; 
            break;
        }
      }
    }
    if(flag)
    return;
    for(int i=0;i<3;i++)
    {
        int s1 = (i+1)%3, s2 = (i+2)%3;
        ll plus = p[i] - a[i];
        ll an[3] = {0,a[s1]+plus,a[s2]+plus};
        if(an[1] && an[2]) 
        {
            if(p[s2]%an[2]==0 && p[s1]%an[1]==0) 
            {
                if(p[s2]/an[2]==p[s1]/an[1]) 
                {
                    cout<<"2"<<endl; 
                    flag=1; 
                    break;
                }
            }
        }
    }
    if(flag) return;
    cout<<"3"<<endl;
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