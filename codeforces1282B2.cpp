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
            int n;ll p;int k;
            cin>>n>>p>>k;std::vector<int> v(n);
            for (int i = 0; i < n; ++i)
                cin>>v[i];
            sort(v.begin(), v.end());int cost=0;int total=0;int ans=INT_MIN;
            for (int i = 0; i < k; ++i)
            {
                int total=cost;
                if(total>p) break;
                int x=i;
                for (int j = i+k-1; j < n; j+=k)//going for the next set
                {
                    if (total+v[j]>p) break;
                    x+=k;total+=v[j];
                }
                cost+=v[i];//if first i elements can also be bought
                ans=max(ans,x);
            }
            cout<<ans<<"\n";
        }
        return 0;
    }