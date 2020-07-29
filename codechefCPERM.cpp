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
int power(int k) {
  //used to calculate pow(2,n) fast
    if (k == 0)
        return 1;
    if (k == 1)
        return 2;
    if (k % 2 == 1)
        return power(k - 1) * 2LL % M;
    int q = power(k / 2);
    return q * 1LL * q % M;
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
void solve(){
 int n;cin>>n;
 if(n!=1)cout<<power(n-1)%M-2<<"\n";
 else cout<<0<<"\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)solve();
    cout<<"\n";
    return 0;
}