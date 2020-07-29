#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
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
    int x,y;cin>>x>>y;
    if(x==1 and y==1)cout<<25<<"\n";
    else if(x==y){
        cout<<26<<"\n";
        cout<<1<<" "<<1<<"\n";
    }
    else{
        cout<<27<<"\n";
        cout<<((x+y)>>1)<<" "<<((x+y)>>1)<<"\n";
        cout<<1<<" "<<1<<"\n";
    }
    x=y=1;
    while(1){
        x++;y++;
        cout<<x<<" "<<y<<"\n";
        cout<<2*x-1<<" "<<1<<"\n";
        cout<<1<<" "<<2*y-1<<"\n";
        cout<<x<<" "<<y<<"\n";
        if(x==4)break;
    }
    while(1){
        x--;y--;
        cout<<8-x<<" "<<8-y<<"\n";
        cout<<8-2*x<<" "<<8<<"\n";
        cout<<8<<" "<<8-2*y<<"\n";
        cout<<8-x<<" "<<8-y<<"\n";
        if(x==1)break;
    }
    cout<<8<<" "<<8<<"\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}