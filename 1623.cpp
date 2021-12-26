#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MN = 20;
int N;
int arr[MN];
set<int> f;
void recur(int i, int cursum){
    if(i == N){
        f.insert(cursum);
        return;
    }
    recur(i+1, cursum);
    recur(i+1, cursum+arr[i]);
}

signed main(){
    int tot = 0;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> arr[i];
        tot += arr[i];
    }
    recur(0,0);
    long long mn = LONG_LONG_MAX;
    for(int i : f){
        long long diff = abs(2 * i - tot);
        mn = min(mn, diff);
    }
    cout << mn << "\n";
    return 0;
}