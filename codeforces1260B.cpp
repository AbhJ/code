#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
#define N 400015
struct table{
    int val,id;
};
bool cmp(table a,table b)
{
    return a.val>b.val;
}
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;ll a,b;int t;cin>>t;
    while(t--){
        cin>>a>>b;
        if(a<b)swap(a,b);
        if((a+b)%3==0 and a<=2*b)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;   
}