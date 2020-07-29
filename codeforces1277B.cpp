#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
priority_queue<int>q;
int main()
{
    ibs;cti;int t;cin>>t;
    while(t--){
      int n;cin>>n;int x;
      for (int i = 0; i < n; ++i){
        cin>>x;if(x%2==0)q.push(x);
      }
      int ans=0;
      while(q.size()){
        int t=q.top(),count=1;
        q.pop();
        while(q.size() and q.top()==t)count++,q.pop();
        ans++;
        if((t/2)%2==0)while(count--)q.push(t/2);
      }
      cout<<ans<<"\n";
    }
    return 0;   
}