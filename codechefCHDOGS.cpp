#include <bits/stdc++.h>
#define ll long long int
#define N 1000009
#define M 1000000007
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;
    int t;cin>>t;cout<<"\n";
    while(t--){
        long double s,v;cin>>s>>v;
        cout<<std::fixed<<std::setprecision(9)<<2*s/3/v<<std::showpoint<<"\n";
    }
    return 0;
}