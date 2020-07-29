    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    #define N 400015
    ll y=0;
    struct table{
        int val,id;
    };
    bool cmp(table a,table b)
    {
        return a.val>b.val;
    }
    bool isPrime(ll n) 
    { 
        // Corner case 
        if (n <= 1) 
            return false; 
      
        // Check from 2 to n-1 
        for (ll i = 2; i < n; i++) 
            if (n % i == 0) 
                return false; 
      
        return true; 
    } 
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;
        int n;ll m;cin>>n>>m;std::vector<ll> a(m,0),b(m,0);bool Check=0;ll x;
        for (int i = 0; i < n; ++i){
            cin>>x;a[x]++;
        }
        for (int i = 0; i < n; ++i){
            cin>>x;b[x]++;
        }
        if(m==2){
            if(a[0]==b[1] and a[1] ==b[0]){
                cout<<"1\n";return 0;
            }
        }
        if(n==1){
            if(b[0]==a[0])
                cout<<0<<"\n";
            return 0;
        }
        for (ll i = 0;; ++i){
            if(a==b){cout<<i<<"\n";return 0;}
            std::rotate(b.begin(), b.begin()+1, b.end());
        }
    }