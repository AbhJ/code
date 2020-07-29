#include <bits/stdc++.h> 
using namespace std;
typedef vector<bool> vb;
int MAX = 5*(int)1e6;
int T, N;
int main(){
    std::vector<bool> ok(MAX+1);
    for(int m=2; m*m<MAX; ++m) 
        for(int n=1; n<m ; ++n) 
            if((m-n)&1){
                int c = m*m+n*n;
                if(c<=MAX && !ok[c]){
                    for(int i=c; i<=MAX; i+=c){
                        ok[i] = 1;
                    }
                }
            }
    cin>>T;
    while(T--){
        scanf("%d", &N);
        puts(ok[N]?"YES":"NO");
    }
}