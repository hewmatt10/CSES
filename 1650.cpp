#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n, q;
int arr[MN];
int blocks[MN];
int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        blocks[i/450] ^= arr[i];
    }
    for(int _ = 0; _ < q; _++){
        int a, b; cin >> a >> b;
        --a; --b;
        int l = a/450, r = b/450;
        if(l >= r){
            int x = 0;
            for(int i = a; i <= b; i++){
                x ^= arr[i];
            }
            cout << x << "\n";
        }
        else{
            int x = 0;
            for(int i = a; i/450 < l + 1; i++){
                x ^= arr[i];
            }
            for(int i = l + 1; i <= r - 1; i++){
                x ^= blocks[i];
            }
            for(int i = b; i/450 > r - 1; i--){
                x ^= arr[i];
            }
            cout << x << "\n";
        }
    }
    return 0;
}