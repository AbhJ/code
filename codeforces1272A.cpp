    #include <bits/stdc++.h>
    #define ll long long
    #define N 100009
    #define M 1000000007
    #define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
    #define po pop_back
    #define pb push_back
    #define lb lower_bound
    #define ub upper_bound
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define cot cout.tie(0)
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;
        int t;cin>>t;ll a,b,c,a1,b1,c1;
        while(t--){
            cin>>a>>b>>c;
            c1=max(a,max(b,c));
            a1=min(a,min(b,c));
            b1=a+b+c-a1-c1;
            a=a1;b=b1;c=c1;
            a++;c--;
            if(c-b+c-a+b-a>0)cout<<c-b+c-a+b-a<<"\n";
            else cout<<0<<"\n";
        }
        return 0;   
    }