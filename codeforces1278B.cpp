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
        int t;cin>>t;ll a,b,i;
        while(t--){
            cin>>a>>b;i=1;if(a==b){cout<<"0\n";continue;}
            while(1){
                if((i*(i+1)/2)>= abs(a-b) and ((i*(i+1)/2)- abs(a-b))%2==0)
                    break;
                i++;
            }
            cout<<i<<"\n";
        }
    }