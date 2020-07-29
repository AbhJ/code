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
const ll M = 998244353; // modulo
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
long long C(long long n,long long r)
{
    long long N=1,R=1;
    for(long long i=1;i<=n;i++) N=N*i%M;
    for(long long i=1;i<=r;i++) R=R*i%M;
    for(long long i=1;i<=n-r;i++) R=R*i%M;
    return (N*powM(R,M-2))%M;
}
int binarySearch(int arr[], int l, int r, int x,int n) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if ((arr[m] <= x) and ( (arr[m+1]>x) or (m+1==n)) /*and (m>0)*/) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
}
void solve(){
    int n,x,y;cin>>n>>x;set<int>s;int m=INT_MIN;
    for (int i = 0; i < n; ++i)cin>>y,m=max(m,y),s.insert(y);int c=0;
    if(s.count(x))cout<<1;else
    cout<<max(2,(x+m-1)/m);
    // sort(v,v+n);
    // while(1){
    //     if(v[n-1]>x){
    //         cout<<2;return;
    //     }
    //     // cout<<binarySearch(v,0,n-1,x);
    //     if(binarySearch(v,0,n-1,x,n)!=-1){
    //         int pos=binarySearch(v,0,n-1,x,n);
    //         // cout<<x;
    //         x-=v[pos];c++;
    //         if(x==0)break;
    //         if(v[0]>=x){c++;break;}
    //     }
    //     else break;
    //     if(x==0)break;
    // }
    // cout<<c;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}