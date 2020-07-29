#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n;bool a[N][N];
void f(int A,int B){
    for (int i = 1; i <= n; ++i)
        {
            // for (int j = 1; j <= n; ++j)
            // {
                if(i<=n-A+1)a[i][i-1]=a[i-1][i]=1;
            // }
        }
}
void solve(){
    int A,b;
    cin>>n>>A>>b;
    if(min(A,b)>1){cout<<"NO";return;}
    if(n==2 and A==1 and b==1){cout<<"NO";return;}
    if(n==3 and A==1 and b==1){cout<<"NO";return;}
    if(A<b){
        f(b,A);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
               if(i^j) a[i][j]=a[i][j]^1;
            }
        }
    }
    else f(A,b);
    cout<<"YES\n";
    for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cout<<a[i][j];
            }
            cout<<"\n";
        }
}
int32_t main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}