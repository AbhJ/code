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
  ll n;cin>>n;ll x,c1=0,c2=0,C=0,C1=0;
  for (int i = 0; i < n; ++i)
  {
    cin>>x;c1++;if(x<0)swap(c1,c2);
    C+=c1;
  }
  C1=n*(n+1);C1=C1>>1;C1-=C;
  cout<<C1<<" "<<C;
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