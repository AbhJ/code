#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
// const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
priority_queue<int , vector<int>, greater<int> > a[N];
void solve(){
  int n,k;cin>>n>>k;
  for (int i = 0; i < n; ++i)
  {
    int x;cin>>x;int y=0;
    while(1){
      if(x==0)break;
      a[x].push(y);
      y++,x=x>>1;
    }
  }
  int mi=1e9;
  for (int i = 0; i < N; ++i)
  {
    int cost=0,num=0;
    if(a[i].size()<k)continue;
    while(a[i].empty()==0 and num<k){
      num++;cost+=a[i].top();a[i].pop();
      // cout<<2;
    }
    // cout<<1;
    // cout<<i<<" "<<cost<<"\n";
    mi=min(mi,cost);
  }
  cout<<mi;
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