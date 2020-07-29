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
        int n;cin>>n;std::vector<pair<int,int>> v(n+1);v[0]={0,0};
        for (int i = 1; i <= n; ++i)
        {
            cin>>v[i].first>>v[i].second;
        }
        sort(v.begin(), v.end());/*sort(v.begin(), v.end(),cmp);*/string s="";bool c=0;
        for (int i = 0; i < v.size()-1; ++i)
        {
                if (v[i+1].second<v[i].second){
                    c=1;break;
                }
            if (v[i+1].first<v[i].first){
                    c=1;break;
                }
             for (int j = 0; j < v[i+1].first-v[i].first; ++j)
                {
                    s+="R";
                }
             for (int j = 0; j < v[i+1].second-v[i].second; ++j)
                {
                    s+="U";
                }
        }
        if(c){
            cout<<"NO\n";continue;
        }
        cout<<"YES\n";
        cout<<s<<"\n";
    }
    return 0;
}