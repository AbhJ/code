    //Coded by Abhijay Mitra
    #include <iostream>
    #include <stdlib.h>
    #include <algorithm>
    #include <cstdio>
    #include <numeric>
    #include <cstring>
    #include <numeric>
    #include <vector>
    #include <iterator> 
    #include <map>
    #include <set>
    #include <climits>
    #include <queue>
    #include <cmath>
    #include <stack>
    #include <cctype>
    #include <bitset>
    using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// #include <bits/stdc++.h>
    #define double long double
    #define int long long int
    #define ll int
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define bp __builtin_popcount
    #define pb push_back
    #define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
    #define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
    #define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
    #define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    using vi = std::vector<int>;
    using vvi = std::vector<vi>;
    using pii = std::pair<int,int>;
    using vpii = std::vector<pii>;
    using vvpii = std::vector<vpii>;
    #define mp         make_pair
    #define rep(i,a,b) for (int i = a; i <= b; i++)
    #define per(i,b,a) for (int i = b; i >= a; i--)
    #define all(x)     x.begin(), x.end()
    using namespace std;
    const int N=2e6+10;
    const int inf = /*0x3f3f3f3f*/1e18+10;
    // const ll M = 998244353 ; // Mulo
    const int M = 1e9+7 ; // Mulo
    const double Pi = 3.14159265;
    #define F first
    #define S second
    int a[N],q,t;ordered_set<int> s;
    void solve(){
      int n,x;cin>>n>>x;
      rep(i,1,n){cin>>a[i];if(a[i]==x)s.insert(i);}
      cin>>q;
      rep(i,1,q){
        cin>>t;
        if(t==1){
          int l,r,k;
          cin>>l>>r>>k;
          int num=((s.order_of_key(l)))+k-1;
          if(num>=s.size()){cout<<-1<<"\n";goto F;}
          if(*s.find_by_order(num)>r){cout<<-1<<"\n";goto F;}
          cout<<*s.find_by_order(num)<<"\n";
        }
        F:;
        if(t==2){
          int i,v;cin>>i>>v;
          if(a[i]==x)s.erase(s.find(i));
          if(v==x)s.insert(i);
          a[i]=x;
        }
      }
    }
    int32_t main()
    {
      ibs;cti;
      solve()
      /*,cout<<"\n"*/;
      // cout<<"\n";
      int xx=0;
      // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
      return 0;
    }