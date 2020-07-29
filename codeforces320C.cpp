#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+3;
const ll M = 1000000007; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  string s;cin>>s;int n=s.length();
  for (int i = 0; i < n-1; ++i)
  {
    s+='0';
  }      
  ll ans=0;
  for (int i = 0; i < 2*(n-1)+1; ++i)
  {
    ans+=ans+s[i]-'0';ans%=M;
  }
  cout<<ans;
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    solve(),cout<<"\n";
    return 0;
}