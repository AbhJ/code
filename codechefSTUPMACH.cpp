#include <bits/stdc++.h>
    #define ll long long int
    #define N 100009
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
    ll solve(std::vector<ll> v,ll n){
        ll mina=INT_MAX,ind=0;
        if(n==0)return 0;
        for (ll i = 0; i < n; ++i){
            if(v[i]<=mina) ind=i;
            mina=min(mina,v[i]);
            }
        for (ll i = 0; i <= ind; ++i)
        {
            v[i]-=mina;
            // cout<<v[i]<<" ";
        }
        // cout<<ind<<"\n";
        return mina*n+solve(v,ind);
    }
    int main()
    {
        ibs;cti;ll t;cin>>t;
        while(t--){
            ll n;cin>>n;std::vector<ll> v(n);
            for (ll i = 0; i < n; ++i){
                cin>>v[i];/*mina=min(mina,v[i]);*/
            }
            cout<<solve(v,n)<<"\n";
        }
        return 0;   
    }