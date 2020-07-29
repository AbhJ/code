#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    int n;cin>>n;ll a[n][n],ans;
    for (int i = 0; i < n; ++i)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    ans=a[0][1]*a[0][2]/a[1][2];
    ans=sqrt(ans);cout<<ans<<" ";
    for (int i = 1; i < n; ++i)
        cout<<a[i][0]/ans<<" ";
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}