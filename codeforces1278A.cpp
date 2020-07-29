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
        int t;cin>>t;
        while(t--){
            string s,h;cin>>s>>h;std::vector<string> v;bool y=0;
            sort(s.begin(), s.end());ll length=s.length();
            while(1){
                for (ll i = 0; i < h.length(); i++)
                    {string x=h.substr(i, length);sort(x.begin(), x.end());v.pb(x);}       
                for (int i = 0; i < v.size(); ++i)
                    if(s==v[i]){
                        cout<<"YES\n";y=1;break;
                    }
                if (y==0)
                {
                    cout<<"NO\n";y=1;
                }
                if(y==1)break;
            }
        }
    }