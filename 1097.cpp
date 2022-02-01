#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN =5e3+3;
int n;
int a[MN];
ll sum, dp[MN][MN];


int main(){
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        sum += a[i];
        dp[i][i] = a[i];
    }
    for(int i = 2;i <= n; i++){
        for(int j = 1; j + i - 1 <= n; j++){
            int l = j;
            int r = j + i - 1;
            dp[l][r] = max(a[r] - dp[l][r-1], a[l] - dp[l+1][r]); 
        }
    }
    
    cout << dp[1][n] + (sum - dp[1][n]) / 2 << "\n";
    return 0;
}