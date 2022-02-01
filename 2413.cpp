#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 1e6+6;
const int MOD = 1e9+7;
int t;
ll dp [MN] [2];
int main(){
    dp[1][0] = 1; dp[1][1] = 1;
    for(int i = 2; i < MN; i++){
        dp[i][0] = (dp[i-1][0] * 4 + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 2) % MOD; 
    }
    cin >> t;
    while(t--){
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    }
    return 0;
}