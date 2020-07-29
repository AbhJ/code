#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
   int n,m,k;cin>>n>>m>>k;std::vector<ll> v(n+1);
   for (int i = 1; i <= n; ++i) cin>>v[i];
   ll ma=0;k=min(k,m-1);
   for (int x = 0; x <= k; ++x){
        ll X=1e9;
       for(int y=0;y<=m-k-1;y++)
            X=min(X,max(v[x+y+1],v[n-m+x+y+1]));
       ma=max(ma,X);
   }
   cout<<ma;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}