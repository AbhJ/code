#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
// const int N=2e7+3;
const int N=300;
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
bool solve(int x){
    if(!x)return false;
          if ((x & (x - 1)) != 0)
        return false;
    return true;
}
// char a[1010],b[1010];int dp[1010][1010];int check[1010][1010];
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    int n;cin>>n;bool x=0;int y;
    for(int i=0;i<n;i++){cin>>y;if(solve(y))x=1;}
    cout<<x<<"\n";
    return 0;
}