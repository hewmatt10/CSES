#include<bits/stdc++.h>
using namespace std;
const int MN = 101;
int n;
int arr[MN];
int dp[100001];
bool vis[100001];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vis[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 100000; j > 0; j--){
            if(j - arr[i] >= 0){
                if(vis[j - arr[i]]){
                    vis[j] = true;
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i < 100001; i++){
        if(vis[i]){
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(int i = 1; i < 100001; i++){
        if(vis[i]){
            cout << i << ' ';
        }
    }
    return 0;
}