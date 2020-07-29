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
        ibs;cti;ll t;cin>>t;
        while(t--){
            int n;cin>>n;std::vector<ll> v(n);int wrong=0;
            for(int i=0;i<n;i++){
                cin>>v[i];if(i<2 or wrong) continue;
                if(v[i]<v[i-1] and v[i]<v[i-2]){
                    wrong++;
                }
            }
            if(wrong==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
        return 0;   
    }