#include<bits/stdc++.h>
using namespace std;
const int MN = 5e3+3;
string a, b;
int dp[MN][MN];
int main(){
    cin >> a >> b;
    memset(dp, 0x3f3f3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i <= a.length(); i++){
        for(int j = 0; j <= b.length(); j++){
            if(i > 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            }
            if(j > 0){
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if(i > 0 && j > 0){
                int n = dp[i-1][j-1] + (a[i-1] != b[j-1]);
                dp[i][j] = min(dp[i][j], n);
            }
        }
    }
    cout << dp[a.length()][b.length()] << "\n";
    return 0;
}