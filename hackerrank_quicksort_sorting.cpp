#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
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
int v[N];
int partition(int v[],int l, int r){
      int x=v[r];int i=l;
      for (int j = l; j < r; ++j)
      {
        if(v[j]<=x)swap(v[i],v[j]),i++;
      }
      swap(v[i],v[r]);
      return i;
}
void quicksort(int v[],int l,int r){
  if(l>=r)return;
  int pivot=partition(v,l,r);
  quicksort(v,l,pivot-1);
  for (int i = l; i <= r; ++i)cout<<v[i]<<" ";
  quicksort(v,pivot+1,r);
  cout<<"\n";
}
void solve(){
      int n;cin>>n;
      for (int i = 0; i < n; ++i)cin>>v[i];
      quicksort(v,0,n-1);
}
int main()
{   
    ibs;cti;
    solve();
    return 0;
}