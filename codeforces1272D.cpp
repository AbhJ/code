    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    #define N 200015
    using namespace std;//coded by abhijay mitra
    ll a[N],b[N];
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;
        ll n=0;cin>>n;std::vector<ll> v(n);
        bool x=0;
        a[0]=1;b[n-1]=1;
        // for(int i=0;i<N;i++){
        //     a[i]=1;b[i]=1;
        // }
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(i){
                if(v[i]>v[i-1])
                    a[i]=a[i-1]+1;
                else {a[i]=1;x=1;}
            }
        }
        for (int i = n-2; i >-1; --i)
        {
            if(v[i]<v[i+1])
                b[i]=b[i+1]+1;
            else {b[i]=1;x=1;}
        }
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<"\t";
        // }cout<<"\n";
        // for(int i=0;i<n;i++){
        //     cout<<b[i]<<"\t";
        // }
        // cout<<x;
        ll m=0;
        for (int i = 0; i < n; ++i)
                m=max(m,a[i]);
        if(x){for (int i = 1; i < n-1; ++i)
                if(v[i+1]>v[i-1] and (v[i]>=v[i+1] or v[i-1]>=v[i]))
                    m=max(m,a[i-1]+b[i+1]);
             }
        // else
        //     for (int i = 0; i < n; ++i)
        //         m=max(m,a[i]);
        cout<<m<<"\n";
        return 0;   
    }