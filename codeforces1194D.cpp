#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n,k;cin>>n>>k;bool c=0;
  if(n%3!=0 and k%3!=0){cout<<"Alice";return;}
  if(k%3!=0){cout<<"Bob";return;}
  int x=(n)%(k+1);
  if(x==k)c=1;
  else if(x%3!=0)c=1;
  if(c==0)cout<<"Bob";else cout<<"Alice";
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}