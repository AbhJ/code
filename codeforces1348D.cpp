#include <iostream>
#include <algorithm>
using namespace std;//coded by abhijay mitra
const int N=2e5+10;long long a[N];
void solve(){
  int n;cin>>n;int i,j=0,z;
  for (i = 0;n; i++)z=min(n,1<<i),a[j++]=z,n-=z;
  sort(a,a+j);cout<<j-1<<"\n";
  for (int i = 1; i < j; ++i)cout<<a[i]-a[i-1]<<" ";
}
int main(){
  int t;cin>>t;while(t--){solve();cout<<"\n";}return 0;
}