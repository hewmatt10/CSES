#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
typedef long long ll;
int n;
ll x, arr [MN], psa[MN];
int main(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        psa[i] = psa[i-1] + arr[i];
    }
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        if(psa[i] - x >= 0){
            int j = lower_bound(psa, psa + n + 1, psa[i] - x) - psa;
            if(psa[i] - psa[j] == x){
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;  
}