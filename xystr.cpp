#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    vector<string> stud;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        stud.push_back(s);
    }
    vector<int> result;
    int pairs=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<stud[i].size();j++)
        {
            if((stud[i][j]=='x' && stud[i][j+1]=='y') ||(stud[i][j]=='y' && stud[i][j+1]=='x'))
            {
                pairs++;
                j+=1;
            }
        }
        result.push_back(pairs);
        pairs=0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<result[i]<<endl;
    } 
}