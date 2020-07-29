#include <bits/stdc++.h>
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
std::vector<int> v[N];
void solve(){
    int n,x;cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>x,v[x].pb(i+1);
    std::vector<int> ans(n);int a=0;
    for (int i = 0; i < n; ++i)
    {
        while(v[a].empty())a-=3;
        if(a<0){cout<<"Impossible\n";return;}
        ans[i]=v[a].back();
        v[a].pop_back();
        a++;
    }
    cout<<"Possible\n";
    for (int i = 0; i < n; ++i)
        cout<<ans[i]<<" ";
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}