#include<bits/stdc++.h>
#define ll long long
using namespace std;
char ar[1001][1001];
ll dp[1001][1001];
ll n;
ll fun(ll i,ll j)
{
    if(i>n || j>n || i<1 || j<1) 
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll v1=fun(i+2,j+1);
    ll v2=fun(i-2,j+1);
    ll v3=fun(i+1,j+2);
    ll v4=fun(i-1,j+2);
    if(ar[i][j]=='P'){
        return dp[i][j]=1+max(v1,max(v2,max(v3,v4)));
    }
    else return dp[i][j]=max(v1,max(v2,max(v3,v4)));
}
int main()
{
    ll t,i,j,inn,jnn;
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cin>>ar[i][j];
                if(ar[i][j]=='K'){
                    inn=i;
                    jnn=j;
                }
            }
        }
        ll cnt=fun(inn,jnn);
        cout<<cnt<<endl;
    }
    return 0;
}
