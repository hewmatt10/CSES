#include<bits/stdc++.h>
using namespace std;
const int MN = 1e6+6;
const int MOD = 1e9+7;
int n, x;
int c[MN];
int dp[MN];
bool vis[MN];
int main(){
    vis[0] = 1;
    dp[0] = 1;
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            if(j + c[i] <= x && vis[j]){
                dp[j + c[i]] = (dp[j + c[i]] + dp[j]) % MOD;
                vis[j + c[i]] = true;
            }  
        }
    }
    cout << dp[x] % MOD << "\n";
    return 0;
}