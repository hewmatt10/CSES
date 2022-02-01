#include<bits/stdc++.h>
using namespace std;
const int MN = 1e2+2;
const int MM = 1e3+3;
const int MOD = 1e9+7;

int n, m;
long long dp[MN][MM];

int main(){
    cin >> n >> m;
    for(int i = 0; i < MN; i++){
        dp[i][0] = 1;
        if(i % 2 == 0){
            dp[i][1] = 1;
        }
    } 
    for(int i = 0; i < MM; i++){
        dp[0][i] = 1;
        if(i % 2 == 0){
            dp[1][i] = 1;
        }
    } 
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            // x splits i, y splits j
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[n][m] << "\n";
    return 0;
}