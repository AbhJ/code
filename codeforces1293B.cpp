#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define N 100010
bool a[N];
int main()
{   
    ibs;cti;
    long double n;cin>>n;
    long double ans=0;
    for (long double i = 1; i <= n; ++i)
    {
        ans+=(long double)1/i;
    }
    cout<<ans<<"\n";
    return 0;
}