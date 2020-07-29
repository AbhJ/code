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
  int n;cin>>n;std::vector<int> v(n);
  for (int i = 0; i < n; ++i)cin>>v[i];int ans=0,c=2;
  if(n<=2){cout<<n;return;}
  for(int i=2;i<n;i++){
    while((v[i]==v[i-1]+v[i-2]) and i<n)c++,i++;
    ans=max(c,ans);c=2;
  }
  cout<<ans;
}
int main()
{   
    ibs;cti;
    solve(),cout<<"\n";
    return 0;
}