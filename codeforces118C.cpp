#include <bits/stdc++.h>
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;string best;int cheap;
    for(char i='0';i<='9';i++){
        string s1=s;int cost=0;
        std::vector<pair<int,int>> v;//cost of that letter, position
        for (int j = 0; j < n; ++j)
            v.pb({abs(s[j]-i),i<=s[j]?j-n:n-j});
        sort(v.begin(), v.end());
        for(int j=0;j<k;j++){
            cost+=v[j].first;
            s1[n-abs(v[j].second)]=i;
        }
        if(i=='0')best=s1,cheap=cost;
        else if(((s1<best) and (cheap>=cost)) or (cheap>cost))cheap=cost,best=s1;
    }
    cout<<cheap<<"\n"<<best<<"\n";
}
int main()
{   
    ibs;cti;
    solve();
    return 0;
}