#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int Q;
ll power [19];
int main(){
    power[0] = 1;
    for(int i = 1;i<19;i++){
        power[i] = power[i-1] * 10;
    }
    cin >> Q;
    while (Q--){
        ll k;
        cin >> k;
        ll cur = 0;
        ll block = 0;
        int dig;
        for(int i = 1;i<19;i++){
            cur += i*(power[i] - power[i-1]);
            if(cur >= k){
                dig = i;
                break;
            }
            block += i*(power[i] - power[i-1]);
        }
        ll l = power[dig-1];
        ll r = power[dig]-1;
        ll v = 0;
        ll pos;
        while(l <= r){
            ll mid = l + (r - l)/2;
            ll act = block + 1 + (mid - power[dig-1])*dig;

            if(act <= k){
                if(mid > v){
                    v = mid;
                    pos = act;
                }
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        string num = to_string(v);
        cout << num[k-pos] << "\n";
    }
    return 0;
}