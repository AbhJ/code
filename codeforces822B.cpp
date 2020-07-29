#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
// std::vector<pair<int,int>> S[200009];//index are duration
int main()
{
    ibs;cti;
    int n,m;cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int ans=0,index;std::vector<int> v;
    for (int i = 0; i <= t.length()-s.length(); ++i)
    {
        int num=0;
        std::vector<int> temp;
        for (int j = 0; j < s.length(); ++j)
        {
            if(t[i+j]==s[j])
                num++;
            // cout<<num;
            else temp.pb(j+1);
        }
        if(num>ans){
            ans=num;
            v=temp;
        }
    }
    // cout<<ans<<"\n";
    if(ans==s.size()){cout<<0<<"\n";return 0;}
    if (v.size())
    {
        cout<<v.size()<<"\n";
        for (int i = 0; i < v.size(); ++i)
        {
            cout<<v[i]<<" ";
        }
    }
    else {
        cout<<n<<"\n";
        for (int i = 1; i < n+1; ++i)
        {
            cout<<i<<" ";
        }
    }    
    return 0;
}