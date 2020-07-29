    #include <bits/stdc++.h>
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;int n;cin>>n;std::vector<int> v;bool check=0;
        string s;cin>>s;
        for (int i = 0; i < n; ++i)
            if(s[i]=='B'){check=1;break;}
        for (int i = 0; i < n-1; ++i)
        {
            if(s[i]=='W'){
                s[i]='B';
                if(s[i+1]=='W') s[i+1]='B';
                else s[i+1]='W';
                v.pb(i+1);
            }
        }
        if(s[n-1]=='W' and !(n%2) ){
            cout<<-1<<"\n";return 0;
        }
        if(!check){cout<<0<<"\n";return 0;}
        if(s[n-1]=='W'){
            for(int i=1;i<n;i+=2)
                v.pb(i);//every odd number to get all white as for WBBBB
        }
        cout<<v.size()<<"\n";
        for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
            cout<<*i<<" ";
        cout<<"\n";
        return 0;
    }