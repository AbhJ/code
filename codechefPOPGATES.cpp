#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
// const int N=300;
const int M = 1e8; // modulo
void solve(){
    int n,k;cin>>n>>k;int h=0,t=0,pos=n-k,set=0;
    std::vector<char> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>s[i];
    }
    while(k--){
        char x=s.back();
        if(x=='H')
            for (int i = 0; i < s.size(); ++i)
            {
                if(s[i]=='T')s[i]='H';
                else if(s[i]=='H')s[i]='T';
            }
        s.pop_back();
    }
    for (int i = 0; i < s.size(); ++i)
    {
         if(s[i]=='H')h++;
    }
    cout<<h<<"\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve();cout<<"\n";
    return 0;
}