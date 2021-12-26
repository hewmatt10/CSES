#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin >> n;
    ll mx = 0;
    ll cnt = 0;
    for(int i = 0;i<n;i++){
        ll a;
        cin >> a;
        mx = max(a,mx);
        cnt += mx - a;
    }
    cout <<  cnt << "\n";
 
    return 0;
}