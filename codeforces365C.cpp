#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+3;
const ll M = 998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  ll a,c=0;cin>>a;string s;cin>>s;int n=s.length();std::map<ll, ll> map;
  for (int xs = 0; xs < n; ++xs){
      ll ans=0;
      for (int i = xs; i < n; ++i){
        ans+=s[i]-'0';map[ans]++;
      }
  }
  for (int xs = 0; xs < n; ++xs){
      ll ans=0;
      for (int i = xs; i < n; ++i){
        ans+=s[i]-'0';if(ans>a)break;
        if(!ans)continue;
        if(!(a%ans))c+=map[a/ans];
      }
  }
  if(!a)for(int i=1;i<=9*n;i++)c+=map[0]*map[i]*2;
  if(!a)c+=map[0]*map[0];
  cout<<c;
}
int main()
{   
    ibs;cti;
    solve(),cout<<"\n";
    return 0;
}