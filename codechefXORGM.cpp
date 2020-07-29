#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
const int M = 1000000007; // modulo
// ll dp[1000][1000];
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
vector<int> fact(int n)
{
    vector<int> v;
    for(int i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n)
                v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return v;
}
void solve(){
  int n;cin>>n;
  std::vector<int> a(n),b(n),c(n);
  for (int i = 0; i < n; ++i)cin>>a[i];
  int x=a[0];
  for (int i = 1; i < n; ++i)x^=a[i];
  for (int i = 0; i < n; ++i)cin>>b[i],x^=b[i];
  sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i)
  {
    if(binary_search(b.begin(),b.end(),a[i]^x))
      c[i]=a[i]^x;
    else {cout<<-1<<"\n";return;}
  }
  for (int i = 0; i < n; ++i)
  {
    cout<<c[i]<<" ";
  }
  cout<<"\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)solve();
    cout<<"\n";
    return 0;
}