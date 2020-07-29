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
void solver(){
    int n;cin>>n;std::vector<int> a(n),b(n);int c=0;
    for (int i = 0; i < n; ++i)cin>>a[i];
    for (int i = 0; i < n; ++i)cin>>b[i];
    std::map<int, int> map;int i=0;
    while(1){
        sort(a.begin(), a.end());sort(b.begin(), b.end());
        std::vector<int> store;
        for (;i<a.size() and i<b.size(); ++i)
        {
            if(b[i]<=a[i])c=2;
            store.pb(a[i]);
            if(i)if(!map.count(a[i]))c=1;
            if(c)break;
            map[a[i]]++,map[b[i]]++;
            store.pb(b[i]);
        }
        if(i>=a.size() or i>=b.size())break;
        if(c==1){
            swap(a,b);map.clear();
        }
        if(c==2){
            for (int i = 0; i < store.size(); ++i)
            {
                b.pb(store[i]);
            }
        }
        if(!c)break;
    }
    if(c)cout<<"NO\n";else cout<<"YES\n";
}
void solve(){
    int n;cin>>n;std::vector<int> a(n),b(n);
    for (int i = 0; i < n; ++i)cin>>a[i];
    for (int i = 0; i < n; ++i)cin>>b[i];
    sort(a.begin(), a.end());sort(b.begin(), b.end());
    std::map<int, int> map;bool c=0;cout<<"\n";
    for (int i = 0; i < n; ++i)
    {
        if(b[i]<=a[i])c=1;
        if(i)if(!map.count(a[i]))c=1;
        if(c)break;
        map[a[i]]++,map[b[i]]++;
    }
    if(c)cout<<"NO\n";else cout<<"YES\n";
}
int main()
{   
    ibs;cti;
    int t,x;cin>>t>>x;
    while(t--)
    if(x==1)solve(),cout<<"\n";
    else solver(),cout<<"\n";
    return 0;
}