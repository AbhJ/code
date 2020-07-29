    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    // #define N 200015
    // #define M 101
    using namespace std;//coded by abhijay mitra
    // int a[M][2];
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;
        ll t,n;cin>>t;string s;
        while(t--){
            cin>>r>>b>>k;ll x=__gcd(r,b);
            r/=x;
            b/=x;
            if(r>b)
                swap(r,b);
            if((b-1)<=(k-1)*r)cout<< "OBEY\n";
            else cout<<"REBEL\n";
        }
        return 0;   
    }