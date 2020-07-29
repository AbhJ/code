#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n;cin>>n;std::vector<int> v(n+1,0);
  std::vector<int> pos,r,l;
  int len=0,st=-1;bool b=0;
  for (int i = 1; i <= n; ++i)
  {
    int x;cin>>x;
    if(x%4==0){x=2;}
    else if(x%2==0){x=1;}
    else x=0;
    // if(i==0)v[i]=x;
    v[i]=x;
  }
  for (int i = 1; i <= n; ++i)
  {
    if(len==0)st=i;
    if(v[i]==2){
      if(st!=1 and b)r.pb(len);b=0;len=0;
    }
    if(v[i]==1){
      if(st!=1 and b)r.pb(len);len=0;b=1;
    }
    if(v[i]==0){
      len++;
    }
  }
  if(b)r.pb(len);
  // for(auto i:r)cout<<i<<" ";cout<<"\n";

  // reverse(v.begin()+1, v.end());
  // len=0,st=-1,b=0;
  // for (int i = 1; i <= n; ++i)
  // {
  //   if(len==0)st=i;
  //   if(v[i]==2){if(st!=1)l.pb(len);len=0;b=0;}
  //   else if(v[i]==1){pos.pb(i);/*if(st!=1)*/l.pb(len);len=0;b=1;}
  //   else len++;
  //   // if(i==0)v[i]=x;
  //   // v[i]=x;
  // }
  // if(b)l.pb(len);
  // reverse(l.begin(), l.end());
  // for(auto i:l)cout<<i<<" ";
  len=0;st=-1;b=0;
  for(int i=n;i;i--){
    if(len==0)st=i;
    if(v[i]==2){
      if(st!=n and b)l.pb(len);b=0;len=0;
    }
    if(v[i]==1){
      if(st!=n and b)l.pb(len);len=0;b=1;
    }
    if(v[i]==0){
      len++;
    }
  }
  if(b)l.pb(len);
  reverse(l.begin(), l.end());
  // for(auto i:l)cout<<i<<" ";
  ll ans=1LL*n*(n+1)/2;
  for (int i = 0; i < l.size(); ++i)
  {
    ans-=1LL*(l[i]+1)*(r[i]+1);
  }
  cout<<ans;
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}