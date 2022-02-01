#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
typedef long long ll;
const ll MOD = 1e9+7;
int n;
ll dp[MN];


int main(){
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        ll temp[MN];
        for(int j = 0; j < MN; j++) temp[j] = 0;
        for(int j = 0; j < MN; j++){
            if(abs(j - i) < MN){
                temp[abs(j - i)] += dp[j];
                temp[abs(j - i)] %= MOD;
            }
            if(abs(j + i) < MN){                
                temp[abs(j + i)] += dp[j];
                temp[abs(j + i)] %= MOD;
            }
        }
        for(int j = 0; j < MN; j++) dp[j] = temp[j] % MOD;
    }   
    if(dp[0] % 2 == 0){
        cout << dp[0]/2 << "\n";
    }
    else{
        cout << (dp[0] + MOD)/2 << "\n";
    }

    return 0;
}