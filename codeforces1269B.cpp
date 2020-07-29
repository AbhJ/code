    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    main()
    {
        ibs;cti;int n;ll m;cin>>n>>m;std::vector<ll> a,b,v;ll x;
        for (int i = 0; i < n; ++i)
        {cin>>x;a.pb(x);}
        for (int i = 0; i < n; ++i)
        {cin>>x;b.pb(x);}
        sort(b.begin(), b.end());sort(a.begin(), a.end());ll ans=m;
        for (int i = 0; i < n; ++i){
            v.clear();x=(b[i]-a[0]+m)%m;
            for (int j = 0; j < n; ++j)v.pb((x+a[j])%m);
            sort(v.begin(), v.end());if(v==b)ans=min(ans,x);
        }
        cout<<ans<<"\n";
    }