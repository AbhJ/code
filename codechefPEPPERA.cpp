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
bool dp[N][N*N],p[N][N*N];
void solve(){
  int n;cin>>n;
  std::vector<string> v(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
  }
  int sum=0;
  std::vector<int> left(n+1,0),right(n+1,0);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n/2; ++j)
    {
      if(v[i][j]=='1')left[i+1]++;
    }
    for (int j = n/2; j < n; ++j)
    {
      if(v[i][j]=='1')right[i+1]++;
    }
    sum+=left[i+1]+right[i+1];
  }
  memset(dp,0,sizeof(bool)*N*N*N),memset(p,0,sizeof(bool)*N*N*N);
  dp[0][0]=1;
  //we keep chosing the left half of the pancake
  for (int i = 1; i <= n; ++i)
  {
    for(int j=0;j<=n*n;j++){
      if(left[i]<=j and dp[i-1][j-left[i]])
        p[i][j]=0,dp[i][j]=1;
      else if(right[i]<=j and dp[i-1][j-right[i]])
        p[i][j]=1,dp[i][j]=1;
    }
  }
  int index=0;
  for (int i = 1; i <= sum; ++i)
    if(dp[n][i] and abs(sum-2*i)<abs(sum-2*index))
      index=i;
  //backtracking
  for (int i = n; i>0; --i)
  {
    if(p[i][index])reverse(v[i-1].begin(), v[i-1].end()),index-=right[i];
    else index-=left[i];
  }
  for (int i = 0; i < n; ++i)
  {
    cout<<v[i]<<"\n";
  }
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)solve();
    cout<<"\n";
    return 0;
}