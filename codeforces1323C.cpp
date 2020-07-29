#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
vector<int> fa(int n1){
    vector<int> v;
    for(int i=1;i<=sqrt(n1);++i)
    {
        if(n1%i==0)
        {
            v.push_back(i);
            if(i*i!=n1)
                v.push_back(n1/i);
        }
    }
    return v;
}
void solve(){
    int n,o=0,c=0,ans=0;string s;cin>>n>>s;
    for (int i = 0; i < n; ++i)
    {
        if(s[i]=='('){
            o++;
        }
        if(s[i]==')'){
            c++;if(c>o)ans+=2;
        }
    }
    if(o!=c)ans=-1;
    cout<<ans;
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    solve(),cout<<"\n";
    return 0;
}