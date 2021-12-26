#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int arr[13];
int main(){
    ll n;
    cin >> n;
    arr[0] = 1;
    for(int i = 1;i<13;i++){
        arr[i] = arr[i-1]*5;
    }
    int ans = 0;
    for(int i = 1;i<13;i++){
        ans += n/arr[i];
    }
    cout << ans;
    return 0;
}