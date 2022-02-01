#include<bits/stdc++.h>
using namespace std;
const int MN = 1e6+6;
const int MOD = 1e9+7;
int n, x;
int c [MN];
int cnt [MN];
bool vis[MN];
int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    cnt[0] = 1;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i + c[j] <= x){
                cnt[i + c[j]] = (cnt[i + c[j]] + cnt[i]) % MOD;
            }
        }
    }

    cout << cnt[x] % MOD << "\n";
    return 0;  
}