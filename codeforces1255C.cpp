#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
const int N = 1e5 + 10;
int cnt[N];
bool vis[N];
int main()
{   
    ibs;cti;
    vector<int> v[N];
    int n,x,y,z;cin>>n;
    for(int i = 1; i <= n - 2; i++){
        cin>>x>>y>>z;
        v[x].push_back(y), v[x].push_back(z);
        v[y].push_back(x), v[y].push_back(z);
        v[z].push_back(x), v[z].push_back(y);
        cnt[x]++, cnt[y]++, cnt[z]++;
    }
    for(int i = 1; i <= n; i++) if(cnt[i] == 1) {x = i;break;}
    if(cnt[v[x][0]] == 2) y = v[x][0];
    else y = v[x][1];
    cout<<x<<" "<<y<<" ";
    vis[x] = vis[y] = 1;
    for(int i = 1; i <= n - 2; i++){
        for(int j = 0; j < v[x].size(); j++){
            if(!vis[v[x][j]]) {z = v[x][j];break;}
        }
        cout<<z<<" ";
        vis[z] = 1;
        x = y;
        y = z;
    }
    return 0;
}