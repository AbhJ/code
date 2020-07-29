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
        ibs;cti;ll n;cin>>n;int cf[25][n];
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin>>v[i];
        for (int i = 0; i < 25; ++i)
            for (int j = 0; j < n; ++j)
                cf[i][j]=0;
         int p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97} ;
         for (int i = 0; i < 25; ++i)
         {
             for (int j = 0; j < n; ++j)
             {
                 if(j) cf[i][j]=cf[i][j-1];
                 int num=v[j];
                 while(num%p[i]==0){
                    cf[i][j]++;
                    num/=p[i];//to store cumulative frequency of p[i]
                 }
             }
         }
        int t;cin>>t;int l,r;ll m;
        while(t--){
            cin>>l>>r>>m;l--;r--;
            ll ans=1;
            for (int i = 0; i < 25; ++i){
                if(l)
                ans*=pow(p[i],cf[i][r]-cf[i][l-1]);
                else ans*=pow(p[i],cf[i][r]);
                ans%=m;
            }
            cout<<ans%m<<"\n";
        }
        return 0;
    }