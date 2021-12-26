#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n,m, cnt;
int x[MN];
int arr[MN];
void update(int a, int b){
    if(arr[x[a]-1] <= arr[x[a]] && b < arr[x[a]-1]) cnt++;
    if(arr[x[a]-1] > arr[x[a]] && b >= arr[x[a]-1]) cnt--;
    if(arr[x[a]+1] >= arr[x[a]] && b > arr[x[a]+1]) cnt++;
    if(arr[x[a]+1] < arr[x[a]] && b <= arr[x[a]+1]) cnt--;
    arr[x[a]] = b;

    if(arr[x[b]-1] <= arr[x[b]] && a < arr[x[b]-1]) cnt++;
    if(arr[x[b]-1] > arr[x[b]] && a >= arr[x[b]-1]) cnt--;
    if(arr[x[b]+1] >= arr[x[b]] && a > arr[x[b]+1]) cnt++;
    if(arr[x[b]+1] < arr[x[b]] && a <= arr[x[b]+1]) cnt--;
    arr[x[b]] = a;

    swap(x[a], x[b]);
}

int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> x[i];
        arr[x[i]] = i;
    }
    arr[n+1] = n+1;
    cnt = 0;
    for(int i = 1,pt;i<=n;i++){
        if(pt > arr[i])cnt++;
        pt = arr[i];
    }
    for(int i = 0,a,b;i<m;i++){
        cin >> a >> b;
        update(a,b);
        cout << cnt << "\n";
    }
    return 0;
}