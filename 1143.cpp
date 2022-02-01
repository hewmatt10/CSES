#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n, m;
int seg[3*MN], a[MN];

void build(int l = 1, int r = n, int id = 1){
    if(l == r){
        seg[id] = a[l];
    }
    else{
        int mid = (l + r) / 2;
        build(l, mid, 2 * id);
        build(mid + 1, r, 2 * id + 1);
        seg[id] = max(seg[2*id], seg[2*id+1]);
    }
}

void update(int v, int l = 1, int r = n, int id = 1){
    if(l == r){
        seg[id] -= v;
        cout << l << " ";
    }
    else{
        int mid = (l + r)/2;
        if(seg[2 * id] >= v){
            update(v, l, mid, 2 * id);
        }
        else{
            update(v, mid + 1, r, 2 * id + 1);
        }
        seg[id] = max(seg[2*id], seg[2*id+1]);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build();
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        if(seg[1] < x) cout << "0 ";
        else update(x);
    }
    return 0;
}