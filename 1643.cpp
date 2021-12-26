#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n;
long long arr[MN];
int main(){
    cin >> n;
    long long cur = 0, ans = LONG_LONG_MIN;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        cur = max(arr[i], cur + arr[i]);
        if(cur > ans){
            ans = cur;
        }
    }
    cout << ans << "\n";
    
    return 0;
}