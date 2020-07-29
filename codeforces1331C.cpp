#include <bits/stdc++.h>
// #include <numeric>
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
int i,a[10],ans;
void solve(){
  int n;cin>>n;
  while(n)a[++i]=n%2,n/=2;
  swap(a[1],a[5]);swap(a[3],a[4]);
  for(i=9;i;i--)ans=ans*2+a[i];
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