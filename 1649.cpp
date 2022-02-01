#include<bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;

struct node{
    int l, r, m; 
} seg [3 * MM];

void push_up(int id){
    seg[id].m = min(seg[2*id].m, seg[2*id + 1].m);
}

void build(int l, int r, int id){
    seg[id].l = l;
    seg[id].r = r;
    if(l == r){
        return;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    build(l, mid, 2 * id);
    build(mid + 1, r, 2 * id + 1);
    push_up(id);
}

//pos is desired location
//id is cur pos in segtree
void update(int pos, int v, int id){
    if(seg[id].l == pos && seg[id].r == pos){
        seg[id].m = v;
        return;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    if(pos <= mid){
        update(pos,v,2*id);
    }
    else{
        update(pos,v,2*id+1);
    }
    push_up(id);
}

int query_min(int l, int r, int id){
    if(seg[id].l == l && seg[id].r == r){
        return seg[id].m;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    if(r <= mid){
        return query_min(l, r, 2 * id);
    }
    else if(l > mid){
        return query_min(l, r, 2 * id + 1);
    }
    else{
        return min(query_min(l, mid, 2 * id),query_min(mid + 1, r, 2 * id + 1));
    }
}

int main(){
    int n,q;
    cin >> n >> q;
    build(1,n,1);
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        update(i, a, 1);
    }
    for(int i = 1;i<=q;i++){
        int o, a, b; cin >> o >> a >> b;
        if(o == 1){
            update(a,b,1);
        }
        else{
            cout << query_min(a, b, 1) << "\n";
        }
    }
    return 0;
}