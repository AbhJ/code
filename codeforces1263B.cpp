    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;int t;cin>>t;int i,j;
        while(t--){
            int n;cin>>n;std::vector<string> v(n);std::vector<bool> used(10);
            for (int i = 0; i < n; ++i){
                cin>>v[i];used[v[i][3]-'0']=1;
            }
            ll sum=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<i;j++)
                    if(v[i]==v[j])break;
                if(j!=i)
                {
                    sum++;
                    for(j=0;j<10;j++)
                        if(!used[j])v[i][3]=j+'0';
                }
                used[v[i][3]-'0']=1;
            }
            cout<<sum<<'\n';
            for(auto x:v)
                cout<<x<<'\n';
        }
        return 0;
    }