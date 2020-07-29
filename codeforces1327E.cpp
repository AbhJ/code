#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll c[N];
void solve(){
  int n;cin>>n;c[0]=1;
  for(int i=1;i<=n;i++)c[i]=(10*c[i-1])%M;
  for(int i=1;i<n;i++)
    cout<<(18*c[n-i]+81*c[n-i-1]*(n-i-1))%M<<" ";
  cout<<10;
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