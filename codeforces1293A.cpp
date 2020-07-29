    #include <bits/stdc++.h>
    #define ll long long int
    #define pb push_back
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    using namespace std;//coded by abhijay mitra
    #define N 100000 
    #define M 1000000007
    int main()
    {   
        ibs;cti;
        int t;cin>>t;
        while(t--){
            int n,s,k;cin>>n>>s>>k;std::vector<int> v(k);
            bool got=0;
            for (int i = 0; i < k; ++i){
                cin>>v[i];
            }
            sort(v.begin(), v.end());
            int i;bool flag=1;
            for (i = 0;flag and i<=k;++i)
            {
                if((s-i>=1 and !binary_search(v.begin(),v.end(),s-i))or(s+i<=n and !binary_search(v.begin(),v.end(),s+i)))
                {cout<<i<<"\n";flag=0;}
            }
        }
        return 0;
    }