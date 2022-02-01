#include<bits/stdc++.h>
using namespace std;
const int MN = 5e2+5;
int a, b;
int dp[MN][MN];
int main(){
    cin >> a >> b;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j)continue;
            int best = INT_MAX;
            for(int x = 1; x < j; x++){
                best = min(best, dp[i][x] + dp[i][j - x]);
            }
            for(int y = 1; y < i; y++){
                best = min(best, dp[y][j] + dp[i - y][j]);
            }
            dp[i][j] = best + 1;
        }
    }
    cout << dp[a][b] << "\n";
    return 0;
}