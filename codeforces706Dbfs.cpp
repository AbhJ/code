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
ll dp[N+1][2];//0 means normal 1 for reverse
int b(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if(mid<=r)if ((arr[mid+1] > x) and (arr[mid]<=x)) 
            return mid; 
        if((mid==r-l) and (arr[r-l]<=x))
          return r-l;  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return b(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return b(arr, mid+1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1;
}
void solve(){
    std::map<int, int> map;char x;int y,q;
    cin>>q;
    while(q--){
      cin>>x>>y;
      if(x=='+')map[y]++;
      if(x=='-')map[y]--;
      if(x=='?'){
        std::vector<int> v;
        for(auto it = map.begin(); it != map.end(); ++it) {
          if((it->second)>0)v.push_back(it->first);
        }
        int ans=0;
        for (int i = 0; i < v.size(); ++i)
        {
          ans=max(y^v[i],ans);
        }
        cout<<ans<<" ";
      }
    }
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    solve(),cout<<"\n";
    return 0;
}