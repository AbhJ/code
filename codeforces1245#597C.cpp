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
        string s;cin>>s;int f[s.length()+1];f[0]=f[1]=1;
        for (int i = 0; i < 2; ++i)
        {
            if(s[i]=='m' or s[i]=='w'){
                cout<<0<<"\n";return 0;
            }
        }
        for (int i = 2; i < s.length()+1; ++i)
        {
            if(s[i-1]=='m' or s[i-1]=='w'){
                cout<<0<<"\n";return 0;
            }
            if(s[i-1]==s[i-2] and (s[i-1]=='n' or s[i-1]=='u'))
                f[i]=(f[i-1]+f[i-2])%M;
            else f[i]=f[i-1];
        }
        cout<<f[s.length()]<<"\n";
    return 0;
}