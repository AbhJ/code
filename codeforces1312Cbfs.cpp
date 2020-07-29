#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
// const int N=300;
const ll M = 1e18; // modulo
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
double dist(pair<double,double>a,pair<double,double>b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
void solve(){
    ll n,k;cin>>n>>k;std::vector<ll> v(n);bool check=1;ll ma=0,store=-1;
    // the following works when sizes of ai's are small.
    for (ll i = 0; i < n; ++i)cin>>v[i];
    for(ll z=0;z<70*n;z++){
        ma=0;
        for (ll i = 0; i < n; ++i)
        {
            ll j=0;
            for(j=0;(ll)pow(k,j)<=v[i];j++);
            ma=max(ma,j-1);/*cout<<ma;*/
        }
        if(ma==store)break;
        ll count=0;
        for (ll i = 0; i < n; ++i)
        {
            if(((ll)pow(k,ma)<=v[i]))
                count++,v[i]-=(ll)pow(k,ma);
        }
        if(count>1){
            // for (int i = 0; i < n; ++i)cout<<v[i]<<" "; 
            cout<<"NO\n";return;}
        if(!ma)break;
        store=ma;
    }
    for (ll i = 0; i < n; ++i)
    {
        if(v[i]){
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";
    // memset(a,0,sizeof(a));
    // for (ll i = 0; i < n; ++i)
    // {
    //     ll t,c=0;cin>>t;
    //     while(t){
    //         a[c]+=t%k;
    //         t/=k;
    //         if(a[c]>=2)check=0;c++;
    //     }
    // }
    // if(check)cout<<"YES\n";
    // else cout<<"NO\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}