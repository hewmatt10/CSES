#include<bits/stdc++.h>
using namespace std;
const int MN = 1e3+3;
const int MM = 1e5+5;

int n, x, h[MN], s[MN], dp[MM];
bool vis[MM];
int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    vis[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = x; j >= 0; j--){
            if(j - h[i] >= 0){
                if(vis[j - h[i]]){
                    dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
                    vis[j] = true;
                }
            }
        }
    }
    int mx = 0;
    for(int i = 0; i <= x; i++){
        mx = max(mx, dp[i]);
    }
    cout << mx << "\n";
    return 0;
}