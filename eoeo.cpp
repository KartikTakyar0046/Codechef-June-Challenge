#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll mpow(ll base, ll exp){
    ll result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((ll)result * base) ;
        base = ((ll)base * base);
        exp >>= 1;
    }
    return result;
}
void solve()
{
    ll n;
    cin>>n;
    ll x=n;
    ll po=0;
    while(x%2==0)
    {
        po++;
        x/=2;
    }
    po++;
    ll ans=(ll)n/mpow(2,po);
    cout<<ans<<endl;
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
