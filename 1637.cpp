#include<bits/stdc++.h>
using namespace std;
const int MN = 1e6+6;
int n, dp[MN];
bool vis[MN];

int main(){
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    cin >> n;
    dp[n] = 0;
    vis[n] = true;
    for(int i = n; i >= 0; i--){
        if(vis[i]){
            int temp = i;
            set<int> dig;
            while(temp > 0){
                dig.insert(temp % 10);
                temp /= 10;
            }
            for(int d : dig){
                if(i - d >= 0){
                    dp[i - d] = min(dp[i - d], dp[i] + 1);
                    vis[i - d] = true;
                }
            }
        }
    }
    cout << dp[0] << "\n";
    return 0;
}