#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n;cin>>n;string s;cin>>s;int x=0,lq=0,rq=0;ll L=0,R=0;
  for (auto i:s)
  {
    x++;
    if(i=='?'){if(x<=n/2)lq++;else rq++;continue;}
    if(x<=n/2)L+=i-'0';else R+=i-'0';
  }
  ll l=L-R-rq*9,r=L-R+lq*9;
  if(l+r)cout<<"Monocarp";else cout<<"Bicarp";
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