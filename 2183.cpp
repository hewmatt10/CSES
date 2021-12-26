#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n;
int arr [MN];
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    long long ans = 1;
    for(int i = 0;i<n && arr[i] <= ans;i++){
        ans += arr[i];
    }
    cout << ans << "\n";
    return 0;
}