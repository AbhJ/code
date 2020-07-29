    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;
        ll n,m;cin>>n>>m;queue <ll> a,b;ll q;
        ll v1[n+10];
        for (ll i = 0; i <n; ++i)
            cin>>v1[i];
        sort(v1, v1+n);
        for (ll i = n-1; i !=-1; --i)
            a.push(v1[i]);ll i=0;ll x=1;
        while(m--){
            cin>>q;
            for (; i<q; ++i)
            {
                if(a.front()>=b.front()){
                    x=a.front();a.pop();
                }
                else {
                    x=b.front();b.pop();
                }
                if (x/2)
                    b.push(x/2);
            }
            cout<<x<<"\n";
        }
        return 0;   
    }