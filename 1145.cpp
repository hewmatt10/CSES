#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e6+6;
int N, dp [MN];
int main() {
    cin>>N;
    int sz = 0;
    for(int k = 0,M;k<N;k++){
        cin>>M;
        int i = 0, j = sz;
        while(i < j){
            int mid = (i+j)/2;
            if (dp[mid] < M)i = mid + 1;
            else j = mid;
        }
        dp[i] = M;
        if(i == sz)sz++;
    }
    cout<<sz<<"\n";
    return 0;
}