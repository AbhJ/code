    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    using namespace std;//coded by abhijay mitra
    int main(){
        ibs;cti;int t;cin>>t;
        while(t--){
            int n,m;cin>>n>>m;
            std::vector<ll> a(n+1,0),b(n+1,0),o(n+1,0);
            for (int i = 0; i < n; ++i){
                cin>>a[i];o[a[i]]=i;
            }
            for (int i = 0; i < m; ++i) cin>>b[i];
            int pos=INT_MIN,pos_max=INT_MIN;ll x=0;
            for (int i = 0; i < m; ++i){
                pos=o[b[i]];
                if(pos>pos_max){//then i-1 elements have been alredy removed
                    pos_max=pos;
                    x+=2*(pos-i)+1;
                }else x++;
            }
            cout<<x<<"\n";
        }
        return 0;
    }