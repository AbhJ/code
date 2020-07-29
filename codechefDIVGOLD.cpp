    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    #define N 200015
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;ll t,n;string s;cin>>t;
        while(t--){
            cin>>n>>s;
            string x=s;//=s;sort(x.begin(), x.end());bool y=1;int dude=-1
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    string test=s;test.erase(j,1);
                    test.insert(i,1,s[j]);x=min(x,test);
                }
            }
            cout<<x<<"\n";
        }
        return 0;   
    }