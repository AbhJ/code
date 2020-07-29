#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e4+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N],l[N],r[N];bool b[N];
void solve(){
  int n,k;cin>>n>>k;int ans=0;
  for (int i = 1; i <= n; ++i)
  {
    cin>>l[i]>>r[i];
    for(int j=l[i];j<=r[i];j++)a[j]++;
  }
  for (int i = 1; i <= 500; ++i)
  {
    while(a[i]>k){
      int x=0;
      for (int j = 1; j <= n; ++j)
      {
        if(b[j])continue;
        if(l[j]<=i and (!x or r[j]>=r[x]))x=j;
      }
      for(int j=l[x];j<=r[x];j++)a[j]--;
      b[x]=1;ans++;
    }
  }
  cout<<ans<<"\n";
  for (int i = 1; i <= 500; ++i)
  {
    if(b[i])cout<<i<<" ";
  }
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}