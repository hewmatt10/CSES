#include<bits/stdc++.h>
using namespace std;
const int MN = 1e3+3;
const int MOD = 1e9+7;
int n;
bool grid[MN][MN];
int dp[MN][MN];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '.')grid[i][j+1] = true;
            else grid[i][j+1] = false;
        }
    }
    if(grid[1][1])dp[1][1] = 1;
    else dp[1][1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j && j == 1)continue;
            if(grid[i][j]){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << dp[n][n] % MOD << "\n";
    return 0;
}