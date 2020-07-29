#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100010
int main()
{
    int t;cin>>t;
    while(t--){
        int len;cin>>len;
        string s;cin>>s;int maxa=0;
        for (int i = 0; i < len; ++i)
        {
            if(s[i]=='A'){
                int n=0;
                while(s[i+1]=='P')
                    i++,n++;
                maxa=max(n,maxa);
            }
        }
        cout<<maxa<<"\n";
    }
    return 0;   
}