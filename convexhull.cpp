#include <bits/stdc++.h>
// #define double long double
// #define int long long int
// #define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
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
const int N=5e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265,E=1e-9;
#define F first
#define S second
struct Point {
    int x, y, id;
};
Point operator - (Point a, Point b){
    return (Point){a.x - b.x, a.y - b.y, -1};
}
long long cross(Point a, Point b){
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}
long long cross(Point a, Point b, Point c){
    return cross(b - a, c - a);
}
//returns convex hull for set of points
vector<Point> convex_hull(vector<Point> points){
    sort(points.begin(), points.end(), [&](Point a, Point b){
        if(a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });
    vector<Point> upper, lower;
    for(int i = 0; i < (int)points.size(); i++){
        while(upper.size() >= 2 && cross(upper.end()[-2], upper.end()[-1], points[i]) > 0)
            upper.pop_back();
        upper.push_back(points[i]);
    }
    for(int i = (int)points.size() - 1; i >= 0; i--){
        while(lower.size() >= 2 && cross(lower.end()[-2], lower.end()[-1], points[i]) > 0)
            lower.pop_back();
        lower.push_back(points[i]);
    }
    if(lower.size() > 2) upper.insert(upper.end(), lower.begin() + 1, lower.end() - 1);
    return upper;
}
// 1 => Strictly inside; -1 => Border; 0 => Outside
int point_in_poly(const vector<Point> & poly, Point p){
    int many = 0;
    for(int i = 0; i < (int)poly.size(); i++){
        Point a = poly[i], b = poly[i + 1 < (int) poly.size() ? i + 1 : 0];
        if(a.x > b.x) swap(a, b);
        if(a.x <= p.x && p.x <= b.x){
            if(abs(a.x - b.x) == 0){
                if(min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y)) return -1;
            } else {
                double y = a.y + 1. * (b.y - a.y) / (b.x - a.x) * (p.x - a.x);
                if(abs(y - p.y) <= E) return -1;
                if(y >= p.y && p.x < b.x) many++;
            }
        }
    }
    return many % 2;
}
void solve(){
    int n,q;cin>>n>>q;vector<Point>a(n),A,B;
    vector<bool>ok(n,0);
    vector<vector<Point>>p;
    rep(i,0,n-1){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    // cout<<N-ok.count();
    while(accumulate(ok.begin(), ok.end(),0)<=n-3){
        A.clear();
        rep(i,0,n-1)if(ok[i]==0)A.pb(a[i]);
        B=convex_hull(A);
        for(auto i:B)ok[i.id]=1;
        p.pb(B);
    }
    rep(i,1,q){
        Point z;int cnt=0;
        cin>>z.x>>z.y;z.id=0;
        for(auto C:p)if(point_in_poly(C,z)==1)cnt++;
        cout<<"\n"<<cnt;
    }
}
int32_t main()
{
  // ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();}
  return 0;
}