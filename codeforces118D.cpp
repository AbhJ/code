#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
// const int N=2e7+3;
const int M = 1e8; // modulo
ll dp[110][110][15][15];
int F,H;
int solve(int f,int h,int k1,int k2){
    if(f+h==0)return 1;
    int footcomb=0, horsecomb=0;
    if(dp[f][h][k1][k2]!=-1)return dp[f][h][k1][k2];
    //footman occupy
    if((k1>0) and (f>0))footcomb=solve(f-1,h,k1-1,H);
    //horseman occupy
    if((k2>0) and (h>0))horsecomb=solve(f,h-1,F,k2-1);
    return dp[f][h][k1][k2]=(footcomb+horsecomb)%M;
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    memset(dp,-1,110*110*15*15*sizeof(ll));
    int n1,n2;cin>>n1>>n2>>F>>H;
    cout<<solve(n1,n2,F,H)<<"\n";
    return 0;
}