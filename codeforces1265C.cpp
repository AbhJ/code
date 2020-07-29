#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
#define N 400015
struct table{
    int val,id;
}a[N];
bool cmp(table a,table b)
{
    return a.val>b.val;
}
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;int n,t;cin>>t;
    while(t--){
        cin>>n;int g=1,s=0,b=0;std::vector<int> p(n);
        for (int i = 0; i < n; ++i){
            cin>>p[i];
        }
        while(g<n/2 and p[g]==p[g-1])
            g++;
        s+=2*g+1;
        while(s<n/2 and p[s]==p[s-1] and g<s-g)
            s++;
        b=n/2;
        while(p[b]==p[b-1] and g<b-s)
            b--;
        if(g>=b-s or g>=s-g or b>n/2) cout<<"0 0 0\n";else
        cout<<g<<" "<<s-g<<" "<<b-s<<"\n";
    }
    return 0;   
}