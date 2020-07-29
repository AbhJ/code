        #include <bits/stdc++.h>
        #define ll long long int
        #define pb push_back
        #define ibs ios_base::sync_with_stdio(false)
        #define cti cin.tie(0)
        using namespace std;//coded by abhijay mitra
        #define watch(x) cout << (#x) << " is " << (x) << endl
        int main()
        {
            ibs;cti;int T;cin>>T;
            while(T--){
                    int h,m;cin>>h>>m;
                    ll time=m+h*60;
                    cout<<1440-time<<"\n";
            }return 0;
        }