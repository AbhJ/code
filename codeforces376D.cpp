#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
const int N=5e3+3;
int dp[N+1][N+1];int dp2[N+1][N+1];
void solve(){
    int n,m;cin>>n>>m;memset(dp,0,sizeof(dp));
    string a[n];memset(dp2,0,sizeof(dp2));
    for (int i = 0; i < n; ++i)cin>>a[i];
    for (int i = 0; i < n; ++i){
        for(int j=m-1;j>-1;j--){
            if(a[i][j]=='0')    dp[i][j]=0;
            else    dp[i][j]=dp[i][j+1]+1;
        }
    }
    for (int i = 0; i < n; ++i)
        for(int j=0;j<m;j++)
            dp2[j][i]=dp[i][j];
    // for (int i = 0; i < m; ++i){
    //     for(int j=0;j<n;j++)
    //         cout<<dp2[i][j];
    //     cout<<"\n";
    // }
    int ans=0;
    for (int i = 0; i < m; ++i){
        sort(dp2[i],dp2[i]+n);
        for (int j = 0; j < n; ++j)
           ans=max(ans,dp2[i][j]*(n-j));
    }
    cout<<ans;
}
int main()
{   
    ibs;cti;
    solve(),cout<<"\n";
    return 0;
}