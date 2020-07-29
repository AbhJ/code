#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 1000100
int main()
{
    ibs;cti;int n,t,y;cin>>t;
    while(t--){
        cin>>n;
        bool x=0;ll l=0,r=0;
        std::vector<ll> v(n);ll sum=0;
        for (int i = 0; i < n; ++i)
            cin>>v[i];
        for (int i = 0; i < n; ++i)
        {
            l+=v[i];r+=v[n-1-i];
            if(l<=0 or r<=0){x=1;break;}
        }
        if(x==1)cout<<"NO\n";else cout<<"YES\n";
    }
    return 0;
}