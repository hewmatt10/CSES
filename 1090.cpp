#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n,x;
int g[MN];
int main(){
    cin >> n >> x;
    for(int i = 0;i<n;i++){
        cin >> g[i];
    }
    sort(g,g+n);
    int cmp = 0;
    int i = 0, j = n-1;
    while(i < j){
        if(g[i] + g[j] > x){
            j--;
        }
        else{
            i++;
            j--;
            cmp++;
        }
    }
    cout << n - cmp << "\n";
    return 0;
}