#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
#define N 200015
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
    ibs;cti;int n,t;cin>>t;string s;bool y=0;
    while(t--){
        cin>>s;n=s.length();y=0;
        for(int i=0;i<n;i++){
            if((i>0 and s[i]==s[i-1]) or (s[i-1]==s[i-2] and i>1)) {cout<<"-1\n";y=1;break;
            }
            if(s[i]=='?'){
                for (char i1 = 'a'; i1 < 'd'; ++i1)
                    if(s[i-1]!=i1 and s[i+1]!=i1)
                        s[i]=i1;
            }
        }
        if(!y) cout<<s<<"\n";
    }
    return 0;   
}