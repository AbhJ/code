#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 1000100
ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}
int main()
{
    ibs;cti;ll x,y,z;
    cin>>x;
    for (int i = 1; i <= sqrt(x); ++i)
    {
        if(x%i==0 and lcm(i,x/i)==x)y=i;
    }
    cout<<y<<" "<<x/y<<"\n";
    return 0;
}