#include <bits/stdc++.h>
#define int long long int
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
int n,m,c,x,a[N],b[N];
void solve(){
  cin>>n>>m>>c;
  for(int i=0;i<=n-1;i++)cin>>a[i];
  for(int i=0;i<=m-1;i++)cin>>b[i];
  for(int i=0;i<=n-1;i++){
    if(i<m)x+=b[i];if(i>n-m)x-=b[i-n+m-1];
    cout<<(a[i]+x)%c<<" ";
  }
}
int32_t main(){
  solve();return 0;
}