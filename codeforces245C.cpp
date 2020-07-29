#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N],ans;
void solve(){
  int n;cin>>n;
  for (int i = 1; i <= n; ++i)
  {
    cin>>a[i];
  }
  if(n<=2 or n%2==0){cout<<-1;return;}
  for(int i=n/2;i;i--){
    ans+=max(a[2*i],a[2*i+1]);
    a[i]-=max(0,a[i]-max(a[2*i],a[2*i+1]));
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