#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M =  998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll dp[2];
void solve(){
  ll n;cin>>n;string s;cin>>s;ll ans=n*(n-1)/2;
  dp[0]=dp[1]=-1;ll c=1;
  for (int i = 1; i < n; ++i)
  {
    if(s[i]==s[i-1])c++;//good pair
    else ans-=c,c=1;
  }
  c=0;
  for (int i = n-2; i >-1; --i)
  {
    if(s[i]==s[i+1])c++;
    else ans-=c,c=0;
  }
  cout<<ans;
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