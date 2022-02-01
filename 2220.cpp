#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
string x, y;
ll dp [20][10][2];

ll solve(ll x){
    vector<int> v;
    while(x){
        v.push_back(x % 10);
        x /= 10;
    }
    int l = v.size() - 1;
    int fdig = v[l];
    for(int i = 0; i < fdig; i++) dp[l][i][0] = 1;
    dp[l][fdig][1] = 1;
    for(int i = l; i > 0; i++){
        
    }
    ll ans = 0;
    for(int i = 0; i <= 9; i++){
        ans += dp[0][i][0];
        ans += dp[0][i][1];
    }
    return ans;
}

int main(){
    cin >> a >> b; 
    cout << solve(b) - solve(a - 1) << "\n";
    return 0;
}