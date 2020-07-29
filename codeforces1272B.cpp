    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    #define N 100000
    using namespace std;//coded by abhijay mitra
    ll c[N];
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;
        int t;cin>>t;string s;ll sum=0;
        while(t--){
            cin>>s;ll n=s.length();
            ll u,d,l,r;
            u=count(s.begin(), s.end(),'U');
            d=count(s.begin(), s.end(),'D');
            l=count(s.begin(), s.end(),'L');
            r=count(s.begin(), s.end(),'R');
            if(min(l,r)==0 and min(u,d)==0) {cout<<"0\n";continue;}
            if(min(l,r)==0){cout<<2<<"\nUD\n";continue;}
            if(min(u,d)==0){cout<<2<<"\nLR\n";continue;}
            cout<<min(l,r)*2+min(u,d)*2<<"\n";
            for (int i = 0; i < min(l,r); ++i)
                cout<<"R";
            for (int i = 0; i < min(u,d); ++i)
                cout<<"U";
            for (int i = 0; i < min(l,r); ++i)
                cout<<"L";
            for (int i = 0; i < min(u,d); ++i)
                cout<<"D";
            cout<<"\n";
        }
        return 0;   
    }