#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n;
int arr[MN];
int main(){
    cin >> n;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        int x;
        cin >> x;
        arr[x] = i;
    }
    ans++;
    for(int i = 2;i<=n;i++){
        ans += (arr[i] < arr[i-1]);
    }
    cout << ans << "\n";
    return 0;
}