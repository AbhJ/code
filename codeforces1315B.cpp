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
    int a,b,p,i;cin>>a>>b>>p;char c;
    string s;cin>>s;int n=s.length();
    // int dp[n][2];memset(dp,0,(n+1)*2*sizeof(int));
    // if(s[n-1]=='A')dp[n-1][0]=1;else dp[n-1][1]=1;
    // cout<<n-1<<" "<<dp[n-1][0]<<" "<<dp[n-1][1]<<"\n";
    // for (int i = n-2; i >-1; --i)
    // {
    //   dp[i][0]=dp[i+1][0];dp[i][1]=dp[i+1][1];
    //   if(s[i]==s[i+1]);
    //   else if(s[i]=='A')dp[i][0]++;
    //   else dp[i][1]++;
    //   cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    // }int i;
    // for (i = 0; i < n; ++i)
    // {
    //   if(dp[i][0]*(ll)a + dp[i][1]*(ll)b<=p)break;
    // }
    // cout<<(min(i+1,n)==n?n:i+1)<<"\n";
    for (i=n-2,c='?'; i>=0; --i)
    {
      if (c!=s[i])
      {
        c=s[i];
        p-=(c=='A'? a: b);
        if (p<0) break;
      }
    }
    cout<<i+2<<endl;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}