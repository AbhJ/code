#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
// const int N=300;
const int M = 1e8; // modulo
 int lcm(int a, int b)  
 {  
    return (a*b)/__gcd(a, b);  
 }  
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
  int n;cin>>n;std::vector<int> b(n),a(2*n);bool c=0;
  bool p[208];memset(p,0,208*sizeof(*p));
  for (int i = 0; i < n; ++i)
  {
     cin>>b[i];if(b[i]>=2*n)c=1;p[b[i]]=1;
  }
  if(c){cout<<-1;return;}
  for (int i = 0; i < 2*n; ++i,++i)
  {
    a[i]=b[i/2];bool x=0;
      for (int j = a[i]+1; j < 2*n+1; ++j)
      {
          if(!p[j]){p[j]=1,a[i+1]=j,x=1;break;}
      }
    // if(a[i]<a[i+1])swap(a[i],a[i+1]);
      if(!x)
        c=1;
  }
  if(c){cout<<-1;return;}
  for (int i = 0; i < 2*n; ++i)
  {
      cout<<a[i]<<" ";
  }
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}