#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
// const int N=300;
const int M = 1e8; // modulo
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
ll div(ll n)
{
    int d[1000001]={0};
    for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)
            d[j]++;
    return d[n];
}
ll dist(pair<ll,ll>a,pair<ll,ll>b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
void solve(){
    int n;cin>>n;std::vector<int> a(n),b(n);
    for (int i = 0; i < n; ++i)cin>>a[i];
    for (int i = 0; i < n; ++i)cin>>b[i];
    int lose=0,win=0;
    for (int i = 0; i < n; ++i)
    {
        if(a[i]==0 and b[i]==1)lose++;
        if(b[i]==0 and a[i]==1)win++;
    }
    int x=0;
    if(win and !(lose%win)){x=lose/win+1;if(x*win<=lose)x++;}
    else if(win){x=max(1,lose/win);if(x*win<=lose)x++;}
    else x=-1;cout<<x;}

int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    solve();cout<<"\n";
    return 0;
}