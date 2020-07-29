    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;int t;cin>>t;std::vector<int> v(3);
        while(t--){
            for (int i = 0; i < 3; ++i)
                cin>>v[i];
            sort(v.begin(), v.end());
            if(v[2]>v[1]+v[0]+1) cout <<"NO\n";
            else cout<<"YES\n";
        }
        return 0;
    }