#include<bits/stdc++.h>
using namespace std;
int n, x;
int a[20];
pair<int,int> dp [1 << 20];
int main(){
    cin >> n >> x;
    for(int i = 0; i < n ; i++) cin >> a[i];
    dp[0] = {1,0};
    for(int mask = 1; mask < (1 << n); mask++){
        dp[mask] = {n + 1, 0};
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                auto best = dp[mask ^ (1 << i)];
                if(dp[mask ^ (1 << i)].second + a[i] <= x){
                    best.second += a[i];
                }
                else{
                    best.first++;
                    best.second = a[i];
                }
                dp[mask] = min(dp[mask], best);
            }
        }
    }
    cout << dp[(1 << n) - 1].first << "\n";
    return 0;
}