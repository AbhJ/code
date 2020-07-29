    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;int t;cin>>t;
        while(t--){
            int n;ll s;cin>>n>>s;
            std::vector<ll> v(n);ll store=0,index=0,x=INT_MIN;
            for (int i = 0; i < n; ++i)
                cin>>v[i];
            for (int i = 0; i < n; ++i)
            {
                if(v[i]>v[index])
                    index=i;//index stores biggest element's index
                store+=v[i];//we are storing sumulative sum till now
                if (store>s and store-v[index]<=s)//we can afford to remove it
                    x=index;
            }
            if(x!=INT_MIN)
                cout<<x+1<<"\n";
            else cout<<0<<"\n";
        }
        return 0;
    }