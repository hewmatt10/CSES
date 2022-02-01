#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 1e5+1;
const int MM = 1e2+1;
const int MOD = 1e9+7;
int n, m;
int arr[MN];
ll dp[MN][MM];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(arr[0] == 0){
        fill(dp[0], dp[0] + 101, 1);
    }
    else{
        dp[0][arr[0]] = 1;
    }
    for(int i = 1; i < n; i++){
        if(arr[i] == 0){
            for(int j = 1; j <= m; j++){
                dp[i][j] += dp[i-1][j];
                if(j - 1 > 0) dp[i][j] += dp[i-1][j-1];
                if(j + 1 <= m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
        else{
            dp[i][arr[i]] += dp[i-1][arr[i]];
            if(arr[i] - 1 > 0) dp[i][arr[i]] += dp[i-1][arr[i] - 1];
            if(arr[i] + 1 <= m) dp[i][arr[i]] += dp[i-1][arr[i] + 1];
            dp[i][arr[i]] %= MOD;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++) ans = (ans + dp[n-1][i]) % MOD;
    cout << ans << "\n";
    return 0;
}