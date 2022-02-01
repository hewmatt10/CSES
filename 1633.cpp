#include<bits/stdc++.h>
using namespace std;
const int MN = 1e6+6;
const int MOD = 1e9+7;
int n;
int dp[MN];
int main(){
    cin >> n;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 6 && i + j <= n; j++){
            dp[i + j] = (dp[i + j] + dp[i]) % MOD;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}