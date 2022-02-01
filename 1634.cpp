#include<bits/stdc++.h>
using namespace std;
const int MN = 1e6+6;
int n, x;
int c [MN];
int cnt [MN];
bool vis[MN];
int main(){
    memset(cnt, 0x3f3f3f3f, sizeof(cnt));
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    cnt[0] = 0;
    vis[0] = 1;
    for(int i = 0; i <= x; i++){
        if(vis[i]){
            for(int j = 0; j < n; j++){
                if(i + c[j] <= x){
                    cnt[i + c[j]] = min(cnt[i + c[j]], cnt[i] + 1);
                    vis[i + c[j]] = true;
                }
            }
        }
    }
    if(vis[x]){
        cout << cnt[x] << "\n";
    }
    else {
        cout << -1 << "\n";
    }
    return 0;  
}