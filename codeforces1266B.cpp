#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
        ll x; cin>>x;
        if (x>15) {x%=14;x+=14;}
        if(x>14 and x<21) cout<<"YES\n";else cout<<"NO\n";
    }
    return 0;   
}