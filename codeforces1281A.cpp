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
            cin>>s;n=s.length();
            if(n>1)
            if(s.substr(n-2,2)=="po")
                cout<<"FILIPINO";
            if(n>3)
            if(s.substr(n-4,4)=="desu" or s.substr(n-4,4)=="masu")
                cout<<"JAPANESE";
            if(n>4)
            if(s.substr(n-5,5)=="mnida")
                cout<<"KOREAN";
            cout<<"\n";
        }
        return 0;   
    }