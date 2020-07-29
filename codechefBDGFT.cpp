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
            cin>>s; ll n=s.length();sum=0;
            for (int i = 1; i < n+1; ++i)
                c[i]=c[i-1]+s[i-1]-'0';
            for (int i = 0; i < n; ++i)
            {
                int x=1;int j,count;
                while(1){
                    j=i+x*x+x;
                    if(j>n)break;
                    count=c[j]-c[i];if(count==x)
                    sum++;
                    x++;
                }
            }
            cout<<sum<<"\n";
        }
        return 0;   
    }