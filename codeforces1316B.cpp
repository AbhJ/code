#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
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
    int n;cin>>n;std::vector<int> pos;
    string s;cin>>s;char a=s[0];
    for (int i = 0; i < n; ++i)
    {
        if(s[i]<a)a=s[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if(s[i]==a)pos.pb(i);
    }
    std::vector<pair<string,int>> v;
    for (int i = 0; i < pos.size(); ++i)
    {
        int p=pos[i];
        string x,y;
        x=s.substr(p);
        y=s.substr(0,p);
        if(n%2!=p%2)reverse(y.begin(), y.end());
        x=x+y;
        v.pb({x,p});
    }
    sort(v.begin(), v.end());
    cout<<v[0].first<<"\n"<<v[0].second+1;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}