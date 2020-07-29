#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 1000100
#define M 1000000007
int main()
{
    ibs;cti;ll n,m;cin>>n>>m;ll f[N];f[0]=1;
    for (int i = 1; i <=n; ++i)
        f[i]=f[i-1]*i%m,f[i]%=m;
    ll sum=0;
    for (int i = 1; i <=n; ++i)
    {
        sum+=(n-i+1)*(f[i]*f[n-i+1]%m);sum%=m;
    }
    cout<<sum<<"\n";
    return 0;
}