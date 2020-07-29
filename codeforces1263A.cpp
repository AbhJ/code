    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;int t;cin>>t;
        while(t--){
            int col[3];
            for (int i = 0; i < 3; ++i)
                cin>>col[i];
            sort(col,col+3);
            if (col[2]>col[0]+col[1])
                cout<<col[0]+col[1]<<"\n";
            else cout<<(col[0]+col[1]+col[2])/2<<"\n";
        }
        return 0;
    }
