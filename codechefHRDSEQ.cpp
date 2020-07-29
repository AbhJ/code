#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        std::vector<int> v;v.pb(0);
        cout<<"\n\n\n";
        //create the vector
        for (int i = 1; i < 129; ++i)
        {
            int x=v.back(),k=0;
            for (int j = 0; j < v.size()-1; ++j)
            {
                if (v[j]==x)
                {
                    k=j+1;
                }
            }
            if (k)
            {
                v.pb(v.size()-k);
            }
            else
                v.pb(0);
            // cout<<v[i];
        }
        int count=0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i]==v[n-1])
            {
                count++;
            }
        }
        cout<<count<<"\n";
    
}
return 0;}