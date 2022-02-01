#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 2e5+5;
int n, k;
ll a[MN];
int main(){
    cin >> n >> k;
    ll l = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        l = max(l, a[i]);
    }
    ll r = (ll)1e18;
    while(l < r){
        ll mid = (l + r)/2;
        int c = 0;
        ll ls = 0;
        for(int i = 0; i < n; i++){
            if(ls + a[i] > mid){
                ls = 0;
                c++;
            }
            ls += a[i];
        }
        c++;
        if(c > k){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    cout << l << "\n";
    return 0;
}