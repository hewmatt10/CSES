#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
struct range{
    int l,r,id;
    bool operator < (const range &other) const{
        if(l == other.l){
            return r > other.r;
        }
        return l < other.l;
    }
};
int n;
range arr[MN];
int contained [MN];
int contains [MN];
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i].l >> arr[i].r;
        arr[i].id = i;
    }
    sort(arr,arr+n);
    int mx = 0;
    for(int i = 0;i<n;i++){
        if(arr[i].r <= mx){
            contained[arr[i].id]++;
        }
        mx = max(mx,arr[i].r);
    }
    int mn = INT_MAX;
    for(int i = n-1;i>=0;i--){
        if(arr[i].r >= mn){
            contains[arr[i].id]++;
        }
        mn = min(mn,arr[i].r);
    }
    for(int i = 0;i<n;i++)cout << contains[i] << " ";
    cout << "\n";
    for(int i = 0;i<n;i++)cout << contained[i] << " ";
    return 0;
}