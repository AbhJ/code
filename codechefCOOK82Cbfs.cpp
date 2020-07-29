    #include <bits/stdc++.h>
    #define ll long long
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
    int main()
    {
        ibs;cti;
        ll n,m;cin>>n>>m;priority_queue <unsigned ll> a;unsigned ll q;
        for (int i = 0; i <n; ++i){
            cin>>q;a.push(q);
        }
        std::vector<unsigned ll> v;unsigned ll x=1;
        for (int i = 0; x>0; ++i)
        {
            x=a.top();a.pop();a.push(x/2);
            v.pb(x);
        }
        while(m--){
            cin>>q;if(q<v.size())cout<<v[q-1]<<"\n";
            else cout<<0<<"\n";
        }
        return 0;   
    }