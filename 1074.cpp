#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n;
int arr[MN];
long long f(int j){
    long long ret = 0;
    for(int i = 0;i<n;i++){
        ret += 1LL * abs(j - arr[i]);
    }
    return ret;
}
int main(){
    cin >> n;
    int l = INT_MAX;
    int r = INT_MIN;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        l = min(l,arr[i]);
        r = max(r,arr[i]);
    }
    while(l < r){
        int mid = l + (r-l)/2;
        long long t1 = f(mid);
        long long t2 = f(mid+1);
        if(t1 > t2){
            l = mid + 1;
        }
        else if(t1 < t2){
            r = mid;
        }
        else{
            cout << t1 << "\n";
            return 0;
        }
    }
    cout << f(l) << "\n";
    return 0;
}