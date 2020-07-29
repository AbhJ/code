#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
pair<ll,ll> a[N];priority_queue<int>q;
int n,k;
void solve(){
  cin>>n>>k;
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i].S>>a[i].F;
  }
  sort(a,a+n);
  ll len=0,mi=1e9,ans=0;
  for(int i=n-1;i>-1;i--){
    len+=a[i].S;
    q.push(-a[i].S);//min length on top
    if(q.size()>k)len+=q.top(),q.pop();//at most k elements
    ans=max(ans,len*a[i].F);
  }
  cout<<ans;
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}